"""
Keil Assistant
Keil 调试助手
"""
from multiprocessing import freeze_support
freeze_support()
# import pyqtgraph.examples
# pyqtgraph.examples.run()

import sys, os, signal, time, argparse, logging
import numpy as np
from PyQt5 import QtCore, QtGui, QtWidgets

from ui.mainwindow_ui import Ui_KeilAssiatantMainWindow
from ui_dataViewer import DataViewerSubMainWindow


__version__ = "0.1.0"
debug = True

class KeilAssistantMainWindow(QtWidgets.QMainWindow, Ui_KeilAssiatantMainWindow):
    """main window"""
    def __init__(self, parent=None, logger=None):
        # Initialize UI
        super().__init__(parent)
        self.setupUi(self)

        self.logger = logger
        # Set window icon
        icon_path = os.path.join(os.path.dirname(os.path.realpath(__file__)), "resource/exeIcon.ico")
        self.setWindowIcon(QtGui.QIcon(icon_path)) 

        self.centerWidget = DataViewerSubMainWindow(parent=self, logger=self.logger)
        self.setCentralWidget(self.centerWidget) 

        self.statusBar().showMessage("Copyright (C) 2020 790614015@qq.com. All rights reserved.")


def main():
    global debug

    # Parse command line arguments
    parser = argparse.ArgumentParser(
        prog="KeilAssistant",
        description="Debug tool for embedded software development with Keil IDE",
    )
    parser.add_argument("--debug", action="store_true",
                        help="detailed debugging messages")
    parser.add_argument("--version", action="version",
                        version="%(prog)s {}".format(__version__))
    args, unparsed_args = parser.parse_known_args()
    debug = args.debug

    logger = logging.getLogger(__name__)
    # logger.setLevel(logging.INFO)
    logger.setLevel(logging.DEBUG)
    handler = logging.StreamHandler(sys.stdout)
    formatter_log = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')
    handler.setFormatter(formatter_log)
    logger.addHandler(handler)

    # Start PyQt application
    app = QtWidgets.QApplication(sys.argv[:1] + unparsed_args)
    app.setOrganizationName("JWang")
    app.setOrganizationDomain("qspectrumanalyzer.eutopia.cz")
    app.setApplicationName("KeilAssistant")
    window = KeilAssistantMainWindow(logger=logger)
    with open('resource/qss/gray.css', 'r') as f:
        window.setStyleSheet(f.read())
    window.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
