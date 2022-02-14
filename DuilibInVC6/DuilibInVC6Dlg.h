// DuilibInVC6Dlg.h : header file
//

#if !defined(AFX_DUILIBINVC6DLG_H__EEA9B25A_6EE2_47F5_BDF5_2D71FE330D4C__INCLUDED_)
#define AFX_DUILIBINVC6DLG_H__EEA9B25A_6EE2_47F5_BDF5_2D71FE330D4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Resource.h"
#include "MainDui.h"
/////////////////////////////////////////////////////////////////////////////
// CDuilibInVC6Dlg dialog

class CDuilibInVC6Dlg : public CDialog
{
// Construction
public:
	CDuilibInVC6Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDuilibInVC6Dlg)
	enum { IDD = IDD_DUILIBINVC6_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDuilibInVC6Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	CMainDui m_MainDui;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDuilibInVC6Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUILIBINVC6DLG_H__EEA9B25A_6EE2_47F5_BDF5_2D71FE330D4C__INCLUDED_)
