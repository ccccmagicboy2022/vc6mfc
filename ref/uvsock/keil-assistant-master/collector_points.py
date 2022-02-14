import time, threading, multiprocessing
from PyQt5 import QtCore
import numpy as np

from protocol.factory import protocol_factory

def worker(queue, cmd_send, parameter_dict, return_dict):
    typ_conn = parameter_dict['typ_conn']
    com = parameter_dict['com']
    host, port, logger = parameter_dict['host'], parameter_dict['port'], parameter_dict['logger']
    cmd_on = parameter_dict['cmd_on']
    cmd_off = parameter_dict['cmd_off']
    count = parameter_dict['count']
    
    dev = protocol_factory('tunkia', host=host, port=port, logger=logger) if typ_conn == 'TCP' else \
        protocol_factory('tunkia', serial_dev=com, logger=logger)
    last_time = time.time()
    for recv in dev.cmd_multi_point_recv(cmd_on, cmd_off, recv_counts=count):
        if parameter_dict['alive'] is False:
            break
        if recv:
            recv['timestamp'] = time.time()
            if recv['timestamp'] - last_time <= 0:
                recv['timestamp'] += 1E-6
            queue.put(recv)
        if cmd_send.empty() is False:
            cmd_str = cmd_send.get()
            dev.cmd(cmd_str)
    dev.cmd(cmd_off)
    dev.close()
    
class DevicePointsStream(QtCore.QThread):
    data_updated = QtCore.pyqtSignal(object)
    data_monitor = QtCore.pyqtSignal(int)

    def __init__(self, parent=None, logger=None):
        super().__init__(parent)
        self.logger = logger
        self.alive = False
        self.process = None

        self.package_counts = {}
        self.recv_num = 0

        manager = multiprocessing.Manager()
        self.parameter_dict = manager.dict()
        self.return_dict = manager.dict()
        self.data_trigger = multiprocessing.Queue(200)
        self.cmd_send = multiprocessing.Queue(10)

    def setup(self, typ_conn, com, host, port, size, cmd_str, logger=None):
        self.typ_conn, self.com, self.host, self.port, self.size, self.logger = typ_conn, com, host, port, size, logger
        self.cmd_str = cmd_str

    def cmd(self, c):
        dev = protocol_factory('tunkia', host=self.host, port=self.port, logger=self.logger)
        dev.cmd(c)
        del dev

    def collect_start(self, count=2**40):
        self.parameter_dict['typ_conn'] = self.typ_conn
        self.parameter_dict['com'] = self.com
        self.parameter_dict['host'] = self.host
        self.parameter_dict['port'] = self.port
        self.parameter_dict['logger'] = self.logger
        self.parameter_dict['cmd_on'] = 'PARW|{}=ON'.format(self.cmd_str)
        self.parameter_dict['cmd_off'] = 'PARW|{}=OFF'.format(self.cmd_str)
        self.parameter_dict['count'] = count
        self.parameter_dict['alive'] = True

        self.process = multiprocessing.Process(target=worker, args=(
            self.data_trigger, self.cmd_send, self.parameter_dict, self.return_dict))
        self.process.daemon = True
        self.process.start()

    def collect_stop(self):
        self.parameter_dict['alive'] = False
        time.sleep(0.5)
        t = threading.Timer(10, lambda _: self.process.terminate())
        if self.typ_conn == 'TCP':
            self.process.terminate()
        self.process.join()
        t.cancel()
        self.alive = False

    def transmmit_cmd(self, cmd, suffix='ON'):
        self.cmd_send.put(f"PARW|{cmd}={suffix}")

    def run(self):
        while True:
            data = self.data_trigger.get()
            self.recv_num += 1
            self.data_monitor.emit(self.recv_num)
            self.data_updated.emit(data)

if __name__ == "__main__":
    dev = DevicePointsStream()
    dev.setup('192.168.11.27', 8000, 100, logger=None)
    dev.collect_start()
    time.sleep(2)
    dev.collect_stop()