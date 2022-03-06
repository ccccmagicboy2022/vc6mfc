// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MainDui.h"

CMainDui::CMainDui()
{
	m_pParent = NULL;
}

CMainDui::~CMainDui()
{
}

LRESULT CMainDui::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam,
	BOOL& bHandled)
{
	CPaintManagerUI::SetInstance(AfxGetInstanceHandle());
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() +
		_T("skin"));

	m_pm.Init(m_hWnd);
	CDialogBuilder builder;
	CControlUI* pRoot = builder.Create("main.xml", NULL, NULL, &m_pm);
	ASSERT(pRoot && "Failed to parse XML");
	m_pm.AttachDialog(pRoot);
	m_pm.AddNotifier(this);

	m_btnMin = static_cast<CButtonUI*>(m_pm.FindControl(_T("btnMin")));
	m_btnClose = static_cast<CButtonUI*>(m_pm.FindControl(_T("btnClose")));

	return 0;
}

void CMainDui::Notify(TNotifyUI& msg)
{
	if (msg.sType == _T("click"))
	{
		if (msg.pSender == m_btnMin)
		{
			AfxMessageBox("最小化");
		}
		else if (msg.pSender == m_btnClose)
		{
			AfxMessageBox("关闭");
		}
	}
}

LRESULT CMainDui::OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam,
	BOOL& bHandled)
{
	LRESULT lRes = CWindowWnd::HandleMessage(uMsg, wParam, lParam);

	return lRes;
}

LRESULT CMainDui::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lRes = 0;
	BOOL bHandled = TRUE;
	switch (uMsg)
	{
	case WM_CREATE:
		lRes = OnCreate(uMsg, wParam, lParam, bHandled); break;
	case WM_SYSCOMMAND:
		lRes = OnSysCommand(uMsg, wParam, lParam, bHandled); break;
	default:
		bHandled = FALSE;
	}
	if (bHandled)
		return lRes;
	if (m_pm.MessageHandler(uMsg, wParam, lParam, lRes))
		return lRes;
	return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}

void CMainDui::SetParent(void* pParent)
{
	m_pParent = pParent;
}