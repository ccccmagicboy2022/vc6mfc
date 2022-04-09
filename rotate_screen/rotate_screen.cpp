// rotate_screen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "rotate_screen.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

/*
BOOL EnumDisplaySettings(
  LPCTSTR lpszDeviceName,  // display device
  DWORD iModeNum,          // graphics mode
  [In, Out] LPDEVMODE lpDevMode      // graphics mode settings
);
ENUM_CURRENT_SETTINGS = -1: Retrieves the current display mode.
ENUM_REGISTRY_SETTINGS = -2: Retrieves the current display mode stored in the Registry.
*/

CWinApp theApp;

using namespace std;

typedef  BOOL (CALLBACK * EnumDisplayDevices)(PVOID,DWORD,PVOID,DWORD);

void APP() 
{
	HINSTANCE  hInstUser32;
    DISPLAY_DEVICE DispDev;
	CString temp_str;
	DEVMODEA	dm;
	long result;
	DWORD temp = 0;
	CString sCmdline = AfxGetApp()->m_lpCmdLine;
	int n;
	DWORD lcd_index = 0;
	CString index_str;

	TRACE(sCmdline);
	n = sCmdline.ReverseFind(' ');

	if (n != -1)
	{
		index_str = sCmdline.Right(sCmdline.GetLength() - n - 1);
		index_str.MakeUpper();
		index_str.TrimLeft('\"');
		index_str.TrimRight('\"');
		TRACE(index_str);
		lcd_index = atoi(index_str);
	}

	hInstUser32 = LoadLibrary("USER32.dll");
    if (!hInstUser32) return; 
	//
	EnumDisplayDevices pEnumDisplayDevices = (EnumDisplayDevices)GetProcAddress(hInstUser32, "EnumDisplayDevicesA");

	if (pEnumDisplayDevices)
	{
		ZeroMemory(&DispDev, sizeof(DispDev));
		DispDev.cb = sizeof(DispDev);
		
		if (pEnumDisplayDevices(NULL, lcd_index, &DispDev, 0))
		{
			temp_str.Format("%s", DispDev.DeviceString);
			TRACE(temp_str);
			temp_str.Format("%s", DispDev.DeviceName);	//for setting use
			TRACE(temp_str);

			ZeroMemory(&dm, sizeof(dm));
			dm.dmSize = sizeof(dm);
			EnumDisplaySettingsA((LPSTR)(LPCTSTR)temp_str, ENUM_CURRENT_SETTINGS, &dm);

			temp_str.Format("%d", dm.dmDisplayOrientation);
			TRACE(temp_str);
			
			if (dm.dmDisplayOrientation < DMDO_270)
				dm.dmDisplayOrientation++;
			else
				dm.dmDisplayOrientation = DMDO_DEFAULT;

			temp = dm.dmPelsWidth;
			temp_str.Format("%d", temp);
			TRACE(temp_str);
			dm.dmPelsWidth = dm.dmPelsHeight;
			dm.dmPelsHeight = temp;

			temp_str.Format("%d", dm.dmDisplayOrientation);
			TRACE(temp_str);

			result = ChangeDisplaySettingsExA ((LPSTR)(LPCTSTR)DispDev.DeviceName, &dm, NULL, 0, NULL);

			if (result == DISP_CHANGE_SUCCESSFUL)
			{
				TRACE("bingo!!!");
			}
			else if (result == DISP_CHANGE_BADMODE)
			{
				TRACE("BADMODE!!!");
			}
			else
			{
				TRACE("BAD!!!");
			}
		} 
		else
		{
			//
		}

	}
	else
	{
        FreeLibrary(hInstUser32);
        return;	
	}

	FreeLibrary(hInstUser32);
	return;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.	
		APP();
	}

	return nRetCode;
}


