// DuilibInVC6.h : main header file for the DUILIBINVC6 application
//

#if !defined(AFX_DUILIBINVC6_H__F4A450E7_CC88_4554_ADA6_93AE8DEE7171__INCLUDED_)
#define AFX_DUILIBINVC6_H__F4A450E7_CC88_4554_ADA6_93AE8DEE7171__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDuilibInVC6App:
// See DuilibInVC6.cpp for the implementation of this class
//

class CDuilibInVC6App : public CWinApp
{
public:
	CDuilibInVC6App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDuilibInVC6App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDuilibInVC6App)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUILIBINVC6_H__F4A450E7_CC88_4554_ADA6_93AE8DEE7171__INCLUDED_)
