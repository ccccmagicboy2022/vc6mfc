// fmcw2mat.h : main header file for the fmcw2mat application
//

#if !defined(AFX_fmcw2mat_H__61121FF6_25BD_4873_A48A_67CD0F9FF2C1__INCLUDED_)
#define AFX_fmcw2mat_H__61121FF6_25BD_4873_A48A_67CD0F9FF2C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// Cfmcw2matApp:
// See fmcw2mat.cpp for the implementation of this class
//

class Cfmcw2matApp : public CWinApp
{
public:
	Cfmcw2matApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cfmcw2matApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(Cfmcw2matApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_fmcw2mat_H__61121FF6_25BD_4873_A48A_67CD0F9FF2C1__INCLUDED_)
