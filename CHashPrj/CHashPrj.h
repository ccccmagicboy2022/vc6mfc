// CHashPrj.h : main header file for the CHASHPRJ application
//

#if !defined(AFX_CHASHPRJ_H__F8603ED2_CE76_430B_BE8D_54911642E0DB__INCLUDED_)
#define AFX_CHASHPRJ_H__F8603ED2_CE76_430B_BE8D_54911642E0DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCHashPrjApp:
// See CHashPrj.cpp for the implementation of this class
//

class CCHashPrjApp : public CWinApp
{
public:
	CCHashPrjApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCHashPrjApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCHashPrjApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHASHPRJ_H__F8603ED2_CE76_430B_BE8D_54911642E0DB__INCLUDED_)
