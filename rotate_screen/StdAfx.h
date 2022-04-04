// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__7A7ED511_FA88_42C1_8238_AF0D6DCE6482__INCLUDED_)
#define AFX_STDAFX_H__7A7ED511_FA88_42C1_8238_AF0D6DCE6482__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afx.h>
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <iostream>

// TODO: reference additional headers your program requires here
//////////////////////////////////////////////////////////////////////////
///增强调试TRACE输出
#ifdef _DEBUG
#include "3rd_part\xtracestd\xtrace.h"
#include "3rd_part\xtracestd\xtracestd.h"
#endif
//no cmd console display
#include<typeinfo>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
/* DEVMODE dmDisplayOrientation specifiations */
#define DMDO_DEFAULT    0
#define DMDO_90         1
#define DMDO_180        2
#define DMDO_270        3
//fix old header
/*
typedef struct _devicemodeA {
    BYTE   dmDeviceName[CCHDEVICENAME];
    WORD dmSpecVersion;
    WORD dmDriverVersion;
    WORD dmSize;
    WORD dmDriverExtra;
    DWORD dmFields;
    union {
      struct {
        short dmOrientation;
        short dmPaperSize;
        short dmPaperLength;
        short dmPaperWidth;
        short dmScale;
        short dmCopies;
        short dmDefaultSource;
        short dmPrintQuality;
      };
      POINTL dmPosition;
		struct {
		  POINTL dmPosition;
		  DWORD  dmDisplayOrientation;
		  DWORD  dmDisplayFixedOutput;
		};
    };
    short dmColor;
    short dmDuplex;
    short dmYResolution;
    short dmTTOption;
    short dmCollate;
    BYTE   dmFormName[CCHFORMNAME];
    WORD   dmLogPixels;
    DWORD  dmBitsPerPel;
    DWORD  dmPelsWidth;
    DWORD  dmPelsHeight;
    DWORD  dmDisplayFlags;
    DWORD  dmDisplayFrequency;
#if(WINVER >= 0x0400)
    DWORD  dmICMMethod;
    DWORD  dmICMIntent;
    DWORD  dmMediaType;
    DWORD  dmDitherType;
    DWORD  dmReserved1;
    DWORD  dmReserved2;
#if (WINVER >= 0x0500) || (_WIN32_WINNT >= 0x0400)
    DWORD  dmPanningWidth;
    DWORD  dmPanningHeight;
#endif
#endif
} DEVMODEA, *PDEVMODEA, *NPDEVMODEA, *LPDEVMODEA;

*/
//////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__7A7ED511_FA88_42C1_8238_AF0D6DCE6482__INCLUDED_)
