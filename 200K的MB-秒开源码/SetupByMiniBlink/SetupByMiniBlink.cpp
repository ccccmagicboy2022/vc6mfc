// SetupByMiniBlink.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include <windowsx.h>
#include <Wininet.h>
#include <stdio.h>
#include "FastLzma2Portal.h"
#include "wke.h"
#include "SetupByMiniBlink.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


HWND HWnd=NULL;
wkeWebView WebView=NULL;
void WebViewOnPaintUpdateCallback(wkeWebView webView, void* param, const HDC hdc, int x, int y, int cx, int cy);
LRESULT CALLBACK WebViewWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
bool setCursorInfoTypeByCache(HWND hWnd);
BOOL Download(const char* xieyi, bool isHttps, const char* host, int port, const char* path, const char* outFileName);
bool IsFileExists(const char* name);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。
    if (!IsFileExists("node.dll")) {
        if (Download("http", false, "ssr.x4tools.com", 60080, "/node.dll.lzma2", "node.dll.lzma2") == FALSE) {
            MessageBox(NULL, L"下载node.dll失败", NULL, NULL);
            return FALSE;
        }
        DecompressFile("node.dll.lzma2", "node.dll");
        remove("node.dll.lzma2");
    }
    BOOL result = wkeInit();
    if (!result) {
        MessageBox(0, L"wkeInit执行失败",0,0);
        return FALSE;
    }
    WebView = wkeCreateWebView();
    if (WebView == NULL) {
        MessageBox(0, L"wkeCreateWebView执行失败", 0, 0);
        return FALSE;
    }

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SETUPBYMINIBLINK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SETUPBYMINIBLINK));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SETUPBYMINIBLINK));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SETUPBYMINIBLINK);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!HWnd)
   {
      return FALSE;
   }
   RECT rect = { 0 };
   GetClientRect(HWnd, &rect);
   int width = rect.right - rect.left, height = rect.bottom - rect.top;
   wkeOnPaintUpdated(WebView, WebViewOnPaintUpdateCallback, NULL);
   wkeLoadURL(WebView, "https://www.baidu.com");
   wkeResize(WebView, width, height);

   ShowWindow(HWnd, nCmdShow);
   UpdateWindow(HWnd);
   SetActiveWindow(HWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (WebViewWndProc(hWnd, message, wParam, lParam))
        return TRUE;
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }    
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
void WebViewOnPaintUpdateCallback(wkeWebView webView, void* param, const HDC hdc, int x, int y, int cx, int cy) {
    auto hdcTarget = GetDC(HWnd);
    BitBlt(hdcTarget, x, y, cx, cy, hdc, x, y, SRCCOPY);
    ReleaseDC(HWnd,hdcTarget);
}
LRESULT CALLBACK WebViewWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    BOOL handled = TRUE;
    switch (message) {
    case WM_SETCURSOR:
        handled = setCursorInfoTypeByCache(hWnd);
        break;
    case WM_SIZE:
        wkeResize(WebView, LOWORD(lParam), HIWORD(lParam));
        break;
    case WM_KEYDOWN:
    {
        unsigned int virtualKeyCode = wParam;
        unsigned int flags = 0;
        if (HIWORD(lParam) & KF_REPEAT)
            flags |= WKE_REPEAT;
        if (HIWORD(lParam) & KF_EXTENDED)
            flags |= WKE_EXTENDED;

        handled = wkeFireKeyDownEvent(WebView, virtualKeyCode, flags, false);
    }
    break;
    case WM_KEYUP:
    {
        unsigned int virtualKeyCode = wParam;
        unsigned int flags = 0;
        if (HIWORD(lParam) & KF_REPEAT)
            flags |= WKE_REPEAT;
        if (HIWORD(lParam) & KF_EXTENDED)
            flags |= WKE_EXTENDED;

        handled = wkeFireKeyUpEvent(WebView, virtualKeyCode, flags, false);
    }
    break;

    case WM_CHAR:
    {
        unsigned int charCode = wParam;
        unsigned int flags = 0;
        if (HIWORD(lParam) & KF_REPEAT)
            flags |= WKE_REPEAT;
        if (HIWORD(lParam) & KF_EXTENDED)
            flags |= WKE_EXTENDED;

        handled = wkeFireKeyPressEvent(WebView, charCode, flags, false);
    }
    break;

    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_LBUTTONDBLCLK: //
    case WM_MBUTTONDBLCLK:
    case WM_RBUTTONDBLCLK:
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MOUSEMOVE:
    {
        if (message == WM_LBUTTONDOWN || message == WM_MBUTTONDOWN || message == WM_RBUTTONDOWN) {
            SetFocus(hWnd);
            SetCapture(hWnd);
        }
        else if (message == WM_LBUTTONUP || message == WM_MBUTTONUP || message == WM_RBUTTONUP) {
            ReleaseCapture();
        }

        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);

        unsigned int flags = 0;

        if (wParam & MK_CONTROL)
            flags |= WKE_CONTROL;
        if (wParam & MK_SHIFT)
            flags |= WKE_SHIFT;

        if (wParam & MK_LBUTTON)
            flags |= WKE_LBUTTON;
        if (wParam & MK_MBUTTON)
            flags |= WKE_MBUTTON;
        if (wParam & MK_RBUTTON)
            flags |= WKE_RBUTTON;

        //flags = wParam;

        handled = wkeFireMouseEvent(WebView, message, x, y, flags);
    }
    break;

    case WM_CONTEXTMENU:
    {
        POINT pt;
        pt.x = GET_X_LPARAM(lParam);
        pt.y = GET_Y_LPARAM(lParam);

        if (pt.x != -1 && pt.y != -1)
            ScreenToClient(hWnd, &pt);

        unsigned int flags = 0;

        if (wParam & MK_CONTROL)
            flags |= WKE_CONTROL;
        if (wParam & MK_SHIFT)
            flags |= WKE_SHIFT;

        if (wParam & MK_LBUTTON)
            flags |= WKE_LBUTTON;
        if (wParam & MK_MBUTTON)
            flags |= WKE_MBUTTON;
        if (wParam & MK_RBUTTON)
            flags |= WKE_RBUTTON;

        handled = wkeFireContextMenuEvent(WebView, pt.x, pt.y, flags);
    }
    break;

    case WM_MOUSEWHEEL:
    {
        POINT pt;
        pt.x = GET_X_LPARAM(lParam);
        pt.y = GET_Y_LPARAM(lParam);
        ScreenToClient(hWnd, &pt);

        int delta = GET_WHEEL_DELTA_WPARAM(wParam);

        unsigned int flags = 0;

        if (wParam & MK_CONTROL)
            flags |= WKE_CONTROL;
        if (wParam & MK_SHIFT)
            flags |= WKE_SHIFT;

        if (wParam & MK_LBUTTON)
            flags |= WKE_LBUTTON;
        if (wParam & MK_MBUTTON)
            flags |= WKE_MBUTTON;
        if (wParam & MK_RBUTTON)
            flags |= WKE_RBUTTON;

        //flags = wParam;

        handled = wkeFireMouseWheelEvent(WebView, pt.x, pt.y, delta, flags);
    }
    break;

    case WM_SETFOCUS:
        wkeSetFocus(WebView);
        break;

    case WM_KILLFOCUS:
        wkeKillFocus(WebView);
        break;

    case WM_IME_STARTCOMPOSITION:
    {
        wkeRect caret = wkeGetCaretRect(WebView);

        CANDIDATEFORM form;
        form.dwIndex = 0;
        form.dwStyle = CFS_EXCLUDE;
        form.ptCurrentPos.x = caret.x;
        form.ptCurrentPos.y = caret.y + caret.h;
        form.rcArea.top = caret.y;
        form.rcArea.bottom = caret.y + caret.h;
        form.rcArea.left = caret.x;
        form.rcArea.right = caret.x + caret.w;

        HIMC hIMC = ImmGetContext(hWnd);
        ImmSetCandidateWindow(hIMC, &form);
        ImmReleaseContext(hWnd, hIMC);
    }
    break;

    default:
        handled = false;
        break;
    }
    return handled;
}
bool setCursorInfoTypeByCache(HWND hWnd)
{
    RECT rc;
    ::GetClientRect(hWnd, &rc);

    POINT pt;
    ::GetCursorPos(&pt);
    ::ScreenToClient(hWnd, &pt);
    if (!::PtInRect(&rc, pt))
        return false;

    HCURSOR hCur = NULL;
    switch (wkeGetCursorInfoType(WebView)) {
    case WkeCursorInfoPointer:
        hCur = ::LoadCursor(NULL, IDC_ARROW);
        break;
    case WkeCursorInfoIBeam:
        hCur = ::LoadCursor(NULL, IDC_IBEAM);
        break;
    case WkeCursorInfoHand:
        hCur = ::LoadCursor(NULL, IDC_HAND);
        break;
    case WkeCursorInfoWait:
        hCur = ::LoadCursor(NULL, IDC_WAIT);
        break;
    case WkeCursorInfoHelp:
        hCur = ::LoadCursor(NULL, IDC_HELP);
        break;
    case WkeCursorInfoEastResize:
        hCur = ::LoadCursor(NULL, IDC_SIZEWE);
        break;
    case WkeCursorInfoNorthResize:
        hCur = ::LoadCursor(NULL, IDC_SIZENS);
        break;
    case WkeCursorInfoSouthWestResize:
    case WkeCursorInfoNorthEastResize:
        hCur = ::LoadCursor(NULL, IDC_SIZENESW);
        break;
    case WkeCursorInfoSouthResize:
    case WkeCursorInfoNorthSouthResize:
        hCur = ::LoadCursor(NULL, IDC_SIZENS);
        break;
    case WkeCursorInfoNorthWestResize:
    case WkeCursorInfoSouthEastResize:
        hCur = ::LoadCursor(NULL, IDC_SIZENWSE);
        break;
    case WkeCursorInfoWestResize:
    case WkeCursorInfoEastWestResize:
        hCur = ::LoadCursor(NULL, IDC_SIZEWE);
        break;
    case WkeCursorInfoNorthEastSouthWestResize:
    case WkeCursorInfoNorthWestSouthEastResize:
        hCur = ::LoadCursor(NULL, IDC_SIZEALL);
        break;
    default:
        hCur = ::LoadCursor(NULL, IDC_ARROW);
        break;
    }

    if (hCur) {
        ::SetCursor(hCur);
        return true;
    }

    return false;
}
BOOL Download(const char* xieyi,bool isHttps, const char* host, int port, const char* path, const char* outFileName) {
    HINTERNET hInternet = InternetOpenA("MyAgent", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0); //初始化WinINet
    if (hInternet == NULL) {        
        return FALSE;
    }
    HINTERNET hConnect = InternetConnectA(hInternet, host, port,
        NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0); //连接服务器
    if (hConnect == NULL) {
        return FALSE;
    }
    HINTERNET hOpenRequest = HttpOpenRequestA(hConnect, "GET", path, HTTP_VERSIONA, NULL,
        NULL, isHttps ? INTERNET_FLAG_SECURE : 0, 1); //创建http请求
    BOOL bRequest = HttpSendRequestA(hOpenRequest, NULL, 0, NULL, 0); //发送http请求
    if (bRequest == FALSE) {
        return FALSE;
    }
    if (hOpenRequest == NULL) {
        return FALSE;
    }
    //InternetWriteFile(hOpenRequest, json.c_str(), json.size(), 0);
    auto fout = fopen(outFileName, "w+b");

    char rBuffer[1024] = { 0 };
    DWORD rb = 0;
    do {
        InternetReadFile(hOpenRequest, rBuffer, 1024, &rb);
        fwrite(rBuffer, 1, rb, fout);
    } while (rb != 0);

    HttpEndRequest(hOpenRequest, NULL, 0, 0);
    InternetCloseHandle(hOpenRequest);
    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);
    fclose(fout);
    return TRUE;
}
bool IsFileExists(const char* name) {
    return GetFileAttributesA(name) != INVALID_FILE_ATTRIBUTES;
}