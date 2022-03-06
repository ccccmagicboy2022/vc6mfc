// wxwork_mailDlg.h : header file
//

#if !defined(AFX_wxwork_mailDLG_H__CE3F9092_65BD_4D9B_9DEC_24F36A41D515__INCLUDED_)
#define AFX_wxwork_mailDLG_H__CE3F9092_65BD_4D9B_9DEC_24F36A41D515__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
CString GetModuleDir();
// Cwxwork_mailDlg dialog

class Cwxwork_mailDlg : public CDialog
{
	// Construction
public:
	Cwxwork_mailDlg(CWnd* pParent = NULL);	// standard constructor

	// Dialog Data
	//{{AFX_DATA(Cwxwork_mailDlg)
	enum { IDD = IDD_wxwork_mail_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cwxwork_mailDlg)
	public:
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(Cwxwork_mailDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnClose();
	afx_msg void OnCancel();
	afx_msg void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	void init_wxwork_mail();
	void controls_change_size();
public:
	wkeWebView window;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_wxwork_mailDLG_H__CE3F9092_65BD_4D9B_9DEC_24F36A41D515__INCLUDED_)
