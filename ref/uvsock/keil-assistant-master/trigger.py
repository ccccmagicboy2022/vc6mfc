import multiprocessing
from PyQt5 import QtCore
import numpy as np



def worker(event, parameter_dict, return_dict):
    host, port, logger = parameter_dict['host'], parameter_dict['port'], parameter_dict['logger']
    
    
class Trigger(QtCore.QThread):
    trigger_update = QtCore.pyqtSignal((object, bool))
    trigger_status_update = QtCore.pyqtSignal(str)

    def __init__(self, dtype='auto', parent=None):
        super().__init__(parent)

        self.dtype = dtype

        # manager = multiprocessing.Manager()
        # self.parameter_dict = manager.dict()
        # self.return_dict = manager.dict()
        # self.data_trigger = multiprocessing.Event()

    def setup_auto(self):
        self.dtype = 'auto'

    def setup_sigle_larger(self, channel, larger):
        self.dtype = 'larger'
        self.trigger_counts = 0
        self.channel = channel
        self.larger = larger
    
    def setup_sigle_less(self, channel, less):
        self.dtype = 'less'
        self.trigger_counts = 0
        self.channel = channel
        self.less = less
        
    def update_trigger(self, data):
        if self.dtype == 'auto':
            self.trigger_update.emit(data, False)
            self.trigger_status_update.emit('AUTO')
        elif self.dtype == 'larger':
            if self.trigger_counts == 0 and data['channel'] == self.channel and (data['data']>self.larger).any():
                self.trigger_counts += 1
                self.trigger_update.emit(data, True)
            if self.trigger_counts >= 1:
                self.trigger_status_update.emit('SINGLE, >, TRIGGERED')
            else:
                self.trigger_status_update.emit('SINGLE, >, WAIT')
                self.trigger_update.emit(data, False)
        elif self.dtype == 'less':
            if self.trigger_counts == 0 and data['channel'] == self.channel and (data['data']<self.less).any():
                self.trigger_counts += 1
                self.trigger_update.emit(data, True)
            if self.trigger_counts >= 1:
                self.trigger_status_update.emit('SINGLE, <, TRIGGERED')
            else:
                self.trigger_status_update.emit('SINGLE, <, WAIT')
                self.trigger_update.emit(data, False)