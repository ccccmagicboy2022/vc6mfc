#pragma once

#include "DuiLib/UIlib.h"
using namespace DuiLib;


#ifdef _DEBUG
# ifdef _UNICODE//引用类库lib文件
# pragma comment(lib, "DuiLib/DuiLib_ud.lib")
# else
# pragma comment(lib, "DuiLib/DuiLib_d.lib")
# endif

#else
# ifdef _UNICODE
# pragma comment(lib, "DuiLib/DuiLib_u.lib")
# else
# pragma comment(lib, "DuiLib/DuiLib.lib")
# endif
#endif


class CMainDui:public CWindowWnd,INotifyUI
{
public:
	CMainDui();
	~CMainDui();

	LPCTSTR GetWindowClassName() const { return _T("登录窗口"); };
	UINT GetClassStyle() const { return CS_DBLCLKS; };
	void Notify(TNotifyUI& msg);
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
public:
	void SetParent(void * pParent);
public:
	CButtonUI* m_btnMin;
	CButtonUI* m_btnClose;
private:
	CPaintManagerUI m_pm;
	void * m_pParent;
};