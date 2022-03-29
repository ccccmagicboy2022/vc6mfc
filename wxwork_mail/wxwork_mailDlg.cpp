// wxwork_mailDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wxwork_mail.h"
#include "wxwork_mailDlg.h"

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
// Cwxwork_mailDlg dialog

Cwxwork_mailDlg::Cwxwork_mailDlg(CWnd* pParent /*=NULL*/) : CDialog(Cwxwork_mailDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cwxwork_mailDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	window = NULL;
}

void Cwxwork_mailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cwxwork_mailDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

}

BEGIN_MESSAGE_MAP(Cwxwork_mailDlg, CDialog)
	//{{AFX_MSG_MAP(Cwxwork_mailDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cwxwork_mailDlg message handlers

BOOL Cwxwork_mailDlg::OnInitDialog()
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
	init_wxwork_mail();
	controls_change_size();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cwxwork_mailDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a wxwork_mailmize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cwxwork_mailDlg::OnPaint()
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
//  the wxwork_mailmized window.
HCURSOR Cwxwork_mailDlg::OnQueryDragIcon()
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

jsValue JS_CALL js_Index2(jsExecState es)
{
	jsValue jv = jsEmptyObject(es);
	wkeUpdate();
	AfxMessageBox("bingo!");
	return jv;
}

jsValue JS_CALL js_msgBox(jsExecState	es)
{
	const	wchar_t* FuncIndex = jsToStringW(es, jsArg(es, 0));

	if (wcscmp(FuncIndex, L"1") == 0)
	{
		return	js_Index1(es);
	}
	else if (wcscmp(FuncIndex, L"2") == 0)
	{
		return	js_Index2(es);
	}
	return	jsStringW(es, L"0X00");
}

jsValue JS_CALL js_click(jsExecState	es)
{
	AfxMessageBox("bingo!!!");
	return	jsStringW(es, L"0X00");
}

jsValue JS_CALL js_click1(jsExecState	es)
{
	AfxMessageBox("bingo!!!111222333");
	return	jsStringW(es, L"0X00");
}

void Cwxwork_mailDlg::init_wxwork_mail()
{
	CString strFileName;
	//CString main_html_name;

	strFileName = GetModuleDir() + "\\node.dll";

	wkeSetWkeDllPath(strFileName.AllocSysString());

	wkeInitialize();

	//this->window = wkeCreateWebWindow(WKE_WINDOW_TYPE_POPUP,
	//						this->m_hWnd, 0, 0, 3000, 2000);
	this->window = wkeCreateWebWindow(WKE_WINDOW_TYPE_CONTROL, GetSafeHwnd(),
					0, 0, 1024, 768);
	//this->window = wkeCreateWebWindow(WKE_WINDOW_TYPE_TRANSPARENT, NULL, 0, 0, 1080, 680);
	wkeLoadURL(window, "https://work.weixin.qq.com/mail/");

	//main_html_name = GetModuleDir() + "\\www\\main.html";
	//wkeLoadFile(this->window, (LPSTR) (LPCTSTR) main_html_name);
	jsBindFunction("msgBox", js_msgBox, 1);
	jsBindFunction("click", js_click, 0);
	jsBindFunction("click1", js_click1, 0);

	wkeSetWindowTitleW(this->window, L"wxwork_mail_cccc");

	wkeEnableHighDPISupport();
	wkeSetZoomFactor(this->window, 2.0f);
	wkeSetDebugConfig(this->window, "antiAlias", "1");
	//wkeMoveToCenter(this->window);
	wkeSetDragEnable(this->window, true);
	wkeSetDragDropEnable(this->window, true);
	wkeSetCookieEnabled(this->window, true);
	wkeSetLocalStorageFullPath(this->window, L"c:\\temp");
	wkeSetTouchEnabled(this->window, true);
	wkeSetMemoryCacheEnable(this->window, true);
	wkeSetMouseEnabled(this->window, true);
	wkeSetHeadlessEnabled(this->window, false);
	//final show
	wkeShowWindow(this->window, TRUE);
	ShowWindow(SW_SHOWMAXIMIZED);
}

void Cwxwork_mailDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	if (nType == 1)
		return;//最小化则什么都不做
	controls_change_size();
}

void Cwxwork_mailDlg::controls_change_size()
{
	CRect rc;
	GetClientRect(rc);

	if (this->GetSafeHwnd())
	{
		if (window)
		{
			wkeResizeWindow(this->window, rc.Width(), rc.Height());
		}
	}
}

void Cwxwork_mailDlg::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI)
{
	CPoint pt(1024, 768);		//
	lpMMI-> ptMinTrackSize = pt;	//
	CDialog::OnGetMinMaxInfo(lpMMI);
}

void Cwxwork_mailDlg::OnCancel()
{
	OnClose();
}

void Cwxwork_mailDlg::OnOK()
{
	//
}

void Cwxwork_mailDlg::OnClose()
{
	DWORD result;
	result = MessageBox(_T("Are you sure? "), _T("exit"),
				MB_OKCANCEL | MB_SYSTEMMODAL | MB_ICONQUESTION | MB_DEFBUTTON2);

	switch (result)
	{
	case IDOK:
		//
		CDialog::OnClose();
		DestroyWindow();
		break;
	case IDCANCEL:
		//
		break;
	}
}

void Cwxwork_mailDlg::WinHelp(DWORD dwData, UINT nCmd)
{
	//
}
