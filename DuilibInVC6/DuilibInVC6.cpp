// DuilibInVC6.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DuilibInVC6.h"
#include "DuilibInVC6Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDuilibInVC6App

BEGIN_MESSAGE_MAP(CDuilibInVC6App, CWinApp)
	//{{AFX_MSG_MAP(CDuilibInVC6App)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDuilibInVC6App construction

CDuilibInVC6App::CDuilibInVC6App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDuilibInVC6App object

CDuilibInVC6App theApp;

/////////////////////////////////////////////////////////////////////////////
// CDuilibInVC6App initialization

BOOL CDuilibInVC6App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CDuilibInVC6Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
