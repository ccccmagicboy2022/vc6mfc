// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  	are changed infrequently
//

#if !defined(AFX_STDAFX_H__89EC98F5_D156_4CF8_991F_389EA8B56BCF__INCLUDED_)
#define AFX_STDAFX_H__89EC98F5_D156_4CF8_991F_389EA8B56BCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h> 		// MFC core and standard components
#include <afxext.h> 		// MFC extensions
#include <afxdisp.h>		// MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#ifndef ULONG_PTR
#define ULONG_PTR unsigned long*
#endif
#include <gdiplus.h>

//LNK4044
#pragma warning(disable: 4044)
//C4251
#pragma warning(disable: 4251)
//LNK4089
#pragma warning(disable: 4089)

//duilib
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

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__89EC98F5_D156_4CF8_991F_389EA8B56BCF__INCLUDED_)
