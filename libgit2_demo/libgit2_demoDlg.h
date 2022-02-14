// libgit2_demoDlg.h : header file
//

#if !defined(AFX_LIBGIT2_DEMODLG_H__4E9C4E51_3DC5_4991_B784_60A212CF8D88__INCLUDED_)
#define AFX_LIBGIT2_DEMODLG_H__4E9C4E51_3DC5_4991_B784_60A212CF8D88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLibgit2_demoDlg dialog

class CLibgit2_demoDlg : public CDialog
{
// Construction
public:
	CLibgit2_demoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLibgit2_demoDlg)
	enum { IDD = IDD_LIBGIT2_DEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibgit2_demoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLibgit2_demoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	/////////////////////////////////////////////////////////////////////////
private:
	void app();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBGIT2_DEMODLG_H__4E9C4E51_3DC5_4991_B784_60A212CF8D88__INCLUDED_)
