# -*- coding: utf-8 -*-
from __future__ import division
from __future__ import unicode_literals
from __future__ import print_function
from __future__ import absolute_import
from builtins import super
from builtins import hex
from future import standard_library
standard_library.install_aliases()
from qtpandas.compat import QtCore, QtGui, Qt, Slot, Signal

from qtpandas.models.DataFrameModel import DataFrameModel
from qtpandas.views.EditDialogs import AddAttributesDialog, RemoveAttributesDialog
from qtpandas.views.CustomDelegates import createDelegate
from qtpandas.models.mime import PandasCellPayload, MimeData
from qtpandas.models.SupportedDtypes import SupportedDtypes

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s


class DataTableWidget(QtGui.QWidget):
    """
    修改来自qtpandas的 DataTableWidget
    删除top的按钮，仅用于dataframe可视化
    """
    def __init__(self, parent=None, iconSize=QtCore.QSize(36, 36)):
        """Constructs the object with the given parent.

        Args:
            parent (QObject, optional): Causes the objected to be owned
                by `parent` instead of Qt. Defaults to `None`.
            iconSize (QSize, optional): Size of edit buttons. Defaults to QSize(36, 36).

        """
        super(DataTableWidget, self).__init__(parent)
        self._iconSize = iconSize
        self.initUi()


    def initUi(self):
        """Initalizes the Uuser Interface with all sub widgets.

        """
        self.gridLayout = QtGui.QGridLayout(self)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)

        self.tableView = QtGui.QTableView(self)
        self.tableView.setAlternatingRowColors(True)
        self.tableView.setSortingEnabled(True)
        
        self.gridLayout.addWidget(self.tableView, 1, 0, 1, 1)


    def setButtonsVisible(self, visible):
        """hide/show the edit buttons"""
        self.buttonFrame.setVisible(visible)
        

    def setViewModel(self, model):
        """Sets the model for the enclosed TableView in this widget.

        Args:
            model (DataFrameModel): The model to be displayed by
                the Table View.

        """
        if isinstance(model, DataFrameModel):
            
            selectionModel = self.tableView.selectionModel()
            self.tableView.setModel(model)
            model.dtypeChanged.connect(self.updateDelegate)
            model.dataChanged.connect(self.updateDelegates)
            del selectionModel
            
    def setModel(self, model):
        """Sets the model for the enclosed TableView in this widget.

        Args:
            model (DataFrameModel): The model to be displayed by
                the Table View.

        """
        self.setViewModel(model)

    def model(self):
        """Gets the viewModel"""
        return self.view().model()

    def viewModel(self):
        """Gets the viewModel"""
        return self.view().model()

    def view(self):
        """Gets the enclosed TableView

        Returns:
            QtGui.QTableView: A Qt TableView object.

        """
        return self.tableView

    def updateDelegate(self, column, dtype):
        """update the delegates for a specific column
        
        Args:
            column (int): column index.
            dtype (str): data type of column.
        
        """
        # as documented in the setDelegatesFromDtype function
        # we need to store all delegates, so going from
        # type A -> type B -> type A
        # would cause a segfault if not stored.
        createDelegate(dtype, column, self.tableView)

    def updateDelegates(self):
        """reset all delegates"""
        for index, column in enumerate(self.tableView.model().dataFrame().columns):
            dtype = self.tableView.model().dataFrame()[column].dtype
            self.updateDelegate(index, dtype)
            
    def selectionModel(self):
        """return the table views selectionModel"""
        return self.view().selectionModel()

    def setMetadataColumnsHidden(self, hiddenList=[], justHidden=False):
        '''隐藏列 '''
        for index, column in enumerate(self.tableView.model().dataFrame().columns):
            if column in hiddenList:
                self.tableView.setColumnHidden(index, 1)
            else:
                if justHidden is False:
                    self.tableView.setColumnHidden(index, 0)

    def enableEditing(self, enabled):
        '''Add CheckBox'''

        model = self.tableView.model()

        if model is not None:
            model.enableEditing(enabled)
            