// miniblink_demo.h : main header file for the miniblink_demo application
//

#if !defined(AFX_miniblink_demo_H__B46953BA_B86E_4FD8_8392_3698082F788A__INCLUDED_)
#define AFX_miniblink_demo_H__B46953BA_B86E_4FD8_8392_3698082F788A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// Cminiblink_demoApp:
// See miniblink_demo.cpp for the implementation of this class
//

class Cminiblink_demoApp : public CWinApp
{
public:
	Cminiblink_demoApp();

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cminiblink_demoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

	// Implementation

	//{{AFX_MSG(Cminiblink_demoApp)
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

#endif // !defined(AFX_miniblink_demo_H__B46953BA_B86E_4FD8_8392_3698082F788A__INCLUDED_)
