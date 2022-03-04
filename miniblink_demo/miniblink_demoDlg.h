// miniblink_demoDlg.h : header file
//

#if !defined(AFX_miniblink_demoDLG_H__CE3F9092_65BD_4D9B_9DEC_24F36A41D515__INCLUDED_)
#define AFX_miniblink_demoDLG_H__CE3F9092_65BD_4D9B_9DEC_24F36A41D515__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
CString GetModuleDir();
// Cminiblink_demoDlg dialog

class Cminiblink_demoDlg : public CDialog
{
	// Construction
public:
	Cminiblink_demoDlg(CWnd* pParent = NULL);	// standard constructor

	// Dialog Data
	//{{AFX_DATA(Cminiblink_demoDlg)
	enum { IDD = IDD_miniblink_demo_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cminiblink_demoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(Cminiblink_demoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	void init_miniblink_demo();
	void controls_change_size();
public:
	wkeWebView window;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_miniblink_demoDLG_H__CE3F9092_65BD_4D9B_9DEC_24F36A41D515__INCLUDED_)
