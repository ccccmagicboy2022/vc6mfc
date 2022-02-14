import os
import multiprocessing, threading
from PyQt5 import QtCore, QtWidgets
import datetime, time
import struct
import hdf5storage as hdf5
import h5py
# import scipy.io
import numpy as np
from utility.unit_converter import unit_split


def worker(file_format, data, filename, save_info, offset_filename, return_dict):
    channel_name = str(data['channel'])
    d = data['data']
    if file_format == 'bin':
        with open(filename, mode='ab+') as f:
            binary = struct.pack('{}f'.format(len(d)), *d.tolist())
            f.write(binary)
            return_dict['counts'] += len(binary)
    elif file_format == 'h5':
        with h5py.File(filename, 'a') as f:
            if 'data' not in f.keys():
                f.create_dataset('data', data=d, chunks=True, maxshape=(None,))
            else:
                f_data = f['data']
                l = f_data.shape[0]
                newshape = [l + d.shape[0]]
                f_data.resize(newshape)
                f_data[l:] = d
            return_dict['counts'] += d.shape[0]
    elif file_format == 'h5_all':
        with h5py.File(filename, 'a') as f:
            if channel_name not in f.keys():
                f.create_dataset(channel_name, data=d, chunks=True, maxshape=(None,))
            else:
                f_data = f[channel_name]
                l = f_data.shape[0]
                newshape = [l + d.shape[0]]
                f_data.resize(newshape)
                f_data[l:] = d
            return_dict['counts'] += d.shape[0]
    elif file_format == 'mat':
        if not os.path.exists(filename):
            hdf5.savemat(filename, {channel_name: d})
        else:
            f = hdf5.loadmat(filename)
            f[channel_name] = np.append(f[channel_name], d) if channel_name in f.keys() else d
            hdf5.savemat(filename, f)
        # mat_data = scipy.io.loadmat(filename) if os.path.exists(filename) else {}
        # if channel_name not in mat_data.keys():
        #     mat_data[channel_name] = d
        # else:
        #     f_data = mat_data[channel_name]
        #     l = f_data.shape[0]
        #     newshape = [l + d.shape[0]]
        #     mat_data[channel_name].resize(newshape)
        #     mat_data[channel_name][l:] = d
        # scipy.io.savemat(filename, mat_data)
        return_dict['counts'] += d.shape[0]
    return_dict['channel'] = data['channel']
    return_dict['offset'] = data['offset']
    if save_info is True:
        with open(offset_filename, mode='a+') as f:
            f.write("{}, {}\n".format(data['channel'], data['offset']))
    return return_dict

def worker_points_without_cache(name, data, filename, file_format, return_dict):
    if 'ENER' in data.keys():
        for key, val in data.items():
            if key not in ['ENER', 'timestamp']:
                v, u = unit_split(val.split(',')[0])
                if file_format == 'h5-all':
                    with h5py.File(filename, 'a') as f:
                        if name not in f.keys():
                            f.create_dataset(name, data=[v], chunks=True, maxshape=(None,))
                            f.create_dataset(f"{name}.time", data=[data['timestamp']], chunks=True, maxshape=(None,))
                        else:
                            f_data, f_data_time = f[name], f[f"{name}.time"]
                            l, l_time = f_data.shape[0], f_data_time.shape[0]
                            newshape, newshape_time = [l + 1], [l_time + 1]
                            f_data.resize(newshape)
                            f_data_time.resize(newshape_time)
                            f_data[l:], f_data_time[l:] = [v], [data['timestamp']]
                        return_dict['counts'] += 1
                elif file_format == 'h5':
                    with h5py.File(filename, 'a') as f:
                        if 'data' not in f.keys():
                            f.create_dataset('data', data=[v], chunks=True, maxshape=(None,))
                        else:
                            f_data = f['data']
                            l = f_data.shape[0]
                            newshape = [l + 1]
                            f_data.resize(newshape)
                            f_data[l:] = [v]
                        return_dict['counts'] += 1
                return_dict['isSave'] = 1
    else:
        return_dict['isSave'] = 0
    return return_dict

def worker_points(parameter_dict, start_time, data_queue, data_process, stop_flag, file_format, dir_path, single_time):
    file_time, pre_save_time = start_time, start_time
    return_dict = {'counts': 0, 'isSave':0}
    is_empty = True
    while is_empty:
        if parameter_dict['start_time'] - start_time > 0:
            file_time, pre_save_time = parameter_dict['start_time'], parameter_dict['start_time']
            return_dict = {'counts': 0, 'isSave':0}
        is_empty = stop_flag.empty()
        if is_empty:
            data = data_queue.get()

            if 'ENER' in data.keys():
                now = time.time()
                for key_raw, _ in data.items():
                    key = key_raw.split(".")[0]
                    if key not in ['ENER', 'timestamp']:
                        name = key
                        break

                if now - pre_save_time > single_time:
                    pre_save_time, file_time = now, now
                file_time_ = datetime.datetime.fromtimestamp(file_time)
                if file_format == 'h5':
                    filename = os.path.join(dir_path, "points{}_{}.{}".format(name, file_time_.strftime("%Y%m%d_%H%M%S"), file_format))
                else:
                    filename = os.path.join(dir_path, "points_{}.h5".format(file_time_.strftime("%Y%m%d_%H%M%S")))

                for key, val in data.items():
                    if key not in ['ENER', 'timestamp']:
                        v, u = unit_split(val.split(',')[0])
                        if file_format == 'h5-all':
                            with h5py.File(filename, 'a') as f:
                                if name not in f.keys():
                                    f.create_dataset(name, data=[v], chunks=True, maxshape=(None,))
                                    f.create_dataset(f"{name}.time", data=[data['timestamp']], chunks=True, maxshape=(None,), dtype="float")
                                else:
                                    f_data, f_data_time = f[name], f[f"{name}.time"]
                                    l, l_time = f_data.shape[0], f_data_time.shape[0]
                                    newshape, newshape_time = [l + 1], [l_time + 1]
                                    f_data.resize(newshape)
                                    f_data_time.resize(newshape_time)
                                    f_data[l:], f_data_time[l:] = [v], [data['timestamp']]
                                return_dict['counts'] += 1
                        elif file_format == 'h5':
                            with h5py.File(filename, 'a') as f:
                                if 'data' not in f.keys():
                                    f.create_dataset('data', data=[v], chunks=True, maxshape=(None,))
                                else:
                                    f_data = f['data']
                                    l = f_data.shape[0]
                                    newshape = [l + 1]
                                    f_data.resize(newshape)
                                    f_data[l:] = [v]
                                return_dict['counts'] += 1
                        return_dict['isSave'] = 1
            else:
                return_dict['isSave'] = 0
            data_process.put(return_dict)


class DataStorage(QtCore.QObject):
    """Data storage"""
    process_updated = QtCore.pyqtSignal((int, int))

    def __init__(self, widgetChannels, parent=None):
        super().__init__(parent)
        self.widgetChannels = widgetChannels

        manager = multiprocessing.Manager()
        self.return_dict = manager.dict()
        # self.pool = multiprocessing.Pool(1)
        self.pool = {}

        self.is_alive = False
        self.start_time = time.time()
        self.pre_save_time = self.start_time
        self.file_time = self.start_time

    def setup(self, total_time, single_time, dir_path, save_info, file_format):
        self.total_time = total_time
        self.single_time = single_time
        self.dir_path = dir_path if len(dir_path)>0 else os.path.dirname(__file__)
        self.save_info = save_info
        self.file_format = file_format.lower()

        self.return_dict['counts'] = 2**63

    def start(self):
        self.return_dict['counts'] = 0
        self.start_time = time.time()
        self.file_time, self.pre_save_time = self.start_time, self.start_time
        self.is_alive = True
    
    def stop(self):
        self.is_alive = False

    def save(self, data, force=False):
        if self.is_alive:
            name = str(data['channel'])
            cc = self.widgetChannels.findChild(QtWidgets.QCheckBox, name)
            if cc.isChecked():                         
                now = time.time()
                if now - self.pre_save_time > self.single_time:
                    self.pre_save_time, self.file_time = now, now
                file_time_ = datetime.datetime.fromtimestamp(self.file_time)
                if self.file_format == 'h5_all':
                    filename = os.path.join(self.dir_path, "wave_{}.{}".format(file_time_.strftime("%Y%m%d_%H%M%S"), 'h5'))
                    offset_filename = os.path.join(self.dir_path, "offset{}.txt".format(name))
                    if 'h5_all' not in self.pool.keys():
                        self.pool['h5_all'] = multiprocessing.Pool(1)
                    self.pool['h5_all'].apply_async(worker,
                                                args=(self.file_format, data, filename, self.save_info, offset_filename, self.return_dict),
                                                callback=self.pasrse_output) 
                elif self.file_format == 'mat':
                    filename = os.path.join(self.dir_path, "wave_{}.{}".format(file_time_.strftime("%Y%m%d_%H%M%S"), 'mat'))
                    offset_filename = os.path.join(self.dir_path, "offset{}.txt".format(name))
                    if 'mat' not in self.pool.keys():
                        self.pool['mat'] = multiprocessing.Pool(1)
                    self.pool['mat'].apply_async(worker,
                                                args=(self.file_format, data, filename, self.save_info, offset_filename, self.return_dict),
                                                callback=self.pasrse_output) 
                else:
                    filename = os.path.join(self.dir_path, "wave{}_{}.{}".format(name, file_time_.strftime("%Y%m%d_%H%M%S"), self.file_format))
                    offset_filename = os.path.join(self.dir_path, "offset{}.txt".format(name))
                    if name not in self.pool.keys():
                        self.pool[name] = multiprocessing.Pool(1)
                    self.pool[name].apply_async(worker,
                                                args=(self.file_format, data, filename, self.save_info, offset_filename, self.return_dict),
                                                callback=self.pasrse_output)
    
    def save_points(self, data, force=False):
        if self.is_alive:
            for key_raw, _ in data.items():
                key = key_raw.split(".")[0]
                if key not in ['ENER', 'timestamp']:
                    name = key
                    break
            cc = self.widgetChannels.findChild(QtWidgets.QCheckBox, name)
            if cc.isChecked():                         
                now = time.time()
                if now - self.pre_save_time > self.single_time:
                    self.pre_save_time, self.file_time = now, now
                file_time_ = datetime.datetime.fromtimestamp(self.file_time)
                if self.file_format == 'h5':
                    filename = os.path.join(self.dir_path, "points{}_{}.{}".format(name, file_time_.strftime("%Y%m%d_%H%M%S"), self.file_format))
                    pool_name = name
                else:
                    filename = os.path.join(self.dir_path, "points_{}.h5".format(file_time_.strftime("%Y%m%d_%H%M%S")))
                    pool_name = 'h5_all'
                if pool_name not in self.pool.keys():
                    self.pool[pool_name] = multiprocessing.Pool(1)
                self.pool[pool_name].apply_async(worker_points_without_cache,
                                            args=(name, data, filename, self.file_format, self.return_dict),
                                            callback=self.pasrse_points_output)
                
    def pasrse_output(self, res):
        now = time.time()
        total_bytes = res['counts']
        process = int((now - self.start_time) / self.total_time * 100)
        process = process if process < 100 else 100
        
        self.process_updated.emit(process, total_bytes)

    def pasrse_points_output(self, res):
        if res['isSave'] == 1:
            now = time.time()
            total_bytes = res['counts']
            process = int((now - self.start_time) / self.total_time * 100)
            process = process if process < 100 else 100
            self.process_updated.emit(process, total_bytes)


class DataPointsStorage(QtCore.QThread):
    """Data storage"""
    process_updated = QtCore.pyqtSignal((int, int))

    def __init__(self, widgetChannels, parent=None):
        super().__init__(parent)
        self.widgetChannels = widgetChannels

        self.process = None
        manager = multiprocessing.Manager()
        self.parameter_dict = manager.dict()
        self.data_queue = multiprocessing.Queue(1000)
        self.data_process = multiprocessing.Queue(1000)
        self.stop_flag = multiprocessing.Queue(2)

        self.is_alive = False
        self.start_time = time.time()
        self.pre_save_time = self.start_time
        self.file_time = self.start_time

    def setup(self, total_time, single_time, dir_path, save_info, file_format):
        self.total_time = total_time
        self.single_time = single_time
        self.dir_path = dir_path if len(dir_path)>0 else os.path.dirname(__file__)
        self.save_info = save_info
        self.file_format = file_format.lower()

    def start_save(self):
        self.start_time = time.time()
        self.file_time, self.pre_save_time = self.start_time, self.start_time
        self.parameter_dict['start_time'] = self.start_time
        # TODO: clear data_queue, data_process, stop_flag Queue

        if self.process is None:
            self.process = multiprocessing.Process(target=worker_points, args=(self.parameter_dict , self.start_time, \
                self.data_queue, self.data_process, self.stop_flag, self.file_format, self.dir_path, self.single_time))
            self.process.daemon = True
            self.process.start()

        self.is_alive = True
    
    def stop_save(self):
        # self.stop_flag.put(True)
        # self.process.terminate()
        # t = threading.Timer(5, lambda _: self.process.terminate())
        # self.process.join()
        # t.cancel()
        self.is_alive = False

    def save_points(self, data, force=False):
        if self.is_alive:
            for key_raw, _ in data.items():
                key = key_raw.split(".")[0]
                if key not in ['ENER', 'timestamp']:
                    name = key
                    break
            cc = self.widgetChannels.findChild(QtWidgets.QCheckBox, name)
            if cc.isChecked():                         
                self.data_queue.put(data)

    def run(self):
        while True:
            res = self.data_process.get()
            if res['isSave'] == 1:
                now = time.time()
                total_bytes = res['counts']
                process = int((now - self.start_time) / self.total_time * 100)
                process = process if process < 100 else 100
                self.process_updated.emit(process, total_bytes)