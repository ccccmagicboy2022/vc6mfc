import sys, os, signal, time, argparse
import numpy as np
from PyQt5 import QtCore, QtGui, QtWidgets
from qtpandas.models.DataFrameModel import DataFrameModel

from plot import WavePlotWidget, SpectrumPlotWidget
from ui.dataViewer_ui import Ui_FormDataViewer
from collector import DeviceStream
# from storage import DataStorage
# from trigger import Trigger
# from stream_exception import StreamException
from apfft import SpectromAnalyzer


class DataViewerSubMainWindow(QtWidgets.QWidget, Ui_FormDataViewer):
    """sub window"""
    def __init__(self, parent=None, logger=None):
        # Initialize UI
        super().__init__(parent)
        self.setupUi(self)
        self.logger = logger

        self.uv_client = None
        self.formLayoutChannel = QtWidgets.QGridLayout(self.widgetChannels)

        self.spectrumPlotWidget = SpectrumPlotWidget(self.spectrumPlotLayout, self.widgetChannels)
        self.wavePlotWidget = WavePlotWidget(self.wavePlotLayout, self.formLayoutChannel, self.spectrumPlotWidget, self.comboBoxHarmonicChannel)

        self.data_collector_thread = DeviceStream(logger=self.logger)
        self.spectrum_analyzer_thread = SpectromAnalyzer(self.comboBoxHarmonicChannel, logger=self.logger)
        
        self.load_settings()
        self.pushButtonStop.setEnabled(False)

        self.harmonic_round = self.spinBoxDecimals.value()
        self.curves_checkBox = []
        self.harmonicTable = DataFrameModel()
        self.widgetHarmonic.setViewModel(self.harmonicTable)
        self.widgetHarmonic.view().horizontalHeader().setSectionResizeMode(1)

        self.data_collector_thread.data_updated.connect(self.wavePlotWidget.update_plot)
        self.data_collector_thread.data_monitor.connect(self.data_recv_monitor)
        
        self.data_collector_thread.data_updated.connect(self.spectrum_analyzer_thread.feed)
        self.spectrum_analyzer_thread.spectrum_updated.connect(self.spectrumPlotWidget.update_plot)
        self.spectrum_analyzer_thread.harmonic_updated.connect(self.update_harmonic)

        self.listWidgetVarList.setContextMenuPolicy(QtCore.Qt.CustomContextMenu)
        self.listWidgetVarList.customContextMenuRequested.connect(self.generatelistWidgetMenu(self.listWidgetVarList))

        self.data_collector_thread.start()
        self.timeout = 5

    def __del__(self):
        self.save_settings()

    def load_settings(self):
        """Restore settings and window geometry"""
        settings = QtCore.QSettings('setup.ini', QtCore.QSettings.IniFormat)
        self.lineEditIP.setText(settings.value("dataViewer/lineEditIP", "127.0.0.1", str))
        self.lineEditPort.setText(settings.value("dataViewer/lineEditPort", 4823, str))
        self.lineEditVar.setText(settings.value("dataViewer/lineEditVar", '', str))
        self.doubleSpinBoxSize.setValue(settings.value("dataViewer/doubleSpinBoxSize", 4096, int))
        self.comboBoxVarType.setCurrentIndex(settings.value("dataViewer/comboBoxVarType", 0, int))
        self.comboBoxByteOrder.setCurrentIndex(settings.value("dataViewer/comboBoxByteOrder", 0, int))
        self.spinBoxSampleRate.setValue(settings.value("dataViewer/spinBoxSampleRate", 10000, int))
    
    def save_settings(self):
        """Save settings and window geometry"""
        settings = QtCore.QSettings('setup.ini', QtCore.QSettings.IniFormat)
        settings.setValue("dataViewer/lineEditIP", self.lineEditIP.text())
        settings.setValue("dataViewer/lineEditPort", self.lineEditPort.text())
        settings.setValue("dataViewer/lineEditVar", self.lineEditVar.text())
        settings.setValue("dataViewer/doubleSpinBoxSize", self.doubleSpinBoxSize.value())
        settings.setValue("dataViewer/comboBoxVarType", self.comboBoxVarType.currentIndex())
        settings.setValue("dataViewer/comboBoxByteOrder", self.comboBoxByteOrder.currentIndex())
        settings.setValue("dataViewer/spinBoxSampleRate", self.spinBoxSampleRate.value())
    
    def start(self, single_shot=False):
        """start collect data"""
        self.save_settings()
        self.harmonic_round = self.spinBoxDecimals.value()
        host, port = self.lineEditIP.text(), int(self.lineEditPort.text())
        auto_read = self.doubleSpinBoxSampleFreq.value()
        sample_rate = self.spinBoxSampleRate.value()
        self.timeout = 5 + auto_read
        exist_list = self.get_var_list()
        self.spectrum_analyzer_thread.setup(15)
        self.spectrum_analyzer_thread.set_sample_rate(sample_rate=sample_rate)
        self.data_collector_thread.setup(host, port , auto_read, exist_list)
        return self.data_collector_thread.collect_start()
    
    def stop(self):
        return self.data_collector_thread.collect_stop()

    # def update_process(self, process, total_bytes):
    #     if process>=100:
    #         self.on_pushButtonSaveStop_clicked()
    #     self.progressBarSave.setValue(process)
    #     self.labelTotalSize.setText(f'{total_bytes:,} Bytes')

    def update_harmonic(self, df_table_json):
        ch = self.comboBoxHarmonicChannel.currentText()
        if ch in df_table_json.keys():
            self.harmonicTable.setDataFrame(df_table_json[ch].round(self.harmonic_round))        

    # def update_trigger_status(self, status):
    #     self.labelTrigStatus.setText(status)
    
    def data_recv_monitor(self, recv_num):
        self.last_recv = time.time()

    def timer_func(self):
        if time.time() - self.last_recv >= self.timeout:
            self.on_pushButtonStop_clicked()
            QtWidgets.QMessageBox.warning(self, '警告', '接收数据超时.')

    @QtCore.pyqtSlot(int)
    def on_spinBoxDecimals_valueChanged(self, v):
        self.harmonic_round = v

    @QtCore.pyqtSlot(int)
    def on_spinBoxSampleRate_valueChanged(self, sample_rate):
        self.spectrum_analyzer_thread.set_sample_rate(sample_rate=sample_rate)
    
    @QtCore.pyqtSlot()
    def on_pushButtonStart_clicked(self):
        self.save_settings()
        if len(self.get_var_list().keys()) > 0:
            self.last_recv = time.time()
            self.timer = QtCore.QTimer()
            self.timer.timeout.connect(self.timer_func)
            self.timer.start(3000)  # ms

            self.start()
            self.pushButtonStart.setEnabled(False)
            self.pushButtonStop.setEnabled(True)
        else:
            QtWidgets.QMessageBox.warning(self, '警告', '请添加变量.')

    @QtCore.pyqtSlot()
    def on_pushButtonStop_clicked(self):
        self.timer.stop()
        self.stop()
        self.pushButtonStart.setEnabled(True)
        self.pushButtonStop.setEnabled(False)

    def generatelistWidgetMenu(self, listWidget):
        def listWidgetMenu(pos):
            menu = QtWidgets.QMenu()
            item1 = menu.addAction(u"删除")
            action = menu.exec_(listWidget.mapToGlobal(pos))
            if action == item1:
                item = listWidget.itemAt(pos)
                listWidget.removeItemWidget(listWidget.takeItem(listWidget.row(item)))
        return listWidgetMenu

    def add_var_item(self, var, var_typ, var_len, var_order):
        if len(var) > 0:
            widget = QtWidgets.QWidget()
            layout = QtWidgets.QHBoxLayout()
            key = QtWidgets.QLabel(f"{var}")
            key.setObjectName("var_name")
            layout.addWidget(key)

            check_typ = QtWidgets.QLabel(f"{var_typ}")
            check_typ.setObjectName("var_type")
            layout.addWidget(check_typ)

            var_len = QtWidgets.QLabel(f"{var_len}")
            var_len.setObjectName("var_len")
            layout.addWidget(var_len)

            var_order = QtWidgets.QLabel(f"{var_order}")
            var_order.setObjectName("var_order")
            layout.addWidget(var_order)

            widget.setLayout(layout)

            strech = [1, 1, 1, 1]
            for i in range(len(strech)):
                layout.setStretch(i, strech[i])

            item = QtWidgets.QListWidgetItem()
            item.setSizeHint(QtCore.QSize(200, 45))
            self.listWidgetVarList.addItem(item)
            self.listWidgetVarList.setItemWidget(item, widget)

    def get_var_list(self):
        row_counts = self.listWidgetVarList.count()
        exception_list = {}
        for i in range(row_counts):
            item = self.listWidgetVarList.item(i)
            widget = self.listWidgetVarList.itemWidget(item)

            var_name = widget.findChild(QtWidgets.QLabel, 'var_name').text()
            var_type = widget.findChild(QtWidgets.QLabel, 'var_type').text()
            var_len = int(widget.findChild(QtWidgets.QLabel, 'var_len').text())
            var_order = widget.findChild(QtWidgets.QLabel, 'var_order').text()

            exception_list[var_name] = {"var_type": var_type, "var_len": var_len, "var_order": var_order}

        return exception_list

    @QtCore.pyqtSlot()
    def on_toolButtonAdd_clicked(self):
        var, size = self.lineEditVar.text(), int(self.doubleSpinBoxSize.text())
        var_type, byte_order = self.comboBoxVarType.currentText(), self.comboBoxByteOrder.currentText()

        exist_list = self.get_var_list()
        if var not in exist_list.keys():
            self.add_var_item(var, var_type, size, byte_order)

        