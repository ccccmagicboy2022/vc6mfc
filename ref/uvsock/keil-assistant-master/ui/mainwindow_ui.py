# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.13.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_KeilAssiatantMainWindow(object):
    def setupUi(self, KeilAssiatantMainWindow):
        KeilAssiatantMainWindow.setObjectName("KeilAssiatantMainWindow")
        KeilAssiatantMainWindow.resize(986, 575)
        self.centralwidget = QtWidgets.QWidget(KeilAssiatantMainWindow)
        self.centralwidget.setObjectName("centralwidget")
        KeilAssiatantMainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(KeilAssiatantMainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 986, 23))
        self.menubar.setObjectName("menubar")
        KeilAssiatantMainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(KeilAssiatantMainWindow)
        self.statusbar.setObjectName("statusbar")
        KeilAssiatantMainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(KeilAssiatantMainWindow)
        QtCore.QMetaObject.connectSlotsByName(KeilAssiatantMainWindow)

    def retranslateUi(self, KeilAssiatantMainWindow):
        _translate = QtCore.QCoreApplication.translate
        KeilAssiatantMainWindow.setWindowTitle(_translate("KeilAssiatantMainWindow", "Keil Assiatant"))
