import os, json, collections, math, time

from PyQt5 import QtCore, QtWidgets
import pyqtgraph as pg
from pyqtgraph import ColorButton

# Basic PyQtGraph settings
pg.setConfigOptions(antialias=True)


class WavePlotWidget:
    """Wave spectrum plot"""
    colors = ['y', 'r', 'g', 'b', 'c', 'm', '#123456']

    def __init__(self, layout, formLayoutChannel, spectrumPlotWidget, \
        comboBoxHarmonicChannel):
        if not isinstance(layout, pg.GraphicsLayoutWidget):
            raise ValueError("layout must be instance of pyqtgraph.GraphicsLayoutWidget")

        self.layout = layout
        self.formLayoutChannel = formLayoutChannel
        self.spectrumPlotWidget = spectrumPlotWidget
        self.comboBoxHarmonicChannel = comboBoxHarmonicChannel

        self.formLayoutChannel.setColumnStretch(0,1)
        self.formLayoutChannel.setColumnStretch(1,2)
        self.formLayoutChannel.setColumnStretch(2,2)

        self.channel_colors, self.channel_units, self.curves_scale, self.channel_default_enable = {}, {}, {}, {}
        self.curves = {}
        self.curves_enable = {}

        self.left_pen, self.right_pen = 'y', 'g'
        self.last_refresh = {}
        self.create_plot()

        self.load_channel_color()

    def load_channel_color(self):
        try:
            channel_filename = os.path.join(os.path.dirname(os.path.realpath(__file__)), "channelName.json")
            with open(channel_filename) as f:
                conf = json.load(f)
                self.channel_colors = conf['color'] if 'color' in conf.keys() else {}
                self.channel_units = conf['units'] if 'units' in conf.keys() else {}
                self.channel_default_enable = conf['default_enable'] if 'default_enable' in conf.keys() else {}
        except:
            pass
            
    def create_plot(self):
        """Create main spectrum plot"""
        self.bandwidthLabel = self.layout.addLabel(row=0, col=0, justify="left")
        self.posLabel = self.layout.addLabel(row=0, col=1, justify="right")
        self.plot = self.layout.addPlot(row=1, col=0, colspan=2)
        self.plot.showGrid(x=True, y=True)
        self.plot.setLabel("left", "Y")
        self.plot.setLabel("bottom", "X", units="")
        self.plot.setLimits(xMin=0)
        self.plot.showButtons()

        # Create crosshair
        self.vLine = pg.InfiniteLine(angle=90, movable=False)
        self.vLine.setZValue(1000)
        self.hLine = pg.InfiniteLine(angle=0, movable=False)
        self.hLine.setZValue(1000)
        self.plot.addItem(self.vLine, ignoreBounds=True)
        self.plot.addItem(self.hLine, ignoreBounds=True)
        self.mouseProxy = pg.SignalProxy(self.plot.scene().sigMouseMoved,
                                         rateLimit=60, slot=self.mouse_moved)

    def create_curve(self, name):
        """Create curve"""
        cl = self.colors[len(self.curves.keys())%len(self.colors)] if name not in self.channel_colors.keys() else self.channel_colors[name]
        units = "" if name not in self.channel_units.keys() else self.channel_units[name]
        self.curves[name] = self.plot.plot(pen=cl, name=name, units=units)
        self.curves_enable[name] = self.channel_default_enable[name] if name in self.channel_default_enable.keys() else True
        self.curves_scale[name] = 1
        # 触发通道
        self.comboBoxHarmonicChannel.addItem(name)

        cc = QtWidgets.QCheckBox(name)
        cc.setObjectName(name)
        default_state = QtCore.Qt.Checked if self.curves_enable[name] else QtCore.Qt.Unchecked
        cc.setCheckState(default_state)
        cc.stateChanged.connect(lambda :self.state_changed(cc))
        cc.stateChanged.connect(lambda :self.spectrumPlotWidget.state_changed(cc))
        
        cb = ColorButton()
        cb.setObjectName(name)
        # sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        # sizePolicy.setHorizontalStretch(0)
        # sizePolicy.setVerticalStretch(0)
        # sizePolicy.setHeightForWidth(cb.sizePolicy().hasHeightForWidth())
        # cb.setMaximumSize(60,100)
        cb.setColor(cl)
        cb.sigColorChanged.connect(self.color_changed)
        cb.sigColorChanged.connect(self.spectrumPlotWidget.color_changed)

        scale = QtWidgets.QDoubleSpinBox()
        scale.setEnabled(False)
        scale.setObjectName(name)
        scale.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        scale.setDecimals(3)
        scale.setMinimum(-999999)
        scale.setMaximum(999999)
        scale.setProperty("value", 1)
        scale.setMaximumSize(60,100)
        scale.valueChanged.connect(lambda x: self.scale_value_changed(name, x))

        self.formLayoutChannel.addWidget(cc, len(self.curves.keys())-1, 0)
        self.formLayoutChannel.addWidget(cb, len(self.curves.keys())-1, 1)
        self.formLayoutChannel.addWidget(scale, len(self.curves.keys())-1, 2)

    def scale_value_changed(self, name, value):
        if name in self.curves_scale.keys():
            self.curves_scale[name] = value

    def state_changed(self, chechBox):
        name = chechBox.objectName()
        self.curves_enable[name] = chechBox.isChecked()
        self.curves[name].setVisible(self.curves_enable[name])

    def color_changed(self, colorButton):
        name = colorButton.objectName()
        cl = colorButton.color()

        self.set_colors(name, cl)

    def set_colors(self, name, cl):
        """Set colors of all curves"""
        if name in self.curves.keys():
            self.curves[name].setPen(cl)

    def update_plot(self, data, force=False):
        """Update curve"""
        channel_name = str(data['channel']) 
        if channel_name not in self.last_refresh.keys():
            self.last_refresh[channel_name] = 0
        now = time.time()
        if now - self.last_refresh[channel_name] >= 0.03 or force:
            self.bandwidthLabel.setText(
                "<span style='font-size: 12pt'>{:,} Bps</span>".format(
                    data['bandwidth']
                )
            )
            if channel_name not in self.curves.keys():
                self.create_curve(channel_name)
            if self.curves_enable[channel_name]:
                self.curves[channel_name].setData(data['data']*self.curves_scale[channel_name])
                self.last_refresh[channel_name] = now

    def mouse_moved(self, evt):
        """Update crosshair when mouse is moved"""
        pos = evt[0]
        if self.plot.sceneBoundingRect().contains(pos):
            mousePoint = self.plot.vb.mapSceneToView(pos)
            self.posLabel.setText(
                "<span style='font-size: 12pt'>X={:,.0f} , Y={:,.6f}</span>".format(
                    mousePoint.x(),
                    mousePoint.y()
                )
            )
            self.vLine.setPos(mousePoint.x())
            self.hLine.setPos(mousePoint.y())

    def clear_plot(self):
        """Clear main curve"""
        for k, curve in self.curves.items():
            curve.clear()

class SpectrumPlotWidget:
    """Waterfall plot"""
    colors = ['y', 'r', 'g', 'b', 'c', 'm', '#123456']

    def __init__(self, layout, widgetChannels, histogram_layout=None):
        if not isinstance(layout, pg.GraphicsLayoutWidget):
            raise ValueError("layout must be instance of pyqtgraph.GraphicsLayoutWidget")

        if histogram_layout and not isinstance(histogram_layout, pg.GraphicsLayoutWidget):
            raise ValueError("histogram_layout must be instance of pyqtgraph.GraphicsLayoutWidget")

        self.layout = layout
        self.widgetChannels = widgetChannels

        self.history_size = 100
        self.counter = 0
        self.curves = {}
        self.curves_enable = {}

        self.last_refresh = {}

        self.create_plot()

    def create_plot(self):
        """Create waterfall plot"""
        self.posLabel = self.layout.addLabel(row=0, col=0, justify="right")
        self.plot = self.layout.addPlot(row=1, col=0)
        self.plot.setLabel("bottom", "Frequency", units="Hz")
        self.plot.setLabel("left", "RMS", units="dB")
        # self.plot.setLogMode(y=True)
        self.plot.showGrid(x=True, y=True)
        # self.plot.setLimits(xMin=0)
        self.plot.showButtons()

        # Create crosshair
        self.vLine = pg.InfiniteLine(angle=90, movable=False)
        self.vLine.setZValue(1000)
        self.hLine = pg.InfiniteLine(angle=0, movable=False)
        self.hLine.setZValue(1000)
        self.plot.addItem(self.vLine, ignoreBounds=True)
        self.plot.addItem(self.hLine, ignoreBounds=True)
        self.mouseProxy = pg.SignalProxy(self.plot.scene().sigMouseMoved,
                                         rateLimit=60, slot=self.mouse_moved)

    def create_curve(self, name):
        """Create curve"""
        cb = self.widgetChannels.findChild(ColorButton, name)
        cl = cb.color() if cb else self.colors[len(self.curves.keys())%len(self.colors)]
        
        cc = self.widgetChannels.findChild(QtWidgets.QCheckBox, name)

        self.curves[name] = self.plot.plot(pen=cl, name=name)
        self.curves_enable[name] = cc.isChecked()

    def state_changed(self, chechBox):
        name = chechBox.objectName()
        self.curves_enable[name] = chechBox.isChecked()
        self.curves[name].setVisible(self.curves_enable[name])

    def color_changed(self, colorButton):
        name = colorButton.objectName()
        cl = colorButton.color()

        self.set_colors(name, cl)

    def set_colors(self, name, cl):
        """Set colors of all curves"""
        if name in self.curves.keys():
            self.curves[name].setPen(cl)

    def update_plot(self, data, force=False):
        """Update curve"""  
        channel_name = str(data['channel']) 
        if channel_name not in self.last_refresh.keys():
            self.last_refresh[channel_name] = 0
        now = time.time()
        if now - self.last_refresh[channel_name] >= 0.03 or force:
            if channel_name not in self.curves.keys():
                self.create_curve(channel_name)
            if self.curves_enable[channel_name]:
                self.curves[channel_name].setData(data['freq1'], data['xf1'])  # FFT
                # self.curves[channel_name].setData(data['freq2'], data['xf2'])  # APFFT
                self.last_refresh[channel_name] = now

    def clear_plot(self):
        """Clear main curve"""
        for k, curve in self.curves.items():
            curve.clear()

    def mouse_moved(self, evt):
        """Update crosshair when mouse is moved"""
        try:
            pos = evt[0]
            if self.plot.sceneBoundingRect().contains(pos):
                mousePoint = self.plot.vb.mapSceneToView(pos)
                self.posLabel.setText(
                    "<span style='font-size: 12pt'>Freq={:,.1f} Hz, RMS={:,.1f} dB ({:,.3f})</span>".format(
                        mousePoint.x(),
                        mousePoint.y(),
                        10**(mousePoint.y()/20)
                    )
                )
                self.vLine.setPos(mousePoint.x())
                self.hLine.setPos(mousePoint.y())
        except:
            pass
