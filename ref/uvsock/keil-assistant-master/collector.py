import os, json, time, threading, multiprocessing, struct
from PyQt5 import QtCore
import numpy as np

from UVSOCK.uv_client import UVClient


VAR_TYPE_MAP = {
    'u8': 'B',
    's8': 'c',
    'u16': 'H',
    's16': 'h',
    'u32': 'I',
    's32': 'i',
    'u64': 'Q',
    's64': 'q',
    'float': 'f',
    'double': 'd'
}

def worker(queue, parameter_dict, return_dict):
    # uv_client = parameter_dict['uv_client']
    host, port = parameter_dict['host'], parameter_dict['port']
    auto_read = parameter_dict['auto_read']
    var_list = parameter_dict['var_list']
    logger = parameter_dict['logger']
    return_dict_size = parameter_dict['return_dict_size']

    uv_client = UVClient(host, port, logger)
    uv_client.open()

    stat_num = 0
    for val_name, var_item in  var_list.items():
        try:
            stat, val_type, val_cacl, sstr = uv_client.calc_expression(val_name)
            var_list[val_name]["var_addr"] = val_cacl if stat == 0 else None
            stat_num = stat_num + 1 if stat == 0 else stat_num
        except Exception as e:
            var_list[val_name]["var_addr"] = None

    if stat_num > 0:
        return_dict['index'] = 0
        start_time, total_size,  bandwidth = time.time(), 0, 0
        
        for i in range(2**64 if auto_read > 0 else 1):
            if parameter_dict['alive'] is False:
                break
            wait_start = time.time()
            for var_name, var_item in  var_list.items():
                var_type, var_addr, size, byte_order= var_item['var_type'], var_item['var_addr'], var_item['var_len'], var_item['var_order']
                if var_addr is not None:
                    elem_size = struct.calcsize(VAR_TYPE_MAP[var_type])
                    formatter_str = '{}{}{}'.format("<" if byte_order == "Little endians" else ">", size//elem_size, VAR_TYPE_MAP[var_type])
                    status, nAddr, ErrAddr, nErr, r_data = uv_client.read_chunk_mem(var_addr, size)
                    if status == 0 and nErr == 0:
                        data = struct.unpack(formatter_str, r_data)
                        # l = len(r_data)
                        total_size += size
                        if time.time() - start_time > 1:
                            bandwidth = int(total_size / (time.time() - start_time))
                            start_time, total_size = time.time(), 0

                        return_dict['index'] = return_dict['index'] + 1 if return_dict['index'] < return_dict_size else 0
                        return_dict[return_dict['index']] = {
                            'channel': var_name,
                            'offset': i,
                            'bandwidth': bandwidth,
                            'downsample': 1,
                            'data': np.array(data)
                        }
                        queue.put(return_dict['index'])
            while time.time() - wait_start < auto_read:
                time.sleep((auto_read - (time.time() - wait_start))/2)

    uv_client.close()

class DeviceStream(QtCore.QThread):
    trigger_update = QtCore.pyqtSignal(object)
    data_updated = QtCore.pyqtSignal(object)
    data_monitor = QtCore.pyqtSignal(int)

    def __init__(self, parent=None, logger=None):
        super().__init__(parent)
        self.logger = logger
        self.alive = False
        self.process = None

        self.package_counts = {}
        self.return_dict_size = 40
        self.recv_num = 0

        manager = multiprocessing.Manager()
        self.parameter_dict = manager.dict()
        self.return_dict = manager.dict()
        self.return_dict['index'] = 0
        self.data_trigger = multiprocessing.Queue(self.return_dict_size-1)

    def setup(self, host, port , auto_read, exist_list):
        self.host, self.port  = host, port 
        self.auto_read, self.var_list = auto_read, exist_list

    def collect_start(self, count=2**40):
        self.parameter_dict['host'] = self.host
        self.parameter_dict['port'] = self.port
        self.parameter_dict['alive'] = True
        # self.parameter_dict['uv_client'] = self.uv_client
        self.parameter_dict['auto_read'] = self.auto_read
        self.parameter_dict['var_list'] = self.var_list
        self.parameter_dict['return_dict_size'] = self.return_dict_size
        self.parameter_dict['logger'] = self.logger

        self.process = multiprocessing.Process(target=worker, args=(
            self.data_trigger, self.parameter_dict, self.return_dict))
        self.process.daemon = True
        self.process.start()

    def collect_stop(self):
        self.parameter_dict['alive'] = False
        time.sleep(0.5)
        t = threading.Timer(10, lambda _: self.process.terminate())
        self.process.terminate()
        self.process.join()
        t.cancel()
        self.alive = False
        return True
        
    def run(self):
        while True:
            index = self.data_trigger.get()
            self.recv_num += 1
            self.data_monitor.emit(self.recv_num)
            
            data = self.return_dict[index]
            self.data_updated.emit(data)
    
    # def post_trigger(self, data, force):
    #     self.data_updated.emit(data, force)