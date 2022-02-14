// libgit2_demoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "libgit2_demo.h"
#include "libgit2_demoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLibgit2_demoDlg dialog

CLibgit2_demoDlg::CLibgit2_demoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLibgit2_demoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLibgit2_demoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLibgit2_demoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLibgit2_demoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLibgit2_demoDlg, CDialog)
	//{{AFX_MSG_MAP(CLibgit2_demoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLibgit2_demoDlg message handlers

BOOL CLibgit2_demoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	app();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLibgit2_demoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLibgit2_demoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLibgit2_demoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

int status_cb(const char *path, unsigned int status_flags, void *payload)
{
	CString temp_str;
	TRACE(path);
	temp_str.Format("status_cb: %d", status_flags);
	TRACE(temp_str);
	return 0;
}

CString GetModuleDir() 
{ 
	HMODULE module = GetModuleHandle(0); 
	char pFileName[MAX_PATH]; 
	GetModuleFileName(module, pFileName, MAX_PATH); 
	
	CString csFullPath(pFileName); 
	int nPos = csFullPath.ReverseFind( _T('\\') ); 
	if( nPos < 0 ) 
		return CString(""); 
	else 
		return csFullPath.Left( nPos ); 
}

void CLibgit2_demoDlg::app()
{
	CString path;
	git_repository *repo = NULL;
	CString temp_str;
	int error;

	git_libgit2_init();
	path = GetModuleDir() + "\\test_repo";
	
// init local repo
// 	error = git_repository_init(&repo, path, false);	//init not bare
// 	//
// 	if (error < 0)
// 	{
// 		const git_error *e = git_error_last();
// 		TRACE("Error %d/%d: %s\n", error, e->klass, e->message);
// 	}

	git_clone_options opt = GIT_CLONE_OPTIONS_INIT;
	git_checkout_options checkout_opts = GIT_CHECKOUT_OPTIONS_INIT;
	opt.bare = false;
	opt.local = GIT_CLONE_LOCAL;
	opt.checkout_branch = "master";
	opt.checkout_opts = checkout_opts;
	error = git_clone(&repo, "https://toscode.gitee.com/penjun71/u8g2_template_stm32f103c8t6.git", (LPSTR)(LPCTSTR)path, &opt);
	temp_str.Format("clone: %d", error);
	TRACE(temp_str);

	if (error < 0)
	{
		const git_error *e = git_error_last();
		TRACE("Error %d/%d: %s\n", error, e->klass, e->message);
	}

	error = git_status_foreach(repo, status_cb, NULL);
	temp_str.Format("status: %d", error);
	TRACE(temp_str);

	if (error < 0)
	{
		const git_error *e = git_error_last();
		TRACE("Error %d/%d: %s\n", error, e->klass, e->message);
	}

	git_repository_free(repo);
	git_libgit2_shutdown();
}


