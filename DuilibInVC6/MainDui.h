#pragma once

#include "DuiLib/UIlib.h"
using namespace DuiLib;

class CMainDui : public CWindowWnd, INotifyUI
{
public:
	CMainDui();
	~CMainDui();

	LPCTSTR GetWindowClassName() const
	{
		return _T("demo");
	};
	UINT GetClassStyle() const
	{
		return CS_DBLCLKS;
	};
	void Notify(TNotifyUI& msg);
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam,
		BOOL& bHandled);
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
public:
	void SetParent(void* pParent);
public:
	CButtonUI* m_btnMin;
	CButtonUI* m_btnClose;
private:
	CPaintManagerUI m_pm;
	void* m_pParent;
};