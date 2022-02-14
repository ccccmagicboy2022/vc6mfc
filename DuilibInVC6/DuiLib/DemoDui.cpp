// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DemoDui.h"
#include "../imgoLiveDlg.h"

CDemoDui::CDemoDui()
{
	m_pParent = NULL;
}

CDemoDui::~CDemoDui()
{
}

LRESULT CDemoDui::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	CPaintManagerUI::SetInstance(AfxGetInstanceHandle());
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin"));

	m_pm.Init(m_hWnd);
	CDialogBuilder builder;
	CControlUI* pRoot = builder.Create("main.xml", (UINT)0,  NULL, &m_pm);
	ASSERT(pRoot && "Failed to parse XML");
	m_pm.AttachDialog(pRoot);
	m_pm.AddNotifier(this);

	return 0;
}

void CDemoDui::Notify(TNotifyUI& msg)
{
	
}

LRESULT CDemoDui::OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	LRESULT lRes = CWindowWnd::HandleMessage(uMsg, wParam, lParam);

	return lRes;
}

LRESULT CDemoDui::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lRes = 0;
	BOOL bHandled = TRUE;
	switch( uMsg ) {
	case WM_CREATE:        lRes = OnCreate(uMsg, wParam, lParam, bHandled); break;
	case WM_SYSCOMMAND:    lRes = OnSysCommand(uMsg, wParam, lParam, bHandled); break;
	default:
		bHandled = FALSE;
	}
	if( bHandled ) return lRes;
	if( m_pm.MessageHandler(uMsg, wParam, lParam, lRes) ) return lRes;
	return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}

void CDemoDui::SetParent(void * pParent)
{
	m_pParent = pParent;
}