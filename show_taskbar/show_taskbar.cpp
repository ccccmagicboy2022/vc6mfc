// show_taskbar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "show_taskbar.h"

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

UINT nEventIds[] =
{
 305,        //DisplayStartupMenu
 401,        //DisplayRunDialog				//ok in win11
 402,        //DisplayLogoffDialog			//ok in win11
 403,        //ArrangeCascade				
 404,        //ArrangeTileHrz
 405,        //ArrangeTileVrt
 407,        //ShowDesktop					//ok in win11
 408,        //ShowDateTimeDialog			//ok in win11
 413,        //ShowTaskbarPrps				//ok in win11
 415,        //MinAll						//ok in win11
 416,        //MaxAll						//ok in win11
 419,        //ShowDesktop2					//ok in win11
 420,        //ShowTaskMngr					//ok in win11
 421,        //TaskBrCustomizeNtfy			//ok in win11
 424,        //LockTaskbar					
 503,        //HelpAndSuppCenter			//ok in win11
 505,        //ControlPanel					
 506,        //TurnOffCompDialog			//ok in win11
 510,        //PrintersAndFaxesDialog		
 41093,      //FindFilesDialog				
 41094       //FindComputers
}; 

void APP() 
{
	HWND hShellWnd = ::FindWindow(_T("Shell_TrayWnd"), NULL);

	//::PostMessage(hShellWnd, WM_COMMAND, MAKELONG(407, 0), NULL);
	SetForegroundWindow(hShellWnd);
	keybd_event(VK_LWIN, 0, KEYEVENTF_KEYUP, 0);

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


