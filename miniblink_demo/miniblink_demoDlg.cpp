// miniblink_demoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "miniblink_demo.h"
#include "miniblink_demoDlg.h"

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
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
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
// Cminiblink_demoDlg dialog

Cminiblink_demoDlg::Cminiblink_demoDlg(CWnd* pParent /*=NULL*/) : CDialog(Cminiblink_demoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cminiblink_demoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cminiblink_demoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cminiblink_demoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

}

BEGIN_MESSAGE_MAP(Cminiblink_demoDlg, CDialog)
	//{{AFX_MSG_MAP(Cminiblink_demoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cminiblink_demoDlg message handlers

BOOL Cminiblink_demoDlg::OnInitDialog()
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
	init_miniblink_demo();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cminiblink_demoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a miniblink_demomize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cminiblink_demoDlg::OnPaint()
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
//  the miniblink_demomized window.
HCURSOR Cminiblink_demoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

CString GetModuleDir()
{
	HMODULE module = GetModuleHandle(0); 
	char pFileName[MAX_PATH]; 
	GetModuleFileName(module, pFileName, MAX_PATH); 

	CString csFullPath(pFileName); 
	int nPos = csFullPath.ReverseFind(_T('\\')); 
	if (nPos < 0)
		return CString("");
	else
		return csFullPath.Left(nPos);
}

jsValue	JS_CALL js_Index1(jsExecState	es)
{
	const	wchar_t* Admin = jsToStringW(es, jsArg(es, 1));
	const	wchar_t* pin = jsToStringW(es, jsArg(es, 2));

	if (wcscmp(Admin, L"cccc") != 0 || wcscmp(pin, L"123") != 0)
	{
		jsValue jv = jsEmptyObject(es);
		jsValue jOv1 = jsInt(1);
		jsSet(es, jv, "Error", jOv1);
		return jv;
	}
	else
	{
		jsValue jv = jsEmptyObject(es);
		jsValue jOv1 = jsInt(0);
		jsSet(es, jv, "Error", jOv1);
		return jv;
	}
}

jsValue JS_CALL js_msgBox(jsExecState	es)
{
	const	wchar_t* FuncIndex = jsToStringW(es, jsArg(es, 0));

	if (wcscmp(FuncIndex, L"1") == 0)
	{
		return	js_Index1(es);
	}
	return	jsStringW(es, L"0X00");
}

void Cminiblink_demoDlg::init_miniblink_demo()
{
	CString strFileName;
	CString main_html_name;

	strFileName = GetModuleDir() + "\\node.dll";

	wkeSetWkeDllPath(strFileName.AllocSysString());

	wkeInitialize();

	wkeWebView window = wkeCreateWebWindow(WKE_WINDOW_TYPE_POPUP,
							this->m_hWnd, 0, 0, 1080, 680);
	//wkeWebView window = wkeCreateWebWindow(WKE_WINDOW_TYPE_TRANSPARENT, NULL, 0, 0, 1080, 680);

	//wkeLoadURL(window, "www.baidu.com");
	main_html_name = GetModuleDir() + "\\www\\main.html";
	wkeLoadFile(window, (LPSTR) (LPCTSTR) main_html_name);
	jsBindFunction("msgBox", js_msgBox, 1);

	wkeShowWindow(window, TRUE);
}
