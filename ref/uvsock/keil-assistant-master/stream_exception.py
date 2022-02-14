import multiprocessing
from PyQt5 import QtCore, QtWidgets
import numpy as np
import pandas as pd
from qtpandas.models.DataFrameModel import DataFrameModel


class StreamException(QtCore.QThread):
    trigger_auto_save = QtCore.pyqtSignal(bool)

    def __init__(self, widgetHarmonicDistribution, widgetPower, parent=None, logger=None):
        super().__init__(parent)
        self.logger = logger
        self.widgetHarmonicDistribution = widgetHarmonicDistribution
        self.widgetPower = widgetPower

        self.harmonic_distribution = {}
        self.harmonic_distributionTable = DataFrameModel()
        self.widgetHarmonicDistribution.setViewModel(self.harmonic_distributionTable)
        self.widgetHarmonicDistribution.view().horizontalHeader().setSectionResizeMode(1)

        self.power = {}
        self.powerTable = DataFrameModel()
        self.widgetPower.setViewModel(self.powerTable)
        self.widgetPower.view().horizontalHeader().setSectionResizeMode(1)

        self.running = False
        self.enable_harmonic, self.enable_power = False, False

        self.channel_map = {"UA": ("IA", "A"), "UB": ("IB", "B"), "UC": ("IC", "C")}

    def setup(self, har_type, power_type, hd_treashold, stable_power, power_treashol, enable_harmonic, enable_power):
        self.har_type, self.power_type = har_type.lower(), power_type.upper()
        self.hd_treashold, self.stable_power, self.power_treashol = hd_treashold, stable_power, power_treashol
        self.enable_harmonic, self.enable_power = enable_harmonic, enable_power
    
    def start(self):
        self.running = True
    
    def stop(self):
        self.running = False
        self.trigger_auto_save.emit(False)

    def update_spectrum(self, df_table_json):
        try:
            for key, df in df_table_json.items():
                if len(df['RMS']) > 3:
                    data = np.array(df['RMS'][1:])
                    odd_hd  = np.sum(data[2::2]**2) / (data[0]**2)
                    even_hd = np.sum(data[1::2]**2) / (data[0]**2)
                    thd = np.sum(data[1:]**2) / (data[0]**2)

                    self.harmonic_distribution[key] = {
                        'channel': key,
                        'odd_hd': np.sqrt(odd_hd)*100,
                        'even_hd': np.sqrt(even_hd)*100,
                        'thd': np.sqrt(thd)*100
                    }
            self.harmonic_distributionTable.setDataFrame(pd.DataFrame.from_dict(
                self.harmonic_distribution, orient='index').round(2))

            self.power = self.power_retrive(df_table_json)
            self.powerTable.setDataFrame(pd.DataFrame.from_dict(
                self.power, orient='index').round(2))

            if self.running is True:
                hit = self.trigger_handle(self.harmonic_distribution, self.power)
                self.trigger_auto_save.emit(hit)

        except Exception as e:
            self.logger.exception(e)
    
    def power_retrive(self, df_table_json):
        power = {}
        for key, item in self.channel_map.items():
            if key in df_table_json.keys() and item[0] in df_table_json.keys():
                s = df_table_json[key]['RMS'][1] * df_table_json[item[0]]['RMS'][1]
                p = s * np.cos( (df_table_json[key]['Phase'][1] - df_table_json[item[0]]['Phase'][1]) / 180 * np.pi )
                q = s * np.sin( (df_table_json[key]['Phase'][1] - df_table_json[item[0]]['Phase'][1]) / 180 * np.pi )
                power[item[1]] = {"channel":item[1], "P":p, "Q":q, "S":s}
        return power


    def trigger_handle(self, hd, power):
        hit = False
        if self.enable_harmonic is True:
            for _, item in hd.items():
                if item[self.har_type] > self.hd_treashold:
                    hit = True
        if hit is False and self.enable_power is True:
            for _, item in power.items():
                if abs((item[self.power_type] - self.stable_power)/self.stable_power*100) > self.power_treashol:
                    hit = True
        return hit