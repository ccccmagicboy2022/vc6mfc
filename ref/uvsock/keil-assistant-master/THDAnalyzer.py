import numpy as np
from PyQt5 import QtCore


class THDAnalyzer(QtCore.QThread):
    data_updated = QtCore.pyqtSignal(object)
    data_monitor = QtCore.pyqtSignal(int)

    def __init__(self, step, thd_threshold, data_length, plot, curves, curves_enable, doubleSpinBoxTHDCurrent, parent=None, logger=None):
        super().__init__(parent)
        self.logger = logger
        
        self.step = step
        self.thd_threshold = thd_threshold / 100
        self.max_length = data_length - 1
        self.plot = plot
        self.curves, self.curves_enable = curves, curves_enable
        self.doubleSpinBoxTHDCurrent = doubleSpinBoxTHDCurrent

        view_range = plot.viewRange()
        self.start_pos = int(view_range[0][0])
    
    def retrive_thd(self, data):
        data = data[1:] - data[:-1]
        xf = np.fft.fft(data)
        xfp = np.abs(xf[:len(data)//2])
        xfp[0] = 0
        xfp = xfp ** 2
        base = np.argmax(xfp)

        thd = np.sum(xfp[base+base::base]) / xfp[base] if base*2 < len(xfp) else 0
        return thd


    def run(self):
        hit= True
        while hit:
            if self.start_pos + self.step <= self.max_length:
                self.plot.setXRange(self.start_pos, self.start_pos + self.step, padding=0)
                for name in self.curves.keys():
                    if self.curves_enable[name] is True:
                        _, y = self.curves[name].getData()
                        thd = self.retrive_thd(y)
                        self.doubleSpinBoxTHDCurrent.setValue(thd*100)
                        if thd > self.thd_threshold:
                            hit = False
                            break

                self.start_pos += self.step
            else:
                hit = False