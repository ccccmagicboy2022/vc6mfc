// CHashPrjDlg.h : header file
//

#if !defined(AFX_CHASHPRJDLG_H__23083951_6A28_4036_9375_DA1D92F37AB8__INCLUDED_)
#define AFX_CHASHPRJDLG_H__23083951_6A28_4036_9375_DA1D92F37AB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CHash.h"

/////////////////////////////////////////////////////////////////////////////
// CCHashPrjDlg dialog

class CCHashPrjDlg : public CDialog
{
// Construction
public:
	CCHashPrjDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCHashPrjDlg)
	enum { IDD = IDD_CHASHPRJ_DIALOG };
	CEdit	m_inFile;
	CEdit	m_outHash;
	CComboBox	m_hashAlgo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCHashPrjDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CHash hashObj;

	// Generated message map functions
	//{{AFX_MSG(CCHashPrjDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBrowseFile();
	afx_msg void OnDoHash();
	afx_msg void OnString();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHASHPRJDLG_H__23083951_6A28_4036_9375_DA1D92F37AB8__INCLUDED_)
