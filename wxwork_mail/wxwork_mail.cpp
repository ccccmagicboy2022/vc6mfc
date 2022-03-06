// wxwork_mail.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "wxwork_mail.h"
#include "wxwork_mailDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cwxwork_mailApp

BEGIN_MESSAGE_MAP(Cwxwork_mailApp, CWinApp)
	//{{AFX_MSG_MAP(Cwxwork_mailApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cwxwork_mailApp construction

Cwxwork_mailApp::Cwxwork_mailApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only Cwxwork_mailApp object

Cwxwork_mailApp theApp;

/////////////////////////////////////////////////////////////////////////////
// Cwxwork_mailApp initialization

BOOL Cwxwork_mailApp::InitInstance()
{
	AfxEnableControlContainer();

	init_skin();
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	Cwxwork_mailDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

extern CString GetModuleDir();

void Cwxwork_mailApp::init_skin()
{
	CString temp_str;
	temp_str = GetModuleDir() + "\\wxwork_mail.she";
	SkinH_Attach_Ex((LPSTR) (LPCTSTR) temp_str, NULL);
}

int Cwxwork_mailApp::ExitInstance()
{
	// TODO: Add your specialized code here and/or call the base class
	SkinH_Detach();

	return CWinApp::ExitInstance();
}
