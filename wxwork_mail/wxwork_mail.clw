; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Cwxwork_mailDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "wxwork_mail.h"

ClassCount=4
Class1=Cwxwork_mailApp
Class2=Cwxwork_mailDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_wxwork_mail_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_DIALOG_BLANK

[CLS:Cwxwork_mailApp]
Type=0
HeaderFile=wxwork_mail.h
ImplementationFile=wxwork_mail.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:Cwxwork_mailDlg]
Type=0
HeaderFile=wxwork_mailDlg.h
ImplementationFile=wxwork_mailDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=wxwork_mailDlg.h
ImplementationFile=wxwork_mailDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_wxwork_mail_DIALOG]
Type=1
Class=Cwxwork_mailDlg
ControlCount=0

[DLG:IDD_DIALOG_BLANK]
Type=1
Class=?
ControlCount=0

