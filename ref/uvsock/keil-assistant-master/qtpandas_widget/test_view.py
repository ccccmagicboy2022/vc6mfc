from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

import pandas as pd

from qtpandas.models.DataFrameModel import DataFrameModel
from view import DataTableWidget


class MainDialog(QDialog):

    def __init__(self, parent=None):

        super(MainDialog, self).__init__(parent)

        layout = QHBoxLayout()

        widget = DataTableWidget()
        self.model = DataFrameModel()
        widget.setViewModel(self.model)

        self.df = pd.DataFrame([[1,2,3],[2,3,4]], columns=['中文1', '中文2', '中文3'])
        self.model.setDataFrame(self.df)

        layout.addWidget(widget)
        self.setLayout(layout)

if __name__ == '__main__':

    import sys

    app = QApplication(sys.argv)
    ui = MainDialog()
    ui.show()

    sys.exit(app.exec_())