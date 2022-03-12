; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Cminiblink_demoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "miniblink_demo.h"

ClassCount=4
Class1=Cminiblink_demoApp
Class2=Cminiblink_demoDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_miniblink_demo_DIALOG
Resource4=IDD_DIALOG_BLANK

[CLS:Cminiblink_demoApp]
Type=0
HeaderFile=miniblink_demo.h
ImplementationFile=miniblink_demo.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:Cminiblink_demoDlg]
Type=0
HeaderFile=miniblink_demoDlg.h
ImplementationFile=miniblink_demoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=miniblink_demoDlg.h
ImplementationFile=miniblink_demoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_miniblink_demo_DIALOG]
Type=1
Class=Cminiblink_demoDlg
ControlCount=0

[DLG:IDD_DIALOG_BLANK]
Type=1
Class=?
ControlCount=0

