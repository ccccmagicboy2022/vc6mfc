// wxwork_mail.h : main header file for the wxwork_mail application
//

#if !defined(AFX_wxwork_mail_H__B46953BA_B86E_4FD8_8392_3698082F788A__INCLUDED_)
#define AFX_wxwork_mail_H__B46953BA_B86E_4FD8_8392_3698082F788A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// Cwxwork_mailApp:
// See wxwork_mail.cpp for the implementation of this class
//

class Cwxwork_mailApp : public CWinApp
{
public:
	Cwxwork_mailApp();

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cwxwork_mailApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

	// Implementation

	//{{AFX_MSG(Cwxwork_mailApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	void init_skin();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_wxwork_mail_H__B46953BA_B86E_4FD8_8392_3698082F788A__INCLUDED_)
