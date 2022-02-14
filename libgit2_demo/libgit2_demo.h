// libgit2_demo.h : main header file for the LIBGIT2_DEMO application
//

#if !defined(AFX_LIBGIT2_DEMO_H__610647FA_DDDF_4052_A859_A5B5CBBDBB8F__INCLUDED_)
#define AFX_LIBGIT2_DEMO_H__610647FA_DDDF_4052_A859_A5B5CBBDBB8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLibgit2_demoApp:
// See libgit2_demo.cpp for the implementation of this class
//

class CLibgit2_demoApp : public CWinApp
{
public:
	CLibgit2_demoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibgit2_demoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLibgit2_demoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBGIT2_DEMO_H__610647FA_DDDF_4052_A859_A5B5CBBDBB8F__INCLUDED_)
