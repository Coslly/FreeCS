/*
2023/10/06 18:00
此头文件不受法律保护*
使用者可随意修改发布or更新
编译时如果出现错误(未修改情况下)请把高级保存选项调整为(Unicode - 1200)
在项目-》属性-》配置属性-》链接器-》系统,将堆栈保留大小弄大点,如50M(52428800)
#include "Head.h"
thread 自定义变量名 = thread(自定义函数名);
*/
#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <Mmsystem.h>
#include <thread>
#include <cstring>
#include <TlHelp32.h>
#include <time.h>
#include <ctime>
#include <cstdint>
#include <sstream>
#include <iomanip>
#include <cstdint>
#include <compare>
#include <string>
#include <string_view>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <tchar.h>
#include <vfw.h>
#include <vector>
#include <io.h>
#include <gdiplus.h>
#include <gdiplusgraphics.h>
#include <dwmapi.h>
#include <urlmon.h>
#include <sapi.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "MSIMG32.LIB")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "Dwmapi.lib")
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "sapi.lib")
#pragma comment(lib, "ole32.lib")
using namespace std;
namespace Window//窗口
{
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    template<class A>//防止同窗口冲突  不同的窗口改不同的类
    vector<int> Get_PixelColor(int X, int Y, HWND Window_HWND = 0) noexcept//采取屏幕颜色
    {//Window::Get_PixelColor<class Get_PixelColor>(100, 100)[0];
        static HDC DC = GetWindowDC(Window_HWND);
        COLORREF pixel = GetPixel(DC, X, Y);
        return { GetRValue(pixel), GetGValue(pixel), GetBValue(pixel) };//[0]red  [1]green  [2]blue
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    vector<int> Get_Resolution() noexcept//获取屏幕分辨率（像素）
    {//Window::Get_Resolution()[0];
        return { GetSystemMetrics(SM_CXSCREEN) ,GetSystemMetrics(SM_CYSCREEN) };//[0]==X [1]==Y
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Set_Resolution(int X, int Y) noexcept//模拟英伟达控制台更改像素 (只适用于系统已经创建的像素搭配!)
    {//Window::Set_Resolution(1440,1080);
        if (X != GetSystemMetrics(SM_CXSCREEN) || Y != GetSystemMetrics(SM_CYSCREEN))//设立条件防止放入循环崩溃
        {
            DEVMODE DevMode = {};
            EnumDisplaySettings(NULL, 0, &DevMode);
            DevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
            DevMode.dmPelsWidth = X;
            DevMode.dmPelsHeight = Y;
            DevMode.dmDisplayFrequency = 30;
            DevMode.dmBitsPerPel = 32;
            ChangeDisplaySettings(&DevMode, 0);
        }
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    vector<int> Get_WindowResolution(HWND WindowHwnd) noexcept//获取窗口分辨率（窗口模式不精准，全屏精准）
    {//Window::Get_WindowResolution(FindWindow(NULL, L"WindowName"))[0];
        RECT rect; GetWindowRect(WindowHwnd, &rect);
        return{ rect.right - rect.left ,rect.bottom - rect.top,  rect.left, rect.top };//[0]==X [1]==Y
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    int Get_Window_PID(string processName) noexcept//获取窗口PID   *如果快速循环使用占用高*
    {//Window::Get_Window_PID("explorer.exe");  //特定窗口名要任务管理器里面的
        uintptr_t processId = 0;
        PROCESSENTRY32 entrys = { };
        entrys.dwSize = sizeof(PROCESSENTRY32);
        const auto snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//问题
        while (Process32Next(snapShot, &entrys))
        {
            if (wcscmp(entrys.szExeFile, wstring(processName.begin(), processName.end()).c_str()) == 0)
            {
                processId = entrys.th32ProcessID;
                OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);//开通权限
                break;
            }
        }
        CloseHandle(snapShot);
        return processId;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    string Get_ForegroundWindowName() noexcept//获取您正在活动时的窗口标题
    {//Window::Get_ForegroundWindowName();
        char NM[MAX_PATH]; GetWindowTextA(GetForegroundWindow(), NM, MAX_PATH);//获取窗口标题
        return NM;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    BOOL Get_WindowEnable(HWND WindowHwnd) noexcept//获取您正在活动时的特定窗口标题是否为真
    {//Window::Get_WindowEnable(FindWindow(NULL, L"WindowName"));
        if (GetForegroundWindow() == WindowHwnd)return true; else return false;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    BOOL Get_WindowEnable_s(string processName) noexcept//获取您正在活动时的特定窗口标题是否为真(特定窗口名要任务管理器里面的)   *占用高*
    {//Window::Get_WindowEnable_s("explorer.exe");
        uintptr_t processId = 0;
        PROCESSENTRY32 entrys = { };
        entrys.dwSize = sizeof(PROCESSENTRY32);
        const auto snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//问题
        while (Process32Next(snapShot, &entrys))
        {
            if (wcscmp(entrys.szExeFile, wstring(processName.begin(), processName.end()).c_str()) == 0)
            {
                processId = entrys.th32ProcessID;
                OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);//开通权限
                break;
            }
        }
        CloseHandle(snapShot);
        DWORD ProcessID; GetWindowThreadProcessId(GetForegroundWindow(), &ProcessID);
        if (processId == ProcessID)return true;
        else return false;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Set_WindowName(HWND WindowHWND, string Title) noexcept//修改特定窗口标题 修改之后再次修改要修改修改后的标题
    {//Window::Set_WindowName(FindWindow(NULL, L"TestWindow"),"Test Window 1");
        SetWindowText(WindowHWND, wstring(Title.begin(), Title.end()).c_str());//修改窗口标题
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Mini_Window(HWND Window_HWND) noexcept//最小化指定窗口
    {//Window::Mini_Window(FindWindowA(NULL, "Test Windows"));
        ShowWindow(Window_HWND, SW_MINIMIZE);
    }
    void Show_Window(HWND Window_HWND) noexcept//显示指定窗口
    {//Window::Show_Window(FindWindowA(NULL, "Test Windows"));
        SetForegroundWindow(Window_HWND);
        ShowWindow(Window_HWND, true);
    }
    void Hide_Window(HWND Window_HWND) noexcept//隐藏指定窗口
    {//Window::Hide_Window(FindWindowA(NULL, "Test Windows"));
        ShowWindow(Window_HWND, false);
    }
    void Kill_Window(HWND Window_HWND) noexcept//关闭指定窗口
    {//Window::Kill_Window(FindWindowA(NULL, "Test Windows"));
        DWORD ProcessID; GetWindowThreadProcessId(Window_HWND, &ProcessID);
        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);
        TerminateProcess(hProcess, 0);
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    BOOL Message_Box(string Title, string Content, UINT MS = MB_OK) noexcept//弹出提示框(更方便选择返回值) 说明：https://blog.csdn.net/yuyan987/article/details/78558648
    {//Window::Message_Box("提示", "你的头上有点绿");
        const short XXK = MessageBoxW(0, wstring(Content.begin(), Content.end()).c_str(), wstring(Title.begin(), Title.end()).c_str(), MS);
        if (XXK == 1 || XXK == 4 || XXK == 6)return true;//当确认
        else if (XXK == 2 || XXK == 3 || XXK == 5 || XXK == 7)return false;//当否定
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Hide_ConsoleWindow() noexcept//隐藏原控制台窗口
    {//Window::Hide_ConsoleWindow();
        ShowWindow(GetConsoleWindow(), false);//隐藏
    }
    void Show_ConsoleWindow() noexcept//显示原控制台窗口
    {//Window::Show_ConsoleWindow();
        ShowWindow(GetConsoleWindow(), true);//显示
    }
    void Set_ConsoleWindowTitle(string title) noexcept//修改原控制台窗口标题
    {//Window::Set_ConsoleWindowTitle("ah");
        system(("title " + title).c_str());
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    LRESULT WINAPI Start_GDI_Window_Prosess(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) noexcept//辅助
    {
        switch (msg)
        {
        case WM_ERASEBKGND: return TRUE;
            break;
        case WM_PAINT: return TRUE;
            break;
        }
        return DefWindowProcW(hwnd, msg, wp, lp);  //定义回调函数的返回值
    }
    class Windows//更加方便的 窗口创建
    {
    private:
        HWND GUIWindowHwnd = NULL;//GUI Window HWND
        int BKX = 0;
        int BKY = 0;
    public:
        //----------------------------------------------------------------------------------------
        HWND Create_Window(int Size_X, int Size_Y, string WindowName, BOOL IfTop = 0) noexcept//创建窗口
        {
            static int 窗口类型 = (WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW);
            if (IfTop)窗口类型 = (WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW);
            else 窗口类型 = (WS_EX_LAYERED | WS_EX_TOOLWINDOW);
            WNDCLASS RenderWindowM;
            memset(&RenderWindowM, 0, sizeof(RenderWindowM));
            RenderWindowM.style = CS_HREDRAW | CS_VREDRAW;
            RenderWindowM.lpfnWndProc = Start_GDI_Window_Prosess;//关联消息处理函数,告诉操作系统，如果有事件发生调用这个函数
            RenderWindowM.cbClsExtra = 0;
            RenderWindowM.cbWndExtra = 0;
            RenderWindowM.hInstance = GetModuleHandle(NULL);//实例句柄
            RenderWindowM.hIcon = LoadIcon(NULL, IDI_SHIELD);//图标
            RenderWindowM.hCursor = LoadCursor(NULL, IDC_ARROW);//光标样式
            RenderWindowM.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);//画刷
            RenderWindowM.lpszMenuName = NULL;
            RenderWindowM.lpszClassName = wstring(WindowName.begin(), WindowName.end()).c_str();//窗口类的名称，操作系统根据类的名称做映射
            RegisterClass(&RenderWindowM);//将这个窗体注册（告诉）到操作系统
            const HWND hWnd = CreateWindowEx(//创建窗口
                窗口类型//窗口的扩展风格 不显示窗口图标
                , wstring(WindowName.begin(), WindowName.end()).c_str()//窗口类的名称，必须和上面的lpszClassName一致
                , wstring(WindowName.begin(), WindowName.end()).c_str()//窗口的标题
                , WS_POPUP//窗口的风格 透明WS_POPUP 正常WS_CAPTION
                , GetSystemMetrics(SM_CXSCREEN) / 2 - Size_X / 2 //屏幕位置
                , GetSystemMetrics(SM_CYSCREEN) / 2 - Size_Y / 2
                , Size_X//宽高
                , Size_Y
                , 0//父窗口
                , 0//系统菜单
                , GetModuleHandle(NULL)
                , 0//用户数据
            );
            if (hWnd)//更新显示
            {
                UpdateWindow(hWnd);
                ShowWindow(hWnd, SW_SHOW);
                SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), 255, LWA_ALPHA);
                GUIWindowHwnd = hWnd;
                BKX = Size_X;
                BKY = Size_Y;
            }
            return hWnd;
        }
        //----------------------------------------------------------------------------------------
        HWND Create_RenderBlock_Alpha(int Size_X, int Size_Y, string WindowName) noexcept//创建绘制画板(专门用于绘制的窗口 支持阿尔法 不支持颜色为0,0,0的图形绘制)
        {
            WNDCLASS RenderWindowM;
            memset(&RenderWindowM, 0, sizeof(RenderWindowM));
            RenderWindowM.style = CS_HREDRAW | CS_VREDRAW;
            RenderWindowM.lpfnWndProc = Start_GDI_Window_Prosess;
            RenderWindowM.cbClsExtra = 0;
            RenderWindowM.cbWndExtra = 0;
            RenderWindowM.hInstance = GetModuleHandle(NULL);
            RenderWindowM.hIcon = LoadIcon(NULL, IDI_SHIELD);
            RenderWindowM.hCursor = LoadCursor(NULL, IDC_ARROW);
            RenderWindowM.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
            RenderWindowM.lpszMenuName = NULL;
            RenderWindowM.lpszClassName = wstring(WindowName.begin(), WindowName.end()).c_str();
            RegisterClass(&RenderWindowM);
            const HWND hWnd = CreateWindowEx((WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW), wstring(WindowName.begin(), WindowName.end()).c_str(), wstring(WindowName.begin(), WindowName.end()).c_str(), WS_POPUP, 0, 0, Size_X, Size_Y, HWND_DESKTOP, 0, GetModuleHandle(NULL), 0);
            if (hWnd)//更新显示
            {
                DWM_BLURBEHIND bb = { 0 };
                HRGN Hrgn = CreateRectRgn(0, 0, -1, -1);
                bb.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;
                bb.hRgnBlur = Hrgn;
                bb.fEnable = TRUE;
                DwmEnableBlurBehindWindow(hWnd, &bb);
                UpdateWindow(hWnd);
                ShowWindow(hWnd, SW_SHOW);
                SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
                GUIWindowHwnd = hWnd;
                BKX = Size_X;
                BKY = Size_Y;
            }
            return hWnd;
        }
        //----------------------------------------------------------------------------------------
        HWND Create_RenderBlock(int Size_X, int Size_Y, string WindowName) noexcept//创建绘制画板(专门用于绘制的窗口 不支持阿尔法 不支持颜色为0,0,0的图形绘制)
        {
            WNDCLASS RenderWindowM;
            memset(&RenderWindowM, 0, sizeof(RenderWindowM));
            RenderWindowM.style = CS_HREDRAW | CS_VREDRAW;
            RenderWindowM.lpfnWndProc = Start_GDI_Window_Prosess;
            RenderWindowM.cbClsExtra = 0;
            RenderWindowM.cbWndExtra = 0;
            RenderWindowM.hInstance = GetModuleHandle(NULL);
            RenderWindowM.hIcon = LoadIcon(NULL, IDI_SHIELD);
            RenderWindowM.hCursor = LoadCursor(NULL, IDC_ARROW);
            RenderWindowM.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
            RenderWindowM.lpszMenuName = NULL;
            RenderWindowM.lpszClassName = wstring(WindowName.begin(), WindowName.end()).c_str();
            RegisterClass(&RenderWindowM);
            HWND hWnd = CreateWindowEx((WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW), wstring(WindowName.begin(), WindowName.end()).c_str(), wstring(WindowName.begin(), WindowName.end()).c_str(), WS_POPUP, 0, 0, Size_X, Size_Y, HWND_DESKTOP, 0, GetModuleHandle(NULL), 0);
            if (hWnd)//更新显示
            {
                UpdateWindow(hWnd);
                ShowWindow(hWnd, SW_SHOW);
                SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
            }
            GUIWindowHwnd = hWnd;
            BKX = Size_X;
            BKY = Size_Y;
            return hWnd;
        }
        //----------------------------------------------------------------------------------------
        void UpdateRenderBlock() noexcept//DeleteColor(Put in the while() and Update < Render)
        {
            static HDC wind = GetWindowDC(GUIWindowHwnd);
            static HGDIOBJ huabi = SelectObject(wind, CreateSolidBrush(RGB(0, 0, 0)));
            BitBlt(wind, 0, 0, 99999, 99999, wind, 0, 0, PATCOPY);
        }
        //----------------------------------------------------------------------------------------
        HWND Get_HWND() noexcept { return GUIWindowHwnd; }//获取窗口HWND
        //----------------------------------------------------------------------------------------
        vector<int> Get_Window_Pos() noexcept//获取窗口坐标
        {
            RECT Windowrect;
            GetWindowRect(GUIWindowHwnd, &Windowrect);
            BKX = Windowrect.right - Windowrect.left;
            BKY = Windowrect.bottom - Windowrect.top;
            return { Windowrect.left ,Windowrect.top };
        }
        void Set_Window_Pos(int X, int Y) noexcept//移动窗口到指定坐标
        {
            RECT Windowrect;
            GetWindowRect(GUIWindowHwnd, &Windowrect);
            BKX = Windowrect.right - Windowrect.left;
            BKY = Windowrect.bottom - Windowrect.top;
            MoveWindow(GUIWindowHwnd, X, Y, Windowrect.right - Windowrect.left, Windowrect.bottom - Windowrect.top, TRUE);
        }
        //----------------------------------------------------------------------------------------
        vector<int> Get_Window_Size() noexcept//获取窗口大小
        {
            RECT Windowrect;
            GetWindowRect(GUIWindowHwnd, &Windowrect);
            BKX = Windowrect.right - Windowrect.left;
            BKY = Windowrect.bottom - Windowrect.top;
            return { Windowrect.right - Windowrect.left ,Windowrect.bottom - Windowrect.top };
        }
        void Set_Window_Size(int XX, int YY) noexcept//修改窗口大小
        {
            RECT Windowrect;
            GetWindowRect(GUIWindowHwnd, &Windowrect);
            BKX = Windowrect.right - Windowrect.left;
            BKY = Windowrect.bottom - Windowrect.top;
            MoveWindow(GUIWindowHwnd, Windowrect.left, Windowrect.top, XX, YY, TRUE);
        }
        //----------------------------------------------------------------------------------------
        void Set_WindowDeleteColor(vector<int>Color = { 0,0,0 }) noexcept//遍历删除特定颜色像素(不用放在循环内)
        {
            SetLayeredWindowAttributes(GUIWindowHwnd, RGB(Color[0], Color[1], Color[2]), 0, LWA_COLORKEY);
        }
        //----------------------------------------------------------------------------------------
        void Set_WindowAlpha(int Alpha = 255) noexcept//窗口整体阿尔法通道(不用放在循环内)
        {
            if (Alpha <= 0)Alpha = 0; else if (Alpha >= 255)Alpha = 255;//限制
            SetLayeredWindowAttributes(GUIWindowHwnd, RGB(0, 0, 0), Alpha, LWA_ALPHA);
        }
        //----------------------------------------------------------------------------------------
        void Show_Window() noexcept//强制显示窗口
        {
            SetForegroundWindow(GUIWindowHwnd);
            ShowWindow(GUIWindowHwnd, true);
        }
        void Hide_Window() noexcept//强制隐藏窗口
        {
            ShowWindow(GUIWindowHwnd, false);
        }
        //----------------------------------------------------------------------------------------
        BOOL Window_Move(int KD = 30) noexcept//移动窗口 KD = 宽度（放在循环）
        {
            static BOOL 防止脱离 = false;
            static int OldX;//按下时坐标X
            static int OldY;//按下时坐标Y
            POINT MousePos;
            GetCursorPos(&MousePos);
            RECT Windowrect;
            GetWindowRect(GUIWindowHwnd, &Windowrect);
            BKX = Windowrect.right - Windowrect.left;
            BKY = Windowrect.bottom - Windowrect.top;
            static BOOL 保存鼠标坐标 = false;
            if (GetForegroundWindow() == GUIWindowHwnd)//检测窗口是否在最前端
            {
                if ((MousePos.x - Windowrect.left >= 0 && MousePos.x - Windowrect.left <= BKX && MousePos.y - Windowrect.top >= 0 && MousePos.y - Windowrect.top <= KD) && GetAsyncKeyState(VK_LBUTTON) && !防止脱离)
                {
                    if (保存鼠标坐标)
                    {
                        OldX = (MousePos.x - Windowrect.left);
                        OldY = (MousePos.y - Windowrect.top);
                        保存鼠标坐标 = false;
                    }
                    MoveWindow(GUIWindowHwnd, MousePos.x - OldX, MousePos.y - OldY, Windowrect.right - Windowrect.left, Windowrect.bottom - Windowrect.top, TRUE);//移动窗口到鼠标坐标
                    防止脱离 = true;
                }
                else if (防止脱离 && GetAsyncKeyState(VK_LBUTTON))
                {
                    MoveWindow(GUIWindowHwnd, MousePos.x - OldX, MousePos.y - OldY, Windowrect.right - Windowrect.left, Windowrect.bottom - Windowrect.top, TRUE);//移动窗口到鼠标坐标
                    return true;
                }
                else {
                    防止脱离 = false;
                    保存鼠标坐标 = true;
                    return false;
                }
            }
            else return false;
        }
        //----------------------------------------------------------------------------------------
        void Fix_inWhile() noexcept//修复窗口转圈
        {
            MSG msg = { 0 };
            if (GetMessageW(&msg, 0, 0, 0))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        //----------------------------------------------------------------------------------------
    };
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    HWND Get_PIDtoHWND(DWORD dwProcessID) noexcept//通过pid获取窗口句柄
    {//Window::Get_PIDtoHWND(8102);
        HWND h = GetTopWindow(0);
        HWND retHwnd = NULL;
        while (h)
        {
            DWORD pid = 0;
            DWORD dwTheardId = GetWindowThreadProcessId(h, &pid);
            if (dwTheardId != 0 && pid == dwProcessID && GetParent(h) == NULL && IsWindowVisible(h))retHwnd = h;
            h = GetNextWindow(h, GW_HWNDNEXT);
        }
        return retHwnd;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    DWORD Get_WindowPID(HWND dwHWND) noexcept//通过窗口HWND句柄获取窗口PID
    {//Window::Get_WindowPID(FindWindow(NULL, NULL));
        DWORD ProcessIDReturnValue;//进程
        GetWindowThreadProcessId(dwHWND, &ProcessIDReturnValue);//获取进程id
        return ProcessIDReturnValue;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    class Render//双缓冲2D绘制类 （将绘制信息转移到图像内一并绘制）
    {
        /*
        int main()
        {
            Window::Windows Window_Var;//window class
            Window_Var.Create_Window(500, 500, "Test Windows");//Create
            Window::Render Render_DoubleBuffer_BL;//render class
            Render_DoubleBuffer_BL.CreatePaint(Window_Var.Get_HWND(), 0, 0, 500, 500);//Create
            while (1)
            {
                Render_DoubleBuffer_BL.Render_SolidRect(0, 0, 99999, 99999, { 255,255,255 });
                Render_DoubleBuffer_BL.Render_Line(0, 0, 300, 200, { 0,0,0 });
                Render_DoubleBuffer_BL.Render_SimpleString(5, 5, "Hello my bro! 123456789 ABCabc !@#$%^&*().", { 255,200,0 });
                Render_DoubleBuffer_BL.Render_SolidRect(100, 400, 100, 100, { 255,0,0 });
                Render_DoubleBuffer_BL.RenderA_GradientCircle(150, 150, 200, { 255,255,255,255 }, { 0,0,0,255 }, 0.5);
                Render_DoubleBuffer_BL.DrawPaint();
                Window_Var.Fix_inWhile();//**
                Sleep(1);
            }
        }
        */
    private:
        HDC HdcWind;
        HDC hMenDC;
        vector<int> StartPos;
        vector<int> EndPos;
        int Draw_FPS;
    public:
        //--------------------------------------------------------------------------------------------------------
        HDC CreatePaint(HWND WindowHWND, int X, int Y, int XX, int YY) noexcept//创建画布（在返回值内进行绘制 请勿放在循环*）
        {
            //-----------------------------------------------------------初始化GDI+
            Gdiplus::GdiplusStartupInput gdiplusstartupinput;
            ULONG_PTR gdiplusToken;
            Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusstartupinput, nullptr);
            //---------------------------------------------------------------------
            StartPos = { X,Y };
            EndPos = { XX,YY };
            HdcWind = GetWindowDC(WindowHWND);
            hMenDC = CreateCompatibleDC(HdcWind);
            SelectObject(hMenDC, (HBITMAP)CreateCompatibleBitmap(HdcWind, EndPos[0], EndPos[1]));
            return hMenDC;
        }
        HDC Get_HDC() noexcept { return hMenDC; }//获取绘制DC
        void DrawPaint() noexcept//绘制画布（如果单单绘制到屏幕NULL依然会闪烁但是不会出现上下图层闪烁*）
        {
            BitBlt(HdcWind, StartPos[0], StartPos[1], EndPos[0], EndPos[1], hMenDC, 0, 0, SRCCOPY);
            //--------------------------------帧数计算
            static int m_fps = 0; m_fps++;
            const int Tick = GetTickCount64(); static int Tick_Old = Tick;
            if (Tick >= Tick_Old + 1000)//每1秒刷新 (计时器)
            {
                Tick_Old = Tick;
                Draw_FPS = m_fps;
                m_fps = 0;
            }
            //----------------------------------------
        }
        int FPS() noexcept { return Draw_FPS; }//获取绘制帧数
        //--------------------------------------------------------------------------------------------------------以下为绘制函数
        void RenderA_Line(int X, int Y, int XX, int YY, vector<int>Color, int LineThickness = 1) noexcept//屏幕画线(包含Alpha)
        {
            Gdiplus::Graphics HDCwind(hMenDC);
            Gdiplus::Pen pen(Gdiplus::Color(Color[3], Color[0], Color[1], Color[2]), LineThickness);
            HDCwind.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);//抗锯齿 https://blog.csdn.net/hgy413/article/details/6692932
            HDCwind.DrawLine(&pen, X, Y, XX, YY);
        }
        //------------------------------------------------------------------------------------------------
        void RenderA_GradientLine(int X, int Y, int XX, int YY, vector<int>Color_1, vector<int>Color_2, int LineThickness = 1) noexcept//屏幕画渐变直线(包含Alpha)
        {
            Gdiplus::Graphics HDCwind(hMenDC);
            Gdiplus::LinearGradientBrush linGrBrush(Gdiplus::Point(X, Y), Gdiplus::Point(XX + 1, YY + 1), Gdiplus::Color(Color_1[3], Color_1[0], Color_1[1], Color_1[2]), Gdiplus::Color(Color_2[3], Color_2[0], Color_2[1], Color_2[2]));
            Gdiplus::Pen pen(&linGrBrush, LineThickness);
            HDCwind.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);//抗锯齿 https://blog.csdn.net/hgy413/article/details/6692932
            HDCwind.DrawLine(&pen, X, Y, XX, YY);
        }
        //------------------------------------------------------------------------------------------------
        void RenderA_SolidRect(int X, int Y, int XX, int YY, vector<int>Color) noexcept//绘制实心矩形(包含Alpha)
        {
            Gdiplus::Graphics HDCwind(hMenDC);
            Gdiplus::SolidBrush Pen(Gdiplus::Color(Color[3], Color[0], Color[1], Color[2]));
            HDCwind.FillRectangle(&Pen, X, Y, XX, YY);
        }
        //------------------------------------------------------------------------------------------------
        void RenderA_HollowRect(int X, int Y, int XX, int YY, vector<int>Color, int LineThickness = 1) noexcept//绘制空心矩形(包含Alpha)
        {
            Gdiplus::Graphics HDCwind(hMenDC);
            Gdiplus::Pen Pen(Gdiplus::Color(Color[3], Color[0], Color[1], Color[2]), LineThickness);
            HDCwind.DrawRectangle(&Pen, X, Y, XX, YY);
        }
        //------------------------------------------------------------------------------------------------
        void RenderA_GradientRect(int X, int Y, int XX, int YY, vector<int>Color_1, vector<int>Color_2, BOOL Style = 0) noexcept//绘制渐变色矩形(包含Alpha) 0横向渐变 1竖向渐变
        {
            Gdiplus::Graphics HDCwind(hMenDC);
            if (!Style)
            {
                Gdiplus::LinearGradientBrush Pen(Gdiplus::Point(X - 1, 0), Gdiplus::Point(X + XX + 1, 0), Gdiplus::Color(Color_1[3], Color_1[0], Color_1[1], Color_1[2]), Gdiplus::Color(Color_2[3], Color_2[0], Color_2[1], Color_2[2]));
                HDCwind.FillRectangle(&Pen, X, Y, XX, YY);
            }
            else {
                Gdiplus::LinearGradientBrush Pen(Gdiplus::Point(0, Y - 1), Gdiplus::Point(0, Y + YY + 1), Gdiplus::Color(Color_1[3], Color_1[0], Color_1[1], Color_1[2]), Gdiplus::Color(Color_2[3], Color_2[0], Color_2[1], Color_2[2]));
                HDCwind.FillRectangle(&Pen, X, Y, XX, YY);
            }
        }
        //------------------------------------------------------------------------------------------------
        void Render_DrawImage(string ImageFile, int X, int Y, int XX, int YY) noexcept//屏幕图像绘制  CPU占用高 绘制慢*
        {
            Gdiplus::Graphics HDCwind(hMenDC);
            Gdiplus::Bitmap bmp(wstring(ImageFile.begin(), ImageFile.end()).c_str());
            HDCwind.DrawImage(&bmp, X, Y, XX, YY);
        }
        //------------------------------------------------------------------------------------------------
        void RenderA_GradientCircle(int X, int Y, int Size, vector<int>Color_1, vector<int>Color_2, float Focus = 1) noexcept//绘制路径渐变圆形(包含Alpha) 内到外
        {
            Gdiplus::Graphics HDCwind(hMenDC);
            Gdiplus::GraphicsPath m_Path;//构造空路径
            m_Path.AddEllipse(X - Size / 2, Y - Size / 2, Size, Size);//添加椭圆
            Gdiplus::PathGradientBrush pathBrush(&m_Path);//使用路径创建画刷
            pathBrush.SetCenterColor(Gdiplus::Color(Color_1[3], Color_1[0], Color_1[1], Color_1[2]));//设置中心颜色
            Gdiplus::Color colors[] = { Gdiplus::Color(Color_2[3], Color_2[0], Color_2[1], Color_2[2]) };//边界颜色
            int i = 1; pathBrush.SetSurroundColors(colors, &i);
            pathBrush.SetFocusScales(Focus, Focus);//设置聚焦缩放0-1 float
            HDCwind.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);//抗锯齿 https://blog.csdn.net/hgy413/article/details/6692932
            HDCwind.FillEllipse(&pathBrush, X - Size / 2, Y - Size / 2, Size, Size);
        }
        //------------------------------------------------------------------------------------------------
        int Render_String(int X, int Y, string String, string FontName, int FontSize, vector<int>Color, BOOL AntiAlias = true) noexcept//文字绘制(不包含Alpha)
        {
            HDC HMS = hMenDC;
            HGDIOBJ FontPen;
            if (AntiAlias)FontPen = SelectObject(HMS, CreateFont(FontSize, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, wstring(FontName.begin(), FontName.end()).c_str()));
            else FontPen = SelectObject(HMS, CreateFont(FontSize, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, NONANTIALIASED_QUALITY, FF_DONTCARE, wstring(FontName.begin(), FontName.end()).c_str()));
            SetTextColor(HMS, RGB(Color[0], Color[1], Color[2]));//文字颜色
            SetBkMode(HMS, TRANSPARENT);//背景透明
            TextOutA(HMS, X, Y, String.c_str(), strlen(String.c_str()));
            DeleteObject(FontPen);
            return strlen(String.c_str());
        }
        //------------------------------------------------------------------------------------------------
        void Render_Line(int X, int Y, int XX, int YY, vector<int>Color, int LineThickness = 1) noexcept//屏幕画线(不包含Alpha 无抗锯齿)
        {
            HDC DC = hMenDC;
            HGDIOBJ LineColor = SelectObject(DC, CreatePen(PS_SOLID, LineThickness, RGB(Color[0], Color[1], Color[2])));
            MoveToEx(DC, X, Y, NULL);
            LineTo(DC, XX, YY);
            DeleteObject(LineColor);
        }
        //------------------------------------------------------------------------------------------------
        void Render_SolidRect(int X, int Y, int XX, int YY, vector<int>Color) noexcept//屏幕画实心矩形带颜色(不包含Alpha)
        {
            HDC HMS = hMenDC;
            HGDIOBJ BIANKUANG = SelectObject(HMS, CreatePen(PS_SOLID, 1, RGB(Color[0], Color[1], Color[2])));
            HGDIOBJ TIANCHONG = SelectObject(HMS, CreateSolidBrush(RGB(Color[0], Color[1], Color[2])));
            Rectangle(HMS, X, Y, X + XX, Y + YY);
            DeleteObject(BIANKUANG);
            DeleteObject(TIANCHONG);
        }
        //------------------------------------------------------------------------------------------------
        void Render_HollowRect(int X, int Y, int XX, int YY, int K, vector<int>Color) noexcept//屏幕画空心矩形带颜色(不包含Alpha)
        {
            HDC HMS = hMenDC;
            HGDIOBJ BIANKUANG = SelectObject(HMS, CreatePen(PS_SOLID, K, RGB(Color[0], Color[1], Color[2])));
            HGDIOBJ TIANCHONG = SelectObject(HMS, (HBRUSH)GetStockObject(NULL_BRUSH));
            Rectangle(HMS, X, Y, X + XX, Y + YY);
            DeleteObject(BIANKUANG);
            DeleteObject(TIANCHONG);
        }
        //------------------------------------------------------------------------------------------------
        void Render_GradientRect(int X, int Y, int XX, int YY, vector<int>Color_1, vector<int>Color_2, BOOL Style = 0) noexcept//绘制渐变色矩形(不包含Alpha) 0横向渐变 1竖向渐变
        {
            TRIVERTEX vert[2];
            GRADIENT_RECT gRect;
            vert[0].Alpha = 0x0000;
            vert[1].Alpha = 0x0000;
            gRect.UpperLeft = 0;
            gRect.LowerRight = 1;
            COLORREF Color1 = RGB(Color_1[0], Color_1[1], Color_1[2]);
            COLORREF Color2 = RGB(Color_2[0], Color_2[1], Color_2[2]);
            vert[0].x = X;
            vert[0].y = Y;
            vert[1].x = X + XX;
            vert[1].y = Y + YY;
            vert[0].Red = GetRValue(Color1) << 8;
            vert[0].Green = GetGValue(Color1) << 8;
            vert[0].Blue = GetBValue(Color1) << 8;
            vert[1].Red = GetRValue(Color2) << 8;
            vert[1].Green = GetGValue(Color2) << 8;
            vert[1].Blue = GetBValue(Color2) << 8;
            if (!Style)GradientFill(hMenDC, vert, 2, &gRect, 1, GRADIENT_FILL_RECT_H);
            else GradientFill(hMenDC, vert, 2, &gRect, 1, GRADIENT_FILL_RECT_V);
        }
        //------------------------------------------------------------------------------------------------
        void Render_HollowCircle(int X, int Y, int Size, vector<int>Color, int LineThickness = 1) noexcept//绘制空心圆形(不包含Alpha 无抗锯齿)
        {
            HDC wind = hMenDC;
            HGDIOBJ BIANKUANG = SelectObject(wind, CreatePen(PS_SOLID, LineThickness, RGB(Color[0], Color[1], Color[2])));
            HGDIOBJ TIANCHONG = SelectObject(wind, (HBRUSH)GetStockObject(NULL_BRUSH));
            Ellipse(wind, X - Size / 2, Y - Size / 2, X + Size / 2, Y + Size / 2);//通过绘制曲线来绘制圆*
            DeleteObject(BIANKUANG);
            DeleteObject(TIANCHONG);
        }
        //------------------------------------------------------------------------------------------------
        void Render_SolidCircle(int X, int Y, int Size, vector<int>Color_1, vector<int>Color_2, int LineThickness = 1) noexcept//绘制实心圆形(不包含Alpha 无抗锯齿)
        {
            HDC wind = hMenDC;
            HGDIOBJ BIANKUANG = SelectObject(wind, CreatePen(PS_SOLID, LineThickness, RGB(Color_1[0], Color_1[1], Color_1[2])));
            HGDIOBJ TIANCHONG = SelectObject(wind, CreateSolidBrush(RGB(Color_2[0], Color_2[1], Color_2[2])));
            Ellipse(wind, X - Size / 2, Y - Size / 2, X + Size / 2, Y + Size / 2);//通过绘制曲线来绘制圆*
            DeleteObject(BIANKUANG);
            DeleteObject(TIANCHONG);
        }
        //------------------------------------------------------------------------------------------------
        void Render_GradientTriangle(vector<int>Pos_3Point, vector<int>Color_1, vector<int>Color_2, vector<int>Color_3) noexcept//绘制渐变色三角形（3种颜色）(不包含Alpha 无抗锯齿)
        {
            TRIVERTEX vert[3];
            GRADIENT_TRIANGLE gTRi;
            COLORREF Color1 = RGB(Color_1[0], Color_1[1], Color_1[2]);
            COLORREF Color2 = RGB(Color_2[0], Color_2[1], Color_2[2]);
            COLORREF Color3 = RGB(Color_3[0], Color_3[1], Color_3[2]);
            vert[0].x = Pos_3Point[0];
            vert[0].y = Pos_3Point[1];
            vert[1].x = Pos_3Point[2];
            vert[1].y = Pos_3Point[3];
            vert[2].x = Pos_3Point[4];
            vert[2].y = Pos_3Point[5];
            vert[0].Red = GetRValue(Color1) << 8;
            vert[0].Green = GetGValue(Color1) << 8;
            vert[0].Blue = GetBValue(Color1) << 8;
            vert[0].Alpha = 0x0000;
            vert[1].Red = GetRValue(Color2) << 8;
            vert[1].Green = GetGValue(Color2) << 8;
            vert[1].Blue = GetBValue(Color2) << 8;
            vert[1].Alpha = 0x0000;
            vert[2].Red = GetRValue(Color3) << 8;
            vert[2].Green = GetGValue(Color3) << 8;
            vert[2].Blue = GetBValue(Color3) << 8;
            vert[2].Alpha = 0x0000;
            gTRi.Vertex1 = 0;
            gTRi.Vertex2 = 1;
            gTRi.Vertex3 = 2;
            GradientFill(hMenDC, vert, 3, &gTRi, 1, GRADIENT_FILL_TRIANGLE);
        }
        //------------------------------------------------------------------------------------------------
        void Render_SimpleString(int X, int Y, string String, vector<int>Color_1, vector<int>Color_2 = { 0,0,0 }) noexcept//文字绘制(简单样式)(不包含Alpha)
        {
            HDC Hdc = hMenDC;
            HGDIOBJ FontPen = SelectObject(Hdc, CreateFont(9, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, NONANTIALIASED_QUALITY, FF_DONTCARE, L"Lucida Console"));
            SetBkMode(Hdc, TRANSPARENT);//背景透明
            SetTextColor(Hdc, RGB(Color_2[0], Color_2[1], Color_2[2]));//文字颜色
            TextOutA(Hdc, X + 1, Y + 1, String.c_str(), strlen(String.c_str()));
            TextOutA(Hdc, X - 1, Y - 1, String.c_str(), strlen(String.c_str()));
            TextOutA(Hdc, X + 1, Y - 1, String.c_str(), strlen(String.c_str()));
            TextOutA(Hdc, X - 1, Y + 1, String.c_str(), strlen(String.c_str()));
            TextOutA(Hdc, X + 1, Y, String.c_str(), strlen(String.c_str()));
            TextOutA(Hdc, X - 1, Y, String.c_str(), strlen(String.c_str()));
            TextOutA(Hdc, X, Y - 1, String.c_str(), strlen(String.c_str()));
            TextOutA(Hdc, X, Y + 1, String.c_str(), strlen(String.c_str()));
            SetTextColor(Hdc, RGB(Color_1[0], Color_1[1], Color_1[2]));//文字颜色
            TextOutA(Hdc, X, Y, String.c_str(), strlen(String.c_str()));
            DeleteObject(FontPen);
        }
        //------------------------------------------------------------------------------------------------
        void RenderA_String(int X, int Y, string String, string Font, int FontSize, vector<int>Color) noexcept//文字绘制(包含Alpha)
        {
            if (Font == "0" || Font == "NONE")Font = "Lucida Console";//默认字体
            Gdiplus::Graphics HDCwind(hMenDC);//HDC
            Gdiplus::FontFamily  fontFamily(wstring(Font.begin(), Font.end()).c_str());
            HDCwind.SetTextRenderingHint(Gdiplus::TextRenderingHintAntiAlias);//抗锯齿
            Gdiplus::Font font(&fontFamily, FontSize, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);//字体状况（大小 斜体）
            Gdiplus::PointF pointF(X, Y);//文字绘制坐标
            Gdiplus::SolidBrush solidBrush(Gdiplus::Color(Color[3], Color[0], Color[1], Color[2]));//文字颜色（包含Alpha）
            HDCwind.DrawString(wstring(String.begin(), String.end()).c_str(), -1, &font, pointF, &solidBrush);//最终绘制
        }
        //--------------------------------------------------------------------------------------------------------
    };
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    HWND NVIDIA_Overlay() noexcept//英伟达覆盖绘制初始化(在上绘制不会导致背后窗口掉帧) 详细可查看: https://github.com/iraizo/nvidia-overlay-hijack/blob/master/src/overlay.cpp
    {//const auto Window_Render = Window::NVIDIA_Overlay();
        const HWND Window_HWND = FindWindow(L"CEF-OSC-WIDGET", L"NVIDIA GeForce Overlay");
        SetWindowLongPtrA(Window_HWND, -20, (LONG_PTR)(GetWindowLongA(Window_HWND, -20) | 0x20));
        MARGINS margin; margin.cyBottomHeight = margin.cyTopHeight = margin.cxLeftWidth = margin.cxRightWidth = -1;
        DwmExtendFrameIntoClientArea(Window_HWND, &margin);
        SetLayeredWindowAttributes(Window_HWND, 0x000000, 0xFF, 0x02);
        SetWindowPos(Window_HWND, HWND_TOPMOST, 0, 0, 0, 0, 0x0002 | 0x0001);
        ShowWindow(Window_HWND, SW_SHOW);
        return Window_HWND;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
}
namespace System//Windows系统
{
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    vector<int> RainbowColor(int Speed, const int Follo = 0) noexcept//彩虹色值
    {//System::RainbowColor(100);//颜色变换速度 (越大越慢)
        return { (int)floor(sin((float)GetTickCount64() / (Speed * 100) * 2 + Follo) * 127 + 128), (int)floor(sin((float)GetTickCount64() / (Speed * 100) * 2 + 2 + Follo) * 127 + 128), (int)floor(sin((float)GetTickCount64() / (Speed * 100) * 2 + 4 + Follo) * 127 + 128) };
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Source_ExecuteCommand(string String, const HWND m_hEngine = FindWindow(L"Valve001", 0)) noexcept//起源引擎游戏执行命令
    {//System::Source_ExecuteCommand("kill");
        COPYDATASTRUCT m_cData; m_cData.cbData = strlen(String.c_str()) + 1; m_cData.dwData = 0; m_cData.lpData = (void*)String.c_str();
        SendMessage(m_hEngine, WM_COPYDATA, 0, (LPARAM)&m_cData);
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Mouse_Move(int X, int Y) noexcept//移动鼠标坐标(可实现游戏内改变视觉角度)鼠标原来的坐标加上设定值
    {//System::Mouse_Move(100, 100);
        mouse_event(MOUSEEVENTF_MOVE, X, Y, 0, 0);
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Key_Click(int VK_CODE, BOOL Sleep_ = false) noexcept//按下弹起键盘上的某个键位 VK_CODE: https://docs.microsoft.com/zh-cn/windows/win32/inputdev/virtual-key-codes
    {//System::Key_Click(VK_RETURN);
        if (Sleep_)//添加睡眠函数程序更容易接收
        {
            keybd_event(VK_CODE, 0, 0, 0);
            Sleep(1);
            keybd_event(VK_CODE, 0, KEYEVENTF_KEYUP, 0);
            Sleep(1);
        }
        else {
            keybd_event(VK_CODE, 0, 0, 0);
            keybd_event(VK_CODE, 0, KEYEVENTF_KEYUP, 0);
        }
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    vector<int> Get_MousePos() noexcept//获取鼠标坐标
    {//System::GetMousePos()[0];
        POINT XY; GetCursorPos(&XY);
        return { XY.x, XY.y };//[0]X坐标  [1]Y坐标
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Play_Sound_WAV(string Str_WAV) noexcept//播放WAV文件（声音）（同时播放2个文件会中断）
    {//System::Play_Sound_WAV("D:\\SteamLibrary\\steamapps\\common\\Counter-Strike Global Offensive\\55.wav");
        PlaySound(wstring(Str_WAV.begin(), Str_WAV.end()).c_str(), NULL, SND_FILENAME | SND_ASYNC);
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Open_Website(string Link) noexcept//打开浏览器网址
    {//System::Open_Website("https://www.baidu.com/");
        system(("start " + Link).c_str());
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    vector<int> Time() noexcept//获取系统时间
    {//System::Time()[0];
        SYSTEMTIME sys; GetLocalTime(&sys);
        return { sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond,sys.wMilliseconds,sys.wDayOfWeek };//0=年份 1=月份 2=天 3=小时 4=分钟 5=秒 6=毫秒 7=星期几
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    string Time_String() noexcept//获取系统时间(有了格式的String)
    {//string Time = System::Time_String();
        SYSTEMTIME sys;
        GetLocalTime(&sys);
        string Hour = to_string(sys.wHour);
        string Minute = to_string(sys.wMinute);
        string Second = to_string(sys.wSecond);
        if (sys.wHour < 10)Hour = "0" + Hour;
        if (sys.wMinute < 10)Minute = "0" + Minute;
        if (sys.wSecond < 10)Second = "0" + Second;
        return Hour + ":" + Minute + ":" + Second;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Create_Folder(string filename) noexcept//创建文件夹(空文件夹)
    {//System::Create_Folder("Test Folder");
        system(("mkdir " + filename).c_str());
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    BOOL Judge_File(string FileName) noexcept//判断 文件or夹 是否存在
    {//System::Judge_File("Test File.txt");
        if (_access(FileName.c_str(), 0) == -1)return false;
        else return true;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Create_File(string FileName, string Content, BOOL Append = false) noexcept//生成并且改写任何文件 //详细：https://blog.csdn.net/qq_29406323/article/details/81261926
    {//System::Create_File("Test File.txt","1\n2\n3\n");
        if (Append)//Append
        {
            fstream foundfile(FileName.c_str(), ios::app);
            if (foundfile.is_open())foundfile << Content.c_str(); foundfile.close();
        }
        else {//Set
            fstream foundfile(FileName.c_str(), ios::out);
            if (foundfile.is_open())foundfile << Content.c_str(); foundfile.close();
        }
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    string Get_File(string file, int line) noexcept//获取文件信息中的特定行数
    {//System::Get_File("Free(武器力度参数).txt", 2);
        ifstream infile; infile.open(file, ios::in);//将文件流对象与文件连接起来 
        static char str[2048];//初始化缓冲区
        for (int i = 0; i < line; i++)infile.getline(str, sizeof(str));//遍历
        infile.close();//关闭文件输入流 
        return str;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    template<class A>//为了防止双函数同步
    BOOL Key_Toggle(int key) noexcept//切换模式按键触发 另一种写法：GetKeyState(VK_TAB)
    {//System::Key_Toggle<class Key_Toggle>(VK_TAB);
        static BOOL keys = false;
        if (!keys && (GetAsyncKeyState(key) & 0x8000))
        {
            keys = true;
            keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
        }
        else if (keys && (GetAsyncKeyState(key) & 0x8000))
        {
            keys = false;
            keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
        }
        return keys;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Copy(string String) noexcept//复制指定内容到剪贴板 (汉子会乱码 解决方法：输入法调成中文)
    {//System::Copy("汉子 中 !@# abc");
        OpenClipboard(NULL);//打开剪切板
        EmptyClipboard();//清空剪切板
        HANDLE hHandle = GlobalAlloc(GMEM_FIXED, strlen(String.c_str()) + 1);//分配内存
        char* pData = (char*)GlobalLock(hHandle);//锁定内存，返回申请内存的首地址
        strcpy_s(pData, strlen(String.c_str()) + 1, String.c_str());//或strcpy(pData, "this is a ClipBoard Test.");
        SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
        GlobalUnlock(hHandle);//解除锁定
        CloseClipboard();//关闭剪切板
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Stickup() noexcept//粘贴剪切板内容 (按键脚本)
    {//System::Stickup();
        keybd_event(VK_CONTROL, 0, 0, 0);//按下ctrl
        keybd_event(0x56, 0x2F, 0, 0);//按下v
        keybd_event(0x56, 0x2F, KEYEVENTF_KEYUP, 0);//松开v
        keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);//松开ctrl
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Copy_Stickup(string String) noexcept//复制粘贴 (汉子会乱码 解决方法：输入法调成中文)
    {//System::Copy_Stickup("汉子 中 !@# abc");
        OpenClipboard(NULL);//打开剪切板
        EmptyClipboard();//清空剪切板
        HANDLE hHandle = GlobalAlloc(GMEM_FIXED, strlen(String.c_str()) + 1);//分配内存
        char* pData = (char*)GlobalLock(hHandle);//锁定内存，返回申请内存的首地址
        strcpy_s(pData, strlen(String.c_str()) + 1, String.c_str());//或strcpy(pData, "this is a ClipBoard Test.");
        SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
        GlobalUnlock(hHandle);//解除锁定
        CloseClipboard();//关闭剪切板
        keybd_event(VK_CONTROL, 0, 0, 0);//按下ctrl
        keybd_event(0x56, 0x2F, 0, 0);//按下v
        keybd_event(0x56, 0x2F, KEYEVENTF_KEYUP, 0);//松开v
        keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);//松开ctrl
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    int Rand_Number(int 以上, int 以下) noexcept//随机数（每次都不同）
    {//System::Rand_Number(0, 1000);//返回0~1000整数
        srand(GetTickCount64() + time(0) * GetTickCount64());//防止一样的函数同步
        return rand() % (以下 - 以上 + 1) + 以上;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    string Get_UserName() noexcept//获取电脑用户名
    {//System::Get_UserName();
        char szBuffer[256];
        DWORD dwNameLen = 256;
        GetUserNameA(szBuffer, &dwNameLen);
        return (string)szBuffer;
    }
    string Get_ComputerName() noexcept//获取电脑名
    {//System::Get_ComputerName();
        char szBuffer[256];
        DWORD dwNameLen = 256;
        GetComputerNameA(szBuffer, &dwNameLen);
        return (string)szBuffer;
    }
    string Get_IPv4Address() noexcept//获取电脑IPv4地址
    {//System::Get_IPv4Address();
        WSADATA WSAData;//WSADATA结构被用来储存调用AfxSocketInit全局函数返回的Windows Sockets初始化信息。
        WSAStartup(MAKEWORD(2, 0), &WSAData);//初始化Windows sockets API
        char hostName[256];
        gethostname(hostName, sizeof(hostName));
        return inet_ntoa(*(struct in_addr*)*gethostbyname(hostName)->h_addr_list);
        //WSACleanup();
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Anti_click() noexcept//防止控制台程序选择暂停(控制台窗口内绘制菜单需要它(虽然人们不会在控制台窗口内绘制XD))
    {//System::Anti_click();
        DWORD mode;
        GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
        mode &= ~ENABLE_QUICK_EDIT_MODE;
        SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), mode);
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Self_Delete(string SelfName = "*.exe") noexcept//程序自删除 输入自身程序名即可删除掉自身
    {//System::Self_Delete();
        FILE* DeleteBatFile = NULL;
        DeleteBatFile = fopen("...bat", "w");
        fputs(("del " + SelfName + "\ndel ...bat\n").c_str(), DeleteBatFile);
        system("start ...bat\n");
        exit(0);//结束进程
    }
    void Self_Restart() noexcept//重启自身程序
    {//System::Self_Restart();
        TCHAR szPath[MAX_PATH];
        GetModuleFileName(NULL, szPath, MAX_PATH);
        STARTUPINFO StartInfo;
        PROCESS_INFORMATION procStruct;
        memset(&StartInfo, 0, sizeof(STARTUPINFO));
        StartInfo.cb = sizeof(STARTUPINFO);
        if (!CreateProcess((LPCTSTR)szPath, NULL, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &StartInfo, &procStruct));//创建自身克隆体
        CloseHandle(procStruct.hProcess);
        CloseHandle(procStruct.hThread);
        exit(0);//关闭自身
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    BOOL MousePos_RectRegion(int StartPosX, int StartPosY, int EndPosX, int EndPosY) noexcept//检测鼠标是否在一个矩形区域内
    {//System::MousePos_RectRegion(100,100,200,200);
        POINT MousePos; GetCursorPos(&MousePos);
        if (MousePos.x >= StartPosX && MousePos.x <= StartPosX + EndPosX && MousePos.y >= StartPosY && MousePos.y <= StartPosY + EndPosY)return true; else return false;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    int Get_Hold_VKKey() noexcept//获取当前按下的键（VK码 16进制）
    {//printf("0x%X\n", System::Get_Hold_VKKey());
        for (int i = 0x01; i < 0xFE; ++i)if (GetAsyncKeyState(i) & 0x8000)return i;//vk键码遍历 返回按下的键的vk码
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    BOOL Get_Mouse_Move(const int Sleep_ = 1) noexcept//获取鼠标是否移动（有1ms延时）
    {//System::Get_Mouse_Move();    if(System::Get_Mouse_Move()){}
        POINT XY; GetCursorPos(&XY);
        Sleep(Sleep_);
        POINT XYX; GetCursorPos(&XYX);
        if (XY.x != XYX.x || XY.y != XYX.y)return true; else return false;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    BOOL DownloadToPath(string Str_URL, string Str_DownloadPath) noexcept//下载文件到目录 当返回true则下载成功  下载到盘(无路径)需要管理员身份执行程序
    {//System::DownloadToPath("https://codeload.github.com/cazzwastaken/internal-bhop/zip/refs/heads/main", "C:\\mypic.zip")
        DWORD dwAttribute = GetFileAttributes(wstring(Str_DownloadPath.begin(), Str_DownloadPath.end()).c_str());
        if (dwAttribute == 0XFFFFFFFF && URLDownloadToFile(0, wstring(Str_URL.begin(), Str_URL.end()).c_str(), wstring(Str_DownloadPath.begin(), Str_DownloadPath.end()).c_str(), 0, 0) == S_OK)return true;
        else return false;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Sleep_ns(int ns) noexcept//纳秒单位等待函数 10000 = 1毫秒 比Sleep(1);更低的延时(前提设置的值在10000以内*)
    {//System::Sleep_ns(100); //= Sleep(0.1);
        this_thread::sleep_for(chrono::nanoseconds(ns));//纳秒单位等待函数
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    class PlaySounds
    {
        /*
        System::PlaySounds ss;
        ss.Open("TestWAV.mp3");
        ss.Play();
        */
    public:
        //-------------------------------------------------------
        void Open(string File) noexcept//打开音频文件(必须项* 如果放到循环需要把Sleep函数值设置到100以上*)
        {
            WCHAR wszClassName[1024];//转换
            memset(wszClassName, 0, sizeof(wszClassName));
            MultiByteToWideChar(CP_ACP, 0, ("open " + File + " alias SoundP").c_str(), strlen(("open " + File + " alias SoundP").c_str()) + 1, wszClassName, sizeof(wszClassName) / sizeof(wszClassName[0]));
            mciSendString(wszClassName, NULL, NULL, NULL);//https://stackoverflow.com/questions/38154985/string-to-lpcwstr-in-c
        }
        //-------------------------------------------------------
        void Play() noexcept//播放打开的音频文件
        {
            mciSendString(L"play SoundP", NULL, NULL, NULL);
        }
        //-------------------------------------------------------
        void Play_Repeat() noexcept//循环播放打开的音频文件
        {
            mciSendString(L"play SoundP repeat", NULL, NULL, NULL);
        }
        //-------------------------------------------------------
        void Stop() noexcept//暂停播放
        {
            mciSendString(L"pause SoundP", NULL, NULL, NULL);
        }
        //-------------------------------------------------------
        void Resume() noexcept//继续播放
        {
            mciSendString(L"resume SoundP", NULL, NULL, NULL);
        }
        //-------------------------------------------------------
        void Seek(int Ms) noexcept//快进快退
        {
            WCHAR wszClassName[1024];//转换
            memset(wszClassName, 0, sizeof(wszClassName));
            MultiByteToWideChar(CP_ACP, 0, ("seek SoundP to " + to_string(Ms)).c_str(), strlen(("seek SoundP to " + to_string(Ms)).c_str()) + 1, wszClassName, sizeof(wszClassName) / sizeof(wszClassName[0]));
            mciSendString(wszClassName, NULL, NULL, NULL);
            mciSendString(L"play SoundP", NULL, NULL, NULL);
        }
        //-------------------------------------------------------
        void Volume(int Ints) noexcept//设置音量(百分比)
        {
            WCHAR wszClassName[1024];//转换
            memset(wszClassName, 0, sizeof(wszClassName));
            MultiByteToWideChar(CP_ACP, 0, ("setaudio SoundP volume to " + to_string(Ints) + "0").c_str(), strlen(("setaudio SoundP volume to " + to_string(Ints) + "0").c_str()) + 1, wszClassName, sizeof(wszClassName) / sizeof(wszClassName[0]));
            mciSendString(wszClassName, NULL, NULL, NULL);
        }
        //-------------------------------------------------------
        void Close() noexcept//释放音频文件(终止播放)
        {
            mciSendString(L"close SoundP", NULL, NULL, NULL);
        }
        //-------------------------------------------------------
    };
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    BOOL Get_Key_Onest(int VK_KeyCode) noexcept//获取按键按下只瞬间返回
    {//Get_Key_Onest(VK_INSERT);
        if (GetAsyncKeyState(VK_KeyCode) & 0x8000)//获取按下的按键
        {
            keybd_event(VK_KeyCode, 0, KEYEVENTF_KEYUP, 0);//松开按键
            return true;//返回按下
        }
        else return false;//返回
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    template<class A>//防止同函数同步
    BOOL Sleep_Tick(int Time_MS) noexcept//不受线程影响的Sleep函数
    {//System::Sleep_Tick<class oiduwaj>(500);
        static BOOL Onest = true;
        if (Onest)//初始化返回true
        {
            Onest = false;
            return true;
        }
        static long OldTick = GetTickCount64();
        long Tick = GetTickCount64() - OldTick;
        if (Tick >= Time_MS)//当达到一定数值返回并且重写变量
        {
            OldTick = GetTickCount64();
            return true;
        }
        else return false;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    BOOL Get_Key(int VK_Code) noexcept//获取按键是否被按下（不会出现没有按下却返回true的bug）
    {//System::Get_Key(VK_INSERT);
        if (GetAsyncKeyState(VK_Code) & 0x8000)return true; else return false;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Read_String(string Str, vector<int> Volume_Rate = { 100, 0 }) noexcept//字符串通过语音播放 问题: 会内存泄漏导致程序暂停
    {//System::Read_String("Hello", {100, 0});
        wstring wszStr;
        int nLength = MultiByteToWideChar(CP_ACP, 0, Str.c_str(), -1, NULL, NULL);
        wszStr.resize(nLength);
        LPWSTR lpwszStr = new wchar_t[nLength];
        MultiByteToWideChar(CP_ACP, 0, Str.c_str(), -1, lpwszStr, nLength);
        wszStr = lpwszStr;
        delete[] lpwszStr;
        //------------------转换
        ISpVoice* pVoice = NULL;
        CoInitialize(NULL);
        CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);//获取SpVoice接口
        pVoice->SetVolume((USHORT)Volume_Rate[0]);//范围: 0~100
        pVoice->SetRate(Volume_Rate[1]);//范围: -10~10
        pVoice->Speak(wszStr.c_str(), 0, NULL);
        pVoice->Release();
        pVoice = NULL;
        CoUninitialize();//释放com资源
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Log(string Str = "", BOOL b_Error = false, ...) noexcept//带有时间标题的打印控制台
    {//System::Log("Value: " + 1);
        SYSTEMTIME sys; GetLocalTime(&sys);
        string Hour = to_string(sys.wHour);
        string Minute = to_string(sys.wMinute);
        string Second = to_string(sys.wSecond);
        string Millisecond = to_string(sys.wMilliseconds);
        if (sys.wHour < 10)Hour = "0" + Hour;
        if (sys.wMinute < 10)Minute = "0" + Minute;
        if (sys.wSecond < 10)Second = "0" + Second;
        if (sys.wMilliseconds < 10)Millisecond = "00" + Millisecond;
        else if (sys.wMilliseconds < 100)Millisecond = "0" + Millisecond;
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        if (b_Error)SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 5);
        else SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 2);
        printf(("[" + Hour + ":" + Minute + ":" + Second + "." + Millisecond + "] " + Str + "\n").c_str());
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    string Rand_String(int len = 10) noexcept//随机字符串
    {//System::Rand_String(20);//生成20个字符的字符串
        string str; char c;
        srand(GetTickCount64() + time(0) * GetTickCount64() + rand());//修复产生相同的随机字符
        for (short idx = 0; idx < len; idx++)
        {
            const int Rand = rand();
            if ((Rand % 4) == 0)c = 'a' + Rand % 26;
            else if ((Rand % 4) == 1)c = 'A' + Rand % 26;
            else if ((Rand % 4) == 2)c = '0' + Rand % 10;
            else if ((Rand % 4) == 3)c = '!' + Rand % 30;
            str.push_back(c);
        }
        return str;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    class Memory//内存类
    {
        /*
        int main()//Bunny Hup
        {
            System::Memory CS_Mem = { "csgo.exe" };//Create
            const auto Client_dll = CS_Mem.Get_Module("client.dll");
            cout << "client.dll -> 0x" << hex << Client_dll << endl;
            while (1)
            {
                const auto LocalPlayer = CS_Mem.Read<uintptr_t>(Client_dll + 0xDEA98C);//Localplayer
                if (CS_Mem.Read<BOOL>(LocalPlayer + 0x104) & (1 << 0) && (GetAsyncKeyState(VK_SPACE) & 0x8000))//Spacebar localplayer in ground
                {
                    System::Source_ExecuteCommand("+jump");//jump
                    Sleep(1);
                    System::Source_ExecuteCommand("-jump");
                }
                Sleep(1);
            }
        }
        */
    private:
        uintptr_t ProcessID = 0;//进程ID
        HANDLE HProcessID = 0;
    public:
        //-----------------------------------------------------------------------------------------
        Memory(string ProcessName) noexcept//获取进程ID 用来内存函数(可以用来初始化不放在循环)
        {
            PROCESSENTRY32 entry = { };
            entry.dwSize = sizeof(PROCESSENTRY32);
            const auto Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
            while (Process32Next(Snapshot, &entry))
            {
                if (wcscmp(entry.szExeFile, wstring(ProcessName.begin(), ProcessName.end()).c_str()) == 0)//判断字符串是否相等
                {
                    ProcessID = entry.th32ProcessID;
                    HProcessID = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);
                    break;
                }
            }
            CloseHandle(Snapshot);
        }
        //-----------------------------------------------------------------------------------------
        uintptr_t Get_Module(string ModuleName) noexcept//读取模块地址
        {
            MODULEENTRY32 entry = { };
            entry.dwSize = sizeof(MODULEENTRY32);
            const auto Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcessID);//获取所有模块
            uintptr_t dwModuleBaseAddress = 0;//返回值
            while (Module32Next(Snapshot, &entry))//遍历所有模块
            {
                if (wcscmp(entry.szModule, wstring(ModuleName.begin(), ModuleName.end()).c_str()) == 0)//判断字符串是否相等
                {
                    dwModuleBaseAddress = reinterpret_cast<uintptr_t>(entry.modBaseAddr);
                    break;
                }
            }
            CloseHandle(Snapshot);//删除遍历
            return dwModuleBaseAddress;//返回地址
        }
        //-----------------------------------------------------------------------------------------
        template<class T>
        T Write(uintptr_t Address, T value) noexcept//写入内存
        {
            WriteProcessMemory(HProcessID, (LPVOID)(Address), &value, sizeof(T), NULL);
            return value;
        }
        //-----------------------------------------------------------------------------------------
        template<class T>
        T Read(uintptr_t Address) noexcept//读取内存
        {
            T Value = { };
            ReadProcessMemory(HProcessID, (LPVOID)(Address), &Value, sizeof(T), NULL);
            return Value;
        }
        //-----------------------------------------------------------------------------------------
        template<class T>
        T Write_Level(uintptr_t Address, vector<DWORD>Offsets, T value) noexcept//修改地址的内存(等级地址版本)
        {
            uintptr_t F = { };
            ReadProcessMemory(HProcessID, (LPVOID)(Address), &F, sizeof(uintptr_t), NULL);
            for (short i = 0; i <= Offsets.size() - 1; ++i)ReadProcessMemory(HProcessID, (LPVOID)(F + Offsets[i - 1]), &F, sizeof(uintptr_t), NULL);//计算等级
            WriteProcessMemory(HProcessID, (LPVOID)(F + Offsets[Offsets.size() - 1]), &value, sizeof(T), NULL);
            return value;
        }
        //-----------------------------------------------------------------------------------------
        template<class T>
        T Read_Level(uintptr_t Address, vector<DWORD>Offsets) noexcept//获取地址的内存(等级地址版本)
        {
            uintptr_t F = { };
            T Returnvalue = { };
            ReadProcessMemory(HProcessID, (LPVOID)(Address), &F, sizeof(uintptr_t), NULL);
            for (short i = 0; i <= Offsets.size() - 1; ++i)ReadProcessMemory(HProcessID, (LPVOID)(F + Offsets[i - 1]), &F, sizeof(uintptr_t), NULL);//计算等级
            ReadProcessMemory(HProcessID, (LPVOID)(F + Offsets[Offsets.size() - 1]), &Returnvalue, sizeof(T), NULL);
            return Returnvalue;
        }
        //-----------------------------------------------------------------------------------------
        uintptr_t Get_ProcessID() noexcept { return ProcessID; }//获取进程ID
        HWND Get_ProcessHWND() noexcept//获取进程HWND
        {
            HWND h = GetTopWindow(0);
            HWND retHwnd = NULL;
            while (h)
            {
                DWORD pid = 0;
                uintptr_t dwTheardId = GetWindowThreadProcessId(h, &pid);
                if (dwTheardId != 0 && pid == ProcessID && GetParent(h) == NULL && IsWindowVisible(h))retHwnd = h;
                h = GetNextWindow(h, GW_HWNDNEXT);
            }
            return retHwnd;
        }
        //-----------------------------------------------------------------------------------------
    };
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    void Post_Message(HWND Window_HWND, WPARAM Message_Value, UINT Message_Type = WM_CHAR) noexcept//向指定窗口发送消息 https://blog.51cto.com/csnd/5480626
    {//System::Post_Message(NULL, 'A');
        if (Window_HWND == 0)PostMessage(GetForegroundWindow(), Message_Type, Message_Value, 0);//如果Window_HWND值为0则发送到最前端窗口
        else PostMessage(Window_HWND, Message_Type, Message_Value, 0);//WM_KEYDOWN WM_KEYUP WM_RBUTTONDOWN WM_CHAR
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
}
namespace Variable//变量转换
{
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    int ValueAddress(int value) noexcept//转换16进制（可用于偏移修改）*X64游戏地址不需要转16进制
    {//Variable::ValueAddress(100);返回64
        stringstream ioss; //定义字符串流
        int s_temp; //存放转化后字符
        ioss << "0x" << setiosflags(ios::uppercase) << hex << value; //以十六制(大写)形式输出
        ioss >> s_temp;
        return s_temp;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    int string_int_(string Str) noexcept//string转int
    {//Variable::string_int_("123");
        return atoi(Str.c_str());
    }
    //-------------------------------------------------------
    DWORD64 string_DWORD_(string Str) noexcept//string转DWORD
    {//Variable::string_DWORD_("0x16");
        DWORD64 cur_dword; sscanf(Str.c_str(), "%X", &cur_dword);
        return cur_dword;
    }
    //-------------------------------------------------------
    float string_float_(string Str) noexcept//string转float
    {//Variable::string_float_("0.0623");
        return atof(Str.c_str());
    }
    //-------------------------------------------------------
    LPCWSTR string_LPCWSTR_(string Str) noexcept//string转换LPCWSTR
    {//Variable::string_LPCWSTR_("ABC");
        return wstring(Str.begin(), Str.end()).c_str();
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    struct Vector3//用来获取多个数据 XYZ
    {
        constexpr Vector3(const float x = 0.f, const float y = 0.f, const float z = 0.f) noexcept :x(x), y(y), z(z) { }
        constexpr const Vector3 operator-(const Vector3 other) const noexcept
        {
            return Vector3{ x - other.x, y - other.y, z - other.z };
        }
        constexpr const Vector3 operator+(const Vector3 other) const noexcept
        {
            return Vector3{ x + other.x, y + other.y, z + other.z };
        }
        constexpr const Vector3 operator/(const float factor) const noexcept
        {
            return Vector3{ x / factor, y / factor, z / factor };
        }
        constexpr const Vector3 operator*(const float factor) const noexcept
        {
            return Vector3{ x * factor, y * factor, z * factor };
        }
        constexpr const Vector3 ToAngle() const noexcept
        {
            return Vector3{ atan2(-z, hypot(x, y)) * (180.0f / (float)acos(-1)),atan2(y, x) * (180.0f / (float)acos(-1)),0.0f };
        }
        constexpr const bool IsZero() const noexcept { return x == 0.f && y == 0.f && z == 0.f; }
        float x, y, z;
    };
    constexpr Vector3 CalculateAngle(const Vector3 localPosition, const Vector3 enemyPosition, const Vector3 viewAngles) noexcept
    {
        return ((enemyPosition - localPosition).ToAngle() - viewAngles);
    }
    struct view_matrix_t
    {
        float* operator[](int index) { return matrix[index]; }
        float matrix[4][4];
    };
    Vector3 WorldToScreen(int X, int Y, Vector3 pos, view_matrix_t matrix) noexcept
    {
        float _x = matrix[0][0] * pos.x + matrix[0][1] * pos.y + matrix[0][2] * pos.z + matrix[0][3];
        float _y = matrix[1][0] * pos.x + matrix[1][1] * pos.y + matrix[1][2] * pos.z + matrix[1][3];
        float w = matrix[3][0] * pos.x + matrix[3][1] * pos.y + matrix[3][2] * pos.z + matrix[3][3];
        float inv_w = 1.f / w;
        _x *= inv_w; _y *= inv_w;
        float x = X * .5f; float y = Y * .5f;
        x += 0.5f * _x * X + 0.5f; y -= 0.5f * _y * Y + 0.5f;
        if (w >= 0.01f)return { x,y,w };
        else return { 99999,99999,99999 };
    }
    template<class A>
    Vector3 Animation_AVec(Vector3 To_VAlue, const float Speed = 10) noexcept
    {
        static Vector3 ReturnValue = To_VAlue;
        if (To_VAlue.x > ReturnValue.x)ReturnValue.x += (To_VAlue.x - ReturnValue.x) / Speed;
        else if (To_VAlue.x < ReturnValue.x)ReturnValue.x -= (ReturnValue.x - To_VAlue.x) / Speed;
        if (To_VAlue.y > ReturnValue.y)ReturnValue.y += (To_VAlue.y - ReturnValue.y) / Speed;
        else if (To_VAlue.y < ReturnValue.y)ReturnValue.y -= (ReturnValue.y - To_VAlue.y) / Speed;
        if (To_VAlue.z > ReturnValue.z)ReturnValue.z += (To_VAlue.z - ReturnValue.z) / Speed;
        else if (To_VAlue.z < ReturnValue.z)ReturnValue.z -= (ReturnValue.z - To_VAlue.z) / Speed;
        return ReturnValue;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    vector<float> 角度转坐标(float 距离, float 角度) noexcept//角度转坐标2D(用于绘制或是计算)
    {//Variable::角度转坐标(150, 180);
        float radian = ((角度) * 3.1415926535) / 180;
        return { 距离 * sin(radian),距离 * cos(radian) };
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    template<class A>//防止冲突
    float Animation(float 目标值, const float Speed = 10) noexcept//快到慢动画 Speed是百分比
    {//Variable::Animation<class Fast_to_Slow>(255);
        static float ReturnValue = 目标值;
        if (目标值 > ReturnValue)ReturnValue += (目标值 - ReturnValue) / Speed;
        else if (目标值 < ReturnValue)ReturnValue -= (ReturnValue - 目标值) / Speed;
        return ReturnValue;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    vector<int> Color_RE(vector<int> Color) noexcept//转换反色
    {//Variable::Color_RE({ 255,255,255 });
        return { 255 - Color[0],255 - Color[1], 255 - Color[2] };
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    string Hex_String(int str) noexcept//10进制整数转换16进制字符转
    {//Variable::Hex_String(16); return 10
        ostringstream ss;
        ss << hex << str;
        auto Return_Value = ss.str();
        transform(Return_Value.begin(), Return_Value.end(), Return_Value.begin(), toupper);
        return Return_Value;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    string Float_Precision(float m_fValue, short Pre = 2) noexcept//保留小数值 (防止字符串过长)
    {//Variable::Float_Precision(0.12344); return 0.12
        stringstream Float_Value__;
        Float_Value__ << fixed << setprecision(Pre) << m_fValue;
        Float_Value__ >> m_fValue;
        return Float_Value__.str();
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
    BOOL String_Find(string Str, string Find_Str) noexcept//查找字符串内是否有特定字符串
    {//Variable::String_Find("Hello Bro", "Hello"); return true
        if (Str.find(Find_Str) != string::npos)return true;
        else return false;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------------
}
namespace EasyGUI
{
    /*
    int main()
    {
        ShowWindow(GetConsoleWindow(), true);//Show Console Window
        EasyGUI::EasyGUI GUI_Variable;//Initialize GUI variables
        GUI_Variable.Window_Create(590, 360, "Test Windows", true);
        GUI_Variable.Window_SetAlpha(250);
        while (1)
        {
            static BOOL UI_Checkbox = false;
            static int UI_Slider_int = 5;
            static float UI_Slider_float = 5;
            static BOOL UI_Button = false;
            static BOOL UI_Button_Small = false;
            static int UI_KeySelector = 4;
            static vector<int> UI_ColorSelector = { 255,255,255 };
            static vector<float> UI_PosSelector = { 0.23,100,1000 };
            static int UI_PanelSelector = 0;
            EasyGUI::EasyGUI_IO GUI_IO = GUI_Variable.Get_IO();//Get Global Input/Output Value
            if (!GUI_Variable.Window_Move())//MoveWindow Funtion (You must add!! cause it have  MessageLoop)
            {
                GUI_Variable.GUI_BackGround();//BackGround
                GUI_Variable.GUI_Block_Panel(30, 30, 100, 300, "Panel", { "Panel 1","Panel 2","Panel 3" }, UI_PanelSelector);
                if (UI_PanelSelector == 0)
                {
                    const auto Block = GUI_Variable.GUI_Block(160, 30, 300, "Block");//Block
                    GUI_Variable.GUI_Checkbox(Block, 1, "This is a Checkbox.", UI_Checkbox);
                    GUI_Variable.GUI_KeySelector<class A_1>(Block, 1, UI_KeySelector);
                    GUI_Variable.GUI_Slider<int, class A_2>(Block, 2, "Slider int", 0, 10, UI_Slider_int);
                    GUI_Variable.GUI_Slider<float, class A_3>(Block, 3, "Slider float", 0, 10, UI_Slider_float);
                    GUI_Variable.GUI_Button(Block, 4, "Button", 90, UI_Button);
                    static auto ButtonClick = 0;
                    if (UI_Button || UI_Button_Small)ButtonClick++;
                    GUI_Variable.GUI_Text(Block, 5, "Button: " + to_string(ButtonClick));
                    GUI_Variable.GUI_Text(Block, 6, "Main Color");
                    GUI_Variable.GUI_ColorSelector(Block, 6, UI_ColorSelector);
                    GUI_Variable.Global_Set_EasyGUI_Color(UI_ColorSelector);
                    GUI_Variable.GUI_Text(Block, 7, "Pos");
                    GUI_Variable.GUI_PosSelector(Block, 7, UI_PosSelector);
                    GUI_Variable.GUI_Button_Small(Block, 2, UI_Button_Small);
                    GUI_Variable.GUI_Text(Block, 8, "FPS: " + to_string(GUI_IO.DrawFPS));
                    GUI_Variable.GUI_Tips(Block, 1, "Some Tips.");
                }
                GUI_Variable.Draw_GUI();
            }
        }
    }
    */
    //---------------------------------------------------------------------------------------------------------------------------------------------------------
    LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) noexcept//消息循环(用于解决窗口未响应问题)
    {
        switch (msg)
        {
        case WM_ERASEBKGND:return TRUE; break;
        case WM_PAINT:return TRUE; break;//一直重绘
        }
        return DefWindowProc(hwnd, msg, wp, lp);  //定义回调函数的返回值
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------
    struct EasyGUI_IO
    {
        int DrawFPS = 0;//绘制帧数
        HWND HWND = 0;//全局GUI窗口HWND
        HDC HDC = 0;//全局GUI窗口HDC
        string FontName = "";//全局GUI字体名字
        int FontSize = 0;//全局GUI字体大小
        vector<int> GUIColor = { 0,0,0 };//全局GUI主题色
        int GUIColor_Alpha = 0;//全局GUI主题色(透明度)
        vector<int> WindowPos = { 0,0 };//全局GUI窗口坐标
        vector<int> WindowSize = { 0,0 };//全局GUI窗口大小
        string WindowTitle = "";//全局GUI窗口标题
        vector<int> MousePos = { 0,0 };//GUI检测的鼠标坐标
    };
    //---------------------------------------------------------------------------------------------------------------------------------------------------------
    class EasyGUI
    {
    private:
        //-----------菜单风格
        string Global_EasyGUIFont = "Verdana";//全局字体
        int Global_EasyGUIFontSize = 13;//字体大小
        vector<int> Global_EasyGUIColor = { 255,255,255 };//全局主题颜色
        int Global_EasyGUIColor_Alpha = 250;
        //------------------
        HWND EasyGUI_WindowHWND = NULL;//GUI Window HWND
        HDC EasyGUI_WindowHDC = NULL;//GUI Window HDC
        vector<int> PaintSize;//DoubleBufferPaint Size 画布大小
        HDC EasyGUI_DrawHDC = NULL;//EasyGUI DrawHDC GUI要绘制的HDC
        POINT EasyGUI_MousePos;//EasyGUI鼠标坐标
        RECT EasyGUI_WindowPos;//EasyGUI窗口坐标
        int EasyGUI_FPS = 0;//EasyGUI绘制帧数
        //------------------
        BOOL Mouse_Block_ = false;
        BOOL Mouse_Slider_ = false;
        //---------------------------------------------------------------------
        void In_DrawRect(int X, int Y, int XX, int YY, vector<int>Color) noexcept//绘制矩形 (方便制作GUI)
        {
            //------------------------初始化
            TRIVERTEX vert[2]; GRADIENT_RECT gRect;
            vert[0].Alpha = 0x0000; vert[1].Alpha = 0x0000;
            gRect.UpperLeft = 0; gRect.LowerRight = 1;
            //------------------------
            const COLORREF Color_ = RGB(Color[0], Color[1], Color[2]);
            vert[0].x = X;
            vert[0].y = Y;
            vert[1].x = X + XX;
            vert[1].y = Y + YY;
            vert[0].Red = GetRValue(Color_) << 8;
            vert[0].Green = GetGValue(Color_) << 8;
            vert[0].Blue = GetBValue(Color_) << 8;
            vert[1].Red = GetRValue(Color_) << 8;
            vert[1].Green = GetGValue(Color_) << 8;
            vert[1].Blue = GetBValue(Color_) << 8;
            GradientFill(EasyGUI_DrawHDC, vert, 2, &gRect, 1, GRADIENT_FILL_RECT_V);
        }
        //---------------------------------------------------------------------
        void In_DrawGradientRect(int X, int Y, int XX, int YY, vector<int>Color_1, vector<int> Color_2, BOOL Draw_Style = false) noexcept//绘制渐变矩形 (方便制作GUI)
        {//false = 横向; true = 竖向
            //------------------------初始化
            TRIVERTEX vert[2]; GRADIENT_RECT gRect;
            vert[0].Alpha = 0x0000; vert[1].Alpha = 0x0000;
            gRect.UpperLeft = 0; gRect.LowerRight = 1;
            //------------------------
            const COLORREF Color1 = RGB(Color_1[0], Color_1[1], Color_1[2]);
            const COLORREF Color2 = RGB(Color_2[0], Color_2[1], Color_2[2]);
            vert[0].x = X;
            vert[0].y = Y;
            vert[1].x = X + XX;
            vert[1].y = Y + YY;
            vert[0].Red = GetRValue(Color1) << 8;
            vert[0].Green = GetGValue(Color1) << 8;
            vert[0].Blue = GetBValue(Color1) << 8;
            vert[1].Red = GetRValue(Color2) << 8;
            vert[1].Green = GetGValue(Color2) << 8;
            vert[1].Blue = GetBValue(Color2) << 8;
            if (Draw_Style)GradientFill(EasyGUI_DrawHDC, vert, 2, &gRect, 1, GRADIENT_FILL_RECT_V);
            else  GradientFill(EasyGUI_DrawHDC, vert, 2, &gRect, 1, GRADIENT_FILL_RECT_H);
        }
        //---------------------------------------------------------------------
        void In_DrawString(int X, int Y, string String, vector<int> TextColor, string Fount_Name, short Fount_Size, short Font_Width = FW_NORMAL, BOOL AntiAlias = true) noexcept//绘制文字 (方便制作GUI)
        {
            const HDC StringHdc = EasyGUI_DrawHDC;
            HGDIOBJ FontPen;
            if (AntiAlias)FontPen = SelectObject(StringHdc, CreateFontA(Fount_Size, 0, 0, 0, Font_Width, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, Fount_Name.c_str()));
            else FontPen = SelectObject(StringHdc, CreateFontA(Fount_Size, 0, 0, 0, Font_Width, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, NONANTIALIASED_QUALITY, FF_DONTCARE, Fount_Name.c_str()));
            SetTextColor(StringHdc, RGB(TextColor[0], TextColor[1], TextColor[2]));//文字颜色
            SetBkMode(StringHdc, TRANSPARENT);//背景透明
            TextOutA(StringHdc, X, Y, String.c_str(), strlen(String.c_str()));
            DeleteObject(FontPen);
        }
        void In_DrawString_Simple(int X, int Y, string String, vector<int> TextColor = { 255,255,255 }) noexcept//绘制简单文字 (方便制作GUI)
        {
            const HDC StringHdc = EasyGUI_DrawHDC;
            HGDIOBJ FontPen = SelectObject(StringHdc, CreateFontA(12, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, NONANTIALIASED_QUALITY, FF_DONTCARE, "Small Fonts"));
            SetBkMode(StringHdc, TRANSPARENT);//背景透明
            SetTextColor(StringHdc, RGB(0, 0, 0));//文字颜色
            TextOutA(StringHdc, X + 1, Y + 1, String.c_str(), strlen(String.c_str()));
            TextOutA(StringHdc, X - 1, Y - 1, String.c_str(), strlen(String.c_str()));
            TextOutA(StringHdc, X + 1, Y - 1, String.c_str(), strlen(String.c_str()));
            TextOutA(StringHdc, X - 1, Y + 1, String.c_str(), strlen(String.c_str()));
            TextOutA(StringHdc, X + 1, Y, String.c_str(), strlen(String.c_str()));
            TextOutA(StringHdc, X - 1, Y, String.c_str(), strlen(String.c_str()));
            TextOutA(StringHdc, X, Y - 1, String.c_str(), strlen(String.c_str()));
            TextOutA(StringHdc, X, Y + 1, String.c_str(), strlen(String.c_str()));
            SetTextColor(StringHdc, RGB(TextColor[0], TextColor[1], TextColor[2]));//文字颜色
            TextOutA(StringHdc, X, Y, String.c_str(), strlen(String.c_str()));
            DeleteObject(FontPen);
        }
        //---------------------------------------------------------------------
        string In_VKCode_to_String(int VK_code) noexcept//通过VK键码获取按键名称
        {
            switch (VK_code)
            {
            case 0x01: return "[M1]";//鼠标左键
            case 0x02: return "[M2]";//鼠标右键
            case 0x03: return "[CAN]";//鼠标中断处理
            case 0x04: return "[M3]";//鼠标中键
            case 0x05: return "[M4]";//鼠标侧键下
            case 0x06: return "[M5]";//鼠标侧键上
            case 0x07: return "[NONE]";
            case 0x08: return "[BACK]";
            case 0x09: return "[TAB]";
            case 0x0C: return "[CLE]";
            case 0x0D: return "[ENT]";
            case 0x10: return "[SHF]";
            case 0x11: return "[CLR]";
            case 0x12: return "[ALT]";
            case 0x13: return "[PAU]";
            case 0x14: return "[CAP]";
            case 0x15: return "[KAN]";
            case 0x16: return "[KAN]";
            case 0x17: return "[JUN]";
            case 0x18: return "[FIN]";
            case 0x19: return "[HAN]";
            case 0x1B: return "[ESC]";
            case 0x1C: return "[CON]";
            case 0x1D: return "[NON]";
            case 0x1E: return "[ACC]";
            case 0x1F: return "[MOD]";
            case 0x20: return "[SPA]";
            case 0x21: return "[PRI]";
            case 0x22: return "[NEXT]";
            case 0x23: return "[END]";
            case 0x24: return "[HOME]";
            case 0x25: return "[LEFT]";
            case 0x26: return "[UP]";
            case 0x27: return "[RIGT]";
            case 0x28: return "[DOWN]";
            case 0x29: return "[SEL]";
            case 0x2A: return "[PRI]";
            case 0x2B: return "[EXE]";
            case 0x2C: return "[SNAP]";
            case 0x2D: return "[INS]";
            case 0x2E: return "[DEL]";
            case 0x2F: return "[HELP]";
            case 0x30: return "[0]";
            case 0x31: return "[1]";
            case 0x32: return "[2]";
            case 0x33: return "[3]";
            case 0x34: return "[4]";
            case 0x35: return "[5]";
            case 0x36: return "[6]";
            case 0x37: return "[7]";
            case 0x38: return "[8]";
            case 0x39: return "[9]";
            case 0x41: return "[A]";
            case 0x42: return "[B]";
            case 0x43: return "[C]";
            case 0x44: return "[D]";
            case 0x45: return "[E]";
            case 0x46: return "[F]";
            case 0x47: return "[G]";
            case 0x48: return "[H]";
            case 0x49: return "[I]";
            case 0x4A: return "[J]";
            case 0x4B: return "[K]";
            case 0x4C: return "[L]";
            case 0x4D: return "[M]";
            case 0x4E: return "[N]";
            case 0x4F: return "[O]";
            case 0x50: return "[P]";
            case 0x51: return "[Q]";
            case 0x52: return "[R]";
            case 0x53: return "[S]";
            case 0x54: return "[T]";
            case 0x55: return "[U]";
            case 0x56: return "[V]";
            case 0x57: return "[W]";
            case 0x58: return "[X]";
            case 0x59: return "[Y]";
            case 0x5A: return "[Z]";
            case 0x5B: return "[WIN]";//L
            case 0x5C: return "[WIN]";//R
            case 0x5D: return "[APP]";
            case 0x5F: return "[SLP]";
            case 0x60: return "[0]";
            case 0x61: return "[1]";
            case 0x62: return "[2]";
            case 0x63: return "[3]";
            case 0x64: return "[4]";
            case 0x65: return "[5]";
            case 0x66: return "[6]";
            case 0x67: return "[7]";
            case 0x68: return "[8]";
            case 0x69: return "[9]";
            case 0x6A: return "[*]";
            case 0x6B: return "[+]";
            case 0x6C: return "[SEP]";
            case 0x6D: return "[-]";
            case 0x6E: return "[.]";
            case 0x6F: return "[/]";
            case 0x70: return "[F1]";
            case 0x71: return "[F2]";
            case 0x72: return "[F3]";
            case 0x73: return "[F4]";
            case 0x74: return "[F5]";
            case 0x75: return "[F6]";
            case 0x76: return "[F7]";
            case 0x77: return "[F8]";
            case 0x78: return "[F9]";
            case 0x79: return "[F10]";
            case 0x7A: return "[F11]";
            case 0x7B: return "[F12]";
            case 0x7C: return "[F13]";
            case 0x7D: return "[F14]";
            case 0x7E: return "[F15]";
            case 0x7F: return "[F16]";
            case 0x80: return "[F17]";
            case 0x81: return "[F18]";
            case 0x82: return "[F19]";
            case 0x83: return "[F20]";
            case 0x84: return "[F21]";
            case 0x85: return "[F22]";
            case 0x86: return "[F23]";
            case 0x87: return "[F24]";
            case 0x90: return "[NUM]";
            case 0x91: return "[SCR]";
            case 0xA0: return "[SHF]";//L
            case 0xA1: return "[SHF]";//R
            case 0xA2: return "[CLR]";//L
            case 0xA3: return "[CLR]";//R
            case 0xA4: return "[ALT]";//L
            case 0xA5: return "[ALT]";//R
            case 0xC0: return "[~]";
            case 0xBC: return "[,]";
            case 0xBE: return "[.]";
            case 0xBF: return "[/]";
            case 0xBA: return "[;]";
            case 0xDE: return "[']";
            case 0xDB: return "[[]";
            case 0xDD: return "[]]";
            case 0xDC: return "[\]";
            default: return "[" + to_string(VK_code) + "]";//如果什么都不是直接返回编码
            }
        }
        //---------------------------------------------------------------------
        BOOL In_MouseEventJudgment(int X, int Y, int XX, int YY) noexcept//检测鼠标坐标是否在窗口矩形坐标内
        {
            if (!(EasyGUI_MousePos.x >= EasyGUI_WindowPos.left && EasyGUI_MousePos.x <= EasyGUI_WindowPos.right && EasyGUI_MousePos.y >= EasyGUI_WindowPos.top && EasyGUI_MousePos.y <= EasyGUI_WindowPos.bottom))return false;//当指针不在窗口内
            if (EasyGUI_MousePos.x - EasyGUI_WindowPos.left >= X && EasyGUI_MousePos.x - EasyGUI_WindowPos.left <= X + XX && EasyGUI_MousePos.y - EasyGUI_WindowPos.top >= Y && EasyGUI_MousePos.y - EasyGUI_WindowPos.top <= Y + YY)return true;
            else return false;
        }
        //---------------------------------------------------------------------
    public:
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        void Global_Set_EasyGUI_Font(string Font) noexcept { Global_EasyGUIFont = Font; }//设置全局GUI字体
        void Global_Set_EasyGUI_FontSize(int Size) noexcept { Global_EasyGUIFontSize = Size; }//设置全局GUI字体大小
        void Global_Set_EasyGUI_Color(vector<int> GlobalColor) noexcept { Global_EasyGUIColor = GlobalColor; }//设置全局主题颜色
        string Global_Get_EasyGUI_Font() noexcept { return Global_EasyGUIFont; }//获取全局GUI字体
        int Global_Get_EasyGUI_FontSize() noexcept { return Global_EasyGUIFontSize; }//获取全局GUI字体大小
        vector<int> Global_Get_EasyGUI_Color() noexcept { return Global_EasyGUIColor; }//获取全局主题颜色
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        vector<int> Initialization_Fast(int Window_Size_Y_ = 400) noexcept//快速初始化 (创建窗口 创建1区块!!! 为了调试减少代码量制作的单一函数)
        {
            /*Example****
            while (true)
            {
                static EasyGUI::EasyGUI GUI_Variable;//Initialize GUI variables
                const auto Block = GUI_Variable.Initialization_Fast();
                if (!GUI_Variable.Window_Move())
                {
                    //Your Controls Code***

                    GUI_Variable.Draw_GUI();
                }
            }
            */
            static BOOL In_OneSt__ = true;
            if (In_OneSt__)//创建窗口 || 只执行一次(由于之放置一个函数 则不用添加模板)
            {
                WNDCLASS RenderWindowM;
                memset(&RenderWindowM, 0, sizeof(RenderWindowM));
                RenderWindowM.style = CS_HREDRAW | CS_VREDRAW;
                RenderWindowM.lpfnWndProc = WndProc;//关联消息处理函数,告诉操作系统，如果有事件发生调用这个函数
                RenderWindowM.cbClsExtra = 0;
                RenderWindowM.cbWndExtra = 0;
                RenderWindowM.hInstance = GetModuleHandle(NULL);//实例句柄
                RenderWindowM.hIcon = LoadIcon(NULL, IDI_SHIELD);//图标
                RenderWindowM.hCursor = LoadCursor(NULL, IDC_ARROW);//光标样式
                RenderWindowM.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);//画刷
                RenderWindowM.lpszMenuName = NULL;
                RenderWindowM.lpszClassName = L"Test Windows  ";//窗口类的名称，操作系统根据类的名称做映射
                RegisterClass(&RenderWindowM);//将这个窗体注册（告诉）到操作系统
                const HWND hWnd = CreateWindowEx(WS_EX_LAYERED, L"Test Windows  ", L"Test Windows  ", WS_POPUP, GetSystemMetrics(SM_CXSCREEN) / 2 - 460 / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - Window_Size_Y_ / 2, 460, Window_Size_Y_, 0, 0, GetModuleHandle(NULL), 0);
                if (hWnd)//当创建成功
                {
                    UpdateWindow(hWnd);
                    ShowWindow(hWnd, SW_SHOW);
                    SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), Global_EasyGUIColor_Alpha, LWA_ALPHA);
                    EasyGUI_WindowHWND = hWnd;
                    EasyGUI_WindowHDC = GetWindowDC(hWnd);
                    //---------------------------------------双缓冲开始绘制
                    PaintSize = { 460 + 100, Window_Size_Y_ + 100 };//设定坐标上加上100缓冲区
                    EasyGUI_DrawHDC = CreateCompatibleDC(EasyGUI_WindowHDC);
                    SelectObject(EasyGUI_DrawHDC, (HBITMAP)CreateCompatibleBitmap(EasyGUI_WindowHDC, PaintSize[0], PaintSize[1]));
                    //---------------------------------------------
                }
                In_OneSt__ = false;
            }
            In_DrawRect(0, 0, 460, Window_Size_Y_, { 0,0,0 });
            In_DrawRect(1, 1, 460 - 2, Window_Size_Y_ - 2, { 60,60,60 });
            In_DrawRect(2, 2, 460 - 4, Window_Size_Y_ - 4, { 30,30,30 });
            In_DrawRect(5, 5, 460 - 10, Window_Size_Y_ - 10, { 60,60,60 });
            In_DrawGradientRect(6, 6, 460 - 12, Window_Size_Y_ - 12, { 5,5,5 }, { 30,30,30 }, true);//BackGround Gradient
            //---------------------------------------------------------------------------------------------------------------
            In_DrawRect(30, 30, 400, Window_Size_Y_ - 60, { 0,0,0 });//黑色外边框
            In_DrawRect(30 + 1, 30 + 1, 400 - 2, Window_Size_Y_ - 60 - 2, { 60,60,60 });//白色外边框
            In_DrawGradientRect(30 + 2, 30 + 2, 400 - 4, Window_Size_Y_ - 60 - 4, { 10,10,10 }, { Global_EasyGUIColor[0] / 10,Global_EasyGUIColor[1] / 10 ,Global_EasyGUIColor[2] / 10 }, true);//渐变背景
            In_DrawString(30 + 20 + 1, 30 - 7 + 1, "Block", { 50,50,50 }, "Small Fonts", 14, 700);
            In_DrawString(30 + 20, 30 - 7, "Block", { 200,200,200 }, "Small Fonts", 14, 700);
            if ((EasyGUI_MousePos.x - EasyGUI_WindowPos.left >= 30 && EasyGUI_MousePos.x - EasyGUI_WindowPos.left <= 30 + 400 && EasyGUI_MousePos.y - EasyGUI_WindowPos.top >= 30 && EasyGUI_MousePos.y - EasyGUI_WindowPos.top <= 30 + Window_Size_Y_ - 60) || !(EasyGUI_MousePos.x >= EasyGUI_WindowPos.left && EasyGUI_MousePos.x <= EasyGUI_WindowPos.right && EasyGUI_MousePos.y >= EasyGUI_WindowPos.top && EasyGUI_MousePos.y <= EasyGUI_WindowPos.bottom))Mouse_Block_ = true;
            return { 30,30 };
        }
        BOOL Window_Create(int Size_X, int Size_Y, string WindowTitle, BOOL IfTop = false) noexcept//创建窗口
        {
            static int 窗口类型 = WS_EX_LAYERED;
            if (IfTop)窗口类型 = WS_EX_TOPMOST | WS_EX_LAYERED;//WS_EX_TOOLWINDOW
            WNDCLASS RenderWindowM;
            memset(&RenderWindowM, 0, sizeof(RenderWindowM));
            RenderWindowM.style = CS_HREDRAW | CS_VREDRAW;
            RenderWindowM.lpfnWndProc = WndProc;//关联消息处理函数,告诉操作系统，如果有事件发生调用这个函数
            RenderWindowM.cbClsExtra = 0;
            RenderWindowM.cbWndExtra = 0;
            RenderWindowM.hInstance = GetModuleHandle(NULL);//实例句柄
            RenderWindowM.hIcon = LoadIcon(NULL, IDI_SHIELD);//图标
            RenderWindowM.hCursor = LoadCursor(NULL, IDC_ARROW);//光标样式
            RenderWindowM.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);//画刷
            RenderWindowM.lpszMenuName = NULL;
            RenderWindowM.lpszClassName = wstring(WindowTitle.begin(), WindowTitle.end()).c_str();//窗口类的名称，操作系统根据类的名称做映射
            RegisterClass(&RenderWindowM);//将这个窗体注册（告诉）到操作系统
            const HWND hWnd = CreateWindowEx(窗口类型, wstring(WindowTitle.begin(), WindowTitle.end()).c_str(), wstring(WindowTitle.begin(), WindowTitle.end()).c_str(), WS_POPUP, GetSystemMetrics(SM_CXSCREEN) / 2 - Size_X / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - Size_Y / 2, Size_X, Size_Y, 0, 0, GetModuleHandle(NULL), 0);
            if (hWnd)//当创建成功
            {
                UpdateWindow(hWnd);
                ShowWindow(hWnd, SW_SHOW);
                SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), Global_EasyGUIColor_Alpha, LWA_ALPHA);
                EasyGUI_WindowHWND = hWnd;
                EasyGUI_WindowHDC = GetWindowDC(hWnd);
                //---------------------------------------双缓冲开始绘制
                PaintSize = { Size_X + 100,Size_Y + 100 };//设定坐标上加上100缓冲区
                EasyGUI_DrawHDC = CreateCompatibleDC(EasyGUI_WindowHDC);
                SelectObject(EasyGUI_DrawHDC, (HBITMAP)CreateCompatibleBitmap(EasyGUI_WindowHDC, PaintSize[0], PaintSize[1]));
                //---------------------------------------------
                return true;
            }
            else return false;
        }
        void Draw_GUI(BOOL ReverseColor = false) noexcept//双缓冲结束绘制 (绘制最终返回图片)
        {
            BitBlt(EasyGUI_WindowHDC, 0, 0, PaintSize[0], PaintSize[1], EasyGUI_DrawHDC, 0, 0, SRCCOPY);
            if (ReverseColor)BitBlt(EasyGUI_WindowHDC, 0, 0, PaintSize[0], PaintSize[1], EasyGUI_DrawHDC, 0, 0, PATINVERT);//反转颜色
            //--------------------------------消息循环
            MSG msg = { 0 };
            if (GetMessage(&msg, 0, 0, 0))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            //--------------------------------帧数计算
            static int m_fps = 0; m_fps++;
            const int Tick = GetTickCount(); static int Tick_Old = Tick;
            if (Tick >= Tick_Old + 1000)//每1秒刷新 (计时器)
            {
                Tick_Old = Tick;
                EasyGUI_FPS = m_fps;
                m_fps = 0;
            }
            //----------------------------------------
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        HWND Window_HWND() noexcept { return EasyGUI_WindowHWND; }//获取GUI窗口HWND
        HDC Window_HDC() noexcept { return EasyGUI_DrawHDC; }//获取GUI窗口HDC
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        void Window_SetPos(vector<int> WindowPos) noexcept//修改GUI窗口坐标
        {
            RECT m_Windowrect; GetWindowRect(EasyGUI_WindowHWND, &m_Windowrect);
            MoveWindow(EasyGUI_WindowHWND, WindowPos[0], WindowPos[1], m_Windowrect.right - m_Windowrect.left, m_Windowrect.bottom - m_Windowrect.top, TRUE);
        }
        vector<int> Window_GetPos() noexcept//获取GUI窗口坐标
        {
            RECT m_Windowrect; GetWindowRect(EasyGUI_WindowHWND, &m_Windowrect);
            return { m_Windowrect.left ,m_Windowrect.top };
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        void Window_SetSize(vector<int> WindowSize) noexcept//修改GUI窗口大小
        {
            RECT m_Windowrect; GetWindowRect(EasyGUI_WindowHWND, &m_Windowrect);
            MoveWindow(EasyGUI_WindowHWND, m_Windowrect.left, m_Windowrect.top, WindowSize[0], WindowSize[1], TRUE);
        }
        vector<int> Window_GetSize() noexcept//获取GUI窗口大小
        {
            RECT m_Windowrect; GetWindowRect(EasyGUI_WindowHWND, &m_Windowrect);
            return { m_Windowrect.right - m_Windowrect.left ,m_Windowrect.bottom - m_Windowrect.top };
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        void Window_Show() noexcept//修改GUI窗口为最前端
        {
            SetForegroundWindow(EasyGUI_WindowHWND);
            ShowWindow(EasyGUI_WindowHWND, true);
        }
        void Window_Hide() noexcept//隐藏GUI窗口
        {
            ShowWindow(EasyGUI_WindowHWND, false);
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        void Window_SetAlpha(short WindowAlpha) noexcept//修改GUI窗口整体阿尔法通道
        {
            if (WindowAlpha >= 255)WindowAlpha = 255; else if (WindowAlpha <= 0)WindowAlpha = 0;
            SetLayeredWindowAttributes(EasyGUI_WindowHWND, RGB(0, 0, 0), WindowAlpha, LWA_ALPHA);
            Global_EasyGUIColor_Alpha = WindowAlpha;
        }
        int Window_GetAlpha() noexcept//获取GUI窗口整体阿尔法通道
        {
            return Global_EasyGUIColor_Alpha;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        void Window_SetTitle(string WindowTitle) noexcept//修改GUI窗口标题
        {
            SetWindowTextA(EasyGUI_WindowHWND, WindowTitle.c_str());//修改窗口标题
        }
        const char* Window_GetTitle() noexcept//获取GUI窗口标题
        {
            CHAR pszMem[MAX_PATH] = { 0 }; GetWindowTextA(EasyGUI_WindowHWND, pszMem, GetWindowTextLength(EasyGUI_WindowHWND) + 1);
            return pszMem;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        BOOL Window_Move(BOOL Window_Move_ = true) noexcept//移动GUI窗口（放在循环(不用放等待函数和消息循环函数) 非事件）
        {
            //--------------------------------消息循环
            MSG msg = { 0 };
            if (GetMessage(&msg, 0, 0, 0))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            //---------------------------------------
            GetCursorPos(&EasyGUI_MousePos); GetWindowRect(EasyGUI_WindowHWND, &EasyGUI_WindowPos);//刷新坐标
            static BOOL 防止脱离 = false;
            static int OldX; static int OldY;//按下时坐标
            static BOOL 保存鼠标坐标 = false;
            if (GetForegroundWindow() == EasyGUI_WindowHWND)//检测窗口是否在最前端
            {
                if (!Mouse_Block_ && GetAsyncKeyState(VK_LBUTTON) && !防止脱离 && Window_Move_)//当鼠标指针不在Block上则可以移动窗口
                {
                    if (保存鼠标坐标)
                    {
                        OldX = (EasyGUI_MousePos.x - EasyGUI_WindowPos.left);
                        OldY = (EasyGUI_MousePos.y - EasyGUI_WindowPos.top);
                        保存鼠标坐标 = false;
                    }
                    MoveWindow(EasyGUI_WindowHWND, EasyGUI_MousePos.x - OldX, EasyGUI_MousePos.y - OldY, EasyGUI_WindowPos.right - EasyGUI_WindowPos.left, EasyGUI_WindowPos.bottom - EasyGUI_WindowPos.top, TRUE);//移动窗口到鼠标坐标
                    防止脱离 = true;
                }
                else if (防止脱离 && GetAsyncKeyState(VK_LBUTTON))
                {
                    MoveWindow(EasyGUI_WindowHWND, EasyGUI_MousePos.x - OldX, EasyGUI_MousePos.y - OldY, EasyGUI_WindowPos.right - EasyGUI_WindowPos.left, EasyGUI_WindowPos.bottom - EasyGUI_WindowPos.top, TRUE);//移动窗口到鼠标坐标
                    this_thread::sleep_for(chrono::nanoseconds(20));//降低CPU占用 纳秒单位等待函数
                    Mouse_Block_ = true;
                    return true;
                }
                else {
                    防止脱离 = false;
                    保存鼠标坐标 = true;
                    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)Sleep(1);
                    else Sleep(5);//降低CPU占用
                    Mouse_Block_ = false;
                    return false;
                }
            }
            else Sleep(20); return false;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        EasyGUI_IO Get_IO() noexcept//获取GUI数据
        {
            struct EasyGUI_IO IO;
            IO.DrawFPS = EasyGUI_FPS;
            IO.HWND = EasyGUI_WindowHWND;
            IO.HDC = EasyGUI_DrawHDC;
            IO.FontName = Global_EasyGUIFont;
            IO.FontSize = Global_EasyGUIFontSize;
            IO.GUIColor = Global_EasyGUIColor;
            IO.GUIColor_Alpha = Global_EasyGUIColor_Alpha;
            RECT Windowrect; GetWindowRect(EasyGUI_WindowHWND, &Windowrect);
            IO.WindowPos = { Windowrect.left ,Windowrect.top };
            IO.WindowSize = { Windowrect.right - Windowrect.left ,Windowrect.bottom - Windowrect.top };
            CHAR Windowtitle[MAX_PATH] = { 0 }; GetWindowTextA(EasyGUI_WindowHWND, Windowtitle, GetWindowTextLength(EasyGUI_WindowHWND) + 1);
            IO.WindowTitle = Windowtitle;
            IO.MousePos = { EasyGUI_MousePos.x,EasyGUI_MousePos.y };
            return IO;
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------以下是控件函数*
        void GUI_BackGround(short BackGround_StyleCode = 0) noexcept//绘制GUI窗口背景
        {
            CHAR pszMem[MAX_PATH] = { 0 }; GetWindowTextA(EasyGUI_WindowHWND, pszMem, GetWindowTextLength(EasyGUI_WindowHWND) + 1);
            const short XX = EasyGUI_WindowPos.right - EasyGUI_WindowPos.left; const short YY = EasyGUI_WindowPos.bottom - EasyGUI_WindowPos.top;
            vector<int> 彩虹条颜色 = { 0,255,255,255,0,255,255,255,0 };
            vector<int> 主题颜色 = { 0,0,0,60,60,60,30,30,30,15,15,15,5,5,5,30,30,30 };
            if (BackGround_StyleCode == 0)//毛都没有
            {
                彩虹条颜色 = { 16,16,16,16,16,16,16,16,16 };
                主题颜色 = { 0,0,0,60,60,60,30,30,30,15,15,15,15,15,15,Global_EasyGUIColor[0] / 7,Global_EasyGUIColor[1] / 7 ,Global_EasyGUIColor[2] / 7 };
            }
            else if (BackGround_StyleCode == 1337)//仿
            {
                彩虹条颜色 = { 100,255,255,255,100,255,255,255,100 };
                主题颜色 = { 0,0,0,60,60,60,30,30,30,15,15,15,5,5,5,30,30,30 };
            }
            else if (BackGround_StyleCode == 1367)//仿2
            {
                彩虹条颜色 = { 0,255,255,255,0,255,255,255,0 };
                主题颜色 = { 0,0,0,60,60,60,30,30,30,15,15,15,3,3,3,30,30,30 };
            }
            else if (BackGround_StyleCode == 1368)//彩色变色渐变条*****************
            {
                彩虹条颜色 = {
                    (int)floor(sin((float)GetTickCount64() / 3500 * 2 + 3) * 127 + 128),
                    (int)floor(sin((float)GetTickCount64() / 3500 * 2 + 2 + 3) * 127 + 128),
                    (int)floor(sin((float)GetTickCount64() / 3500 * 2 + 4 + 3) * 127 + 128),
                    (int)floor(sin((float)GetTickCount64() / 3500 * 2 + 2) * 127 + 128),
                    (int)floor(sin((float)GetTickCount64() / 3500 * 2 + 2 + 2) * 127 + 128),
                    (int)floor(sin((float)GetTickCount64() / 3500 * 2 + 4 + 2) * 127 + 128),
                    (int)floor(sin((float)GetTickCount64() / 3500 * 2 + 1) * 127 + 128),
                    (int)floor(sin((float)GetTickCount64() / 3500 * 2 + 2 + 1) * 127 + 128),
                    (int)floor(sin((float)GetTickCount64() / 3500 * 2 + 4 + 1) * 127 + 128),
                };
                主题颜色 = { 0,0,0,60,60,60,30,30,30,15,15,15,3,3,3, Global_EasyGUIColor[0] / 7,Global_EasyGUIColor[1] / 7 ,Global_EasyGUIColor[2] / 7 };
                Global_EasyGUIColor = { 彩虹条颜色[3],彩虹条颜色[4], 彩虹条颜色[5] };
            }
            else if (BackGround_StyleCode == 1369)//主题色渐变条*****************
            {
                const vector<float> Sins = { sin((float)GetTickCount64() / 800 + 0), sin((float)GetTickCount64() / 800 + 1),sin((float)GetTickCount64() / 800 + 2) };
                彩虹条颜色 = {
                    (int)(Sins[2] * Global_EasyGUIColor[0] / 2 + Global_EasyGUIColor[0] / 2),
                    (int)(Sins[2] * Global_EasyGUIColor[1] / 2 + Global_EasyGUIColor[1] / 2),
                    (int)(Sins[2] * Global_EasyGUIColor[2] / 2 + Global_EasyGUIColor[2] / 2),
                    (int)(Sins[1] * Global_EasyGUIColor[0] / 2 + Global_EasyGUIColor[0] / 2),
                    (int)(Sins[1] * Global_EasyGUIColor[1] / 2 + Global_EasyGUIColor[1] / 2),
                    (int)(Sins[1] * Global_EasyGUIColor[2] / 2 + Global_EasyGUIColor[2] / 2),
                    (int)(Sins[0] * Global_EasyGUIColor[0] / 2 + Global_EasyGUIColor[0] / 2),
                    (int)(Sins[0] * Global_EasyGUIColor[1] / 2 + Global_EasyGUIColor[1] / 2),
                    (int)(Sins[0] * Global_EasyGUIColor[2] / 2 + Global_EasyGUIColor[2] / 2)
                };
                主题颜色 = { 0,0,0,60,60,60,30,30,30,15,15,15,0,0,0,Global_EasyGUIColor[0] / 7,Global_EasyGUIColor[1] / 7,Global_EasyGUIColor[2] / 7 };
            }
            In_DrawRect(0, 0, XX, YY, { 主题颜色[0], 主题颜色[1], 主题颜色[2] });
            In_DrawRect(1, 1, XX - 2, YY - 2, { 主题颜色[3], 主题颜色[4], 主题颜色[5] });
            In_DrawRect(2, 2, XX - 4, YY - 4, { 主题颜色[6], 主题颜色[7], 主题颜色[8] });
            In_DrawRect(5, 5, XX - 10, YY - 10, { 主题颜色[3], 主题颜色[4], 主题颜色[5] });
            In_DrawGradientRect(6, 6, XX - 12, YY - 12, { 主题颜色[12], 主题颜色[13], 主题颜色[14] }, { 主题颜色[15], 主题颜色[16], 主题颜色[17] }, true);//BackGround Gradient
            //-----------彩虹条
            if (BackGround_StyleCode != 0)//毛都没有
            {
                In_DrawGradientRect(7, 7, (XX - 7 * 2) / 2, 2, { 彩虹条颜色[0] / 2, 彩虹条颜色[1] / 2, 彩虹条颜色[2] / 2 }, { 彩虹条颜色[3] / 2, 彩虹条颜色[4] / 2, 彩虹条颜色[5] / 2 }, false);
                In_DrawGradientRect(7 + (XX - 7 * 2) / 2, 7, (XX - 7 * 2) / 2, 2, { 彩虹条颜色[3] / 2, 彩虹条颜色[4] / 2, 彩虹条颜色[5] / 2 }, { 彩虹条颜色[6] / 2, 彩虹条颜色[7] / 2, 彩虹条颜色[8] / 2 }, false);
                In_DrawGradientRect(7, 7, (XX - 7 * 2) / 2, 1, { 彩虹条颜色[0], 彩虹条颜色[1], 彩虹条颜色[2] }, { 彩虹条颜色[3], 彩虹条颜色[4], 彩虹条颜色[5] }, false);
                In_DrawGradientRect(7 + (XX - 7 * 2) / 2, 7, (XX - 7 * 2) / 2, 1, { 彩虹条颜色[3], 彩虹条颜色[4], 彩虹条颜色[5] }, { 彩虹条颜色[6], 彩虹条颜色[7], 彩虹条颜色[8] }, false);
            }
            else//排除特定背景标题
            {
                In_DrawString(8 + 1, YY - Global_EasyGUIFontSize - 5, pszMem, { 0,0,0 }, Global_EasyGUIFont, Global_EasyGUIFontSize);
                In_DrawString(8, YY - Global_EasyGUIFontSize - 5, pszMem, { Global_EasyGUIColor[0] / 2,Global_EasyGUIColor[1] / 2 ,Global_EasyGUIColor[2] / 2 }, Global_EasyGUIFont, Global_EasyGUIFontSize, 400);
            }
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        vector<int> GUI_Block(int X, int Y, int YY, string BlockText) noexcept//绘制按钮的区块
        {
            In_DrawRect(X, Y, 400, YY, { 0,0,0 });//黑色外边框
            In_DrawRect(X + 1, Y + 1, 400 - 2, YY - 2, { 60,60,60 });//白色外边框
            In_DrawGradientRect(X + 2, Y + 2, 400 - 4, YY - 4, { 10,10,10 }, { Global_EasyGUIColor[0] / 10,Global_EasyGUIColor[1] / 10 ,Global_EasyGUIColor[2] / 10 }, true);//渐变背景
            In_DrawString(X + 20 + 1, Y - 7 + 1, BlockText.c_str(), { 50,50,50 }, "Small Fonts", 14, 700);
            In_DrawString(X + 20, Y - 7, BlockText.c_str(), { 200,200,200 }, "Small Fonts", 14, 700);
            if ((EasyGUI_MousePos.x - EasyGUI_WindowPos.left >= X && EasyGUI_MousePos.x - EasyGUI_WindowPos.left <= X + 400 && EasyGUI_MousePos.y - EasyGUI_WindowPos.top >= Y && EasyGUI_MousePos.y - EasyGUI_WindowPos.top <= Y + YY) || !(EasyGUI_MousePos.x >= EasyGUI_WindowPos.left && EasyGUI_MousePos.x <= EasyGUI_WindowPos.right && EasyGUI_MousePos.y >= EasyGUI_WindowPos.top && EasyGUI_MousePos.y <= EasyGUI_WindowPos.bottom))Mouse_Block_ = true;
            return { X,Y };
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        int GUI_Block_Panel(int X, int Y, int XX, int YY, string BlockText, vector<string>BlockText_, int& m_In_B_Block) noexcept//区块_大区块选择器
        {
            In_DrawRect(X, Y, XX, YY, { 0,0,0 });//黑色外边框
            In_DrawRect(X + 1, Y + 1, XX - 2, YY - 2, { 60,60,60 });//白色外边框
            In_DrawGradientRect(X + 2, Y + 2, XX - 4, YY - 4, { Global_EasyGUIColor[0] / 8,Global_EasyGUIColor[1] / 8,Global_EasyGUIColor[2] / 8 }, { 10,10,10 }, true);//主题色渐变背景
            In_DrawString(X + 15 + 1, Y - 7 + 1, BlockText.c_str(), { 50,50,50 }, "Small Fonts", 14, 700);
            In_DrawString(X + 15, Y - 7, BlockText.c_str(), { 200,200,200 }, "Small Fonts", 14, 700);
            for (short i = 0; i < BlockText_.size(); ++i)//遍历坐标
            {
                const BOOL DetectMousePos = In_MouseEventJudgment(X, Y + 20 + 30 * i - 2 - 4, XX, 15 + 8);
                if (m_In_B_Block == i)
                {
                    In_DrawGradientRect(X + 2, Y + 20 + 30 * i - 5, XX - 4, 15 + 10, { 20,20,20 }, { Global_EasyGUIColor[0] / 3,Global_EasyGUIColor[1] / 3,Global_EasyGUIColor[2] / 3 });
                    In_DrawGradientRect(X + 2, Y + 20 + 30 * i - 4, XX - 4, 15 + 8, { Global_EasyGUIColor[0] / 3,Global_EasyGUIColor[1] / 3,Global_EasyGUIColor[2] / 3 }, { 20,20,20 });
                }
                else if (DetectMousePos)
                {
                    In_DrawGradientRect(X + 2, Y + 20 + 30 * i - 4, XX - 4, 15 + 8, { Global_EasyGUIColor[0] / 5,Global_EasyGUIColor[1] / 5,Global_EasyGUIColor[2] / 5 }, { 20,20,20 });
                    if (GetForegroundWindow() == EasyGUI_WindowHWND && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && !Mouse_Slider_)
                    {
                        m_In_B_Block = i;
                        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                    }
                }
                In_DrawString(X + 20 + 1, Y + 20 + 30 * i + 1, BlockText_[i], { 0,0,0 }, Global_EasyGUIFont, 15);
                In_DrawString(X + 20 + 1, Y + 20 + 30 * i, BlockText_[i], { 220,220,220 }, Global_EasyGUIFont, 15);
            }
            if ((EasyGUI_MousePos.x - EasyGUI_WindowPos.left >= X && EasyGUI_MousePos.x - EasyGUI_WindowPos.left <= X + XX && EasyGUI_MousePos.y - EasyGUI_WindowPos.top >= Y && EasyGUI_MousePos.y - EasyGUI_WindowPos.top <= Y + YY) || !(EasyGUI_MousePos.x >= EasyGUI_WindowPos.left && EasyGUI_MousePos.x <= EasyGUI_WindowPos.right && EasyGUI_MousePos.y >= EasyGUI_WindowPos.top && EasyGUI_MousePos.y <= EasyGUI_WindowPos.bottom))Mouse_Block_ = true;
            return m_In_B_Block;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        void GUI_Text(vector<int>BlockPos, short LineRow, string Text, vector<int> TextColor = { 200,200,200 }) noexcept//行文字
        {
            if (BlockPos[0] == 0 && BlockPos[1] == 0)return;//当无block则不进行绘制
            In_DrawString(BlockPos[0] + 22 + 30 + 1, BlockPos[1] - 3 + (30 * LineRow) + 1, Text, { 0,0,0 }, Global_EasyGUIFont, Global_EasyGUIFontSize);
            In_DrawString(BlockPos[0] + 22 + 30 + 1, BlockPos[1] - 3 + (30 * LineRow), Text, TextColor, Global_EasyGUIFont, Global_EasyGUIFontSize);
        }
        //--------------------------------------------------------------------------------------------------------------------------------------------------------
        BOOL GUI_Checkbox(vector<int>BlockPos, short LineRow, string Text, BOOL& m_CheckboxValue, vector<int> TextColor = { 200,200,200 }) noexcept//点击框
        {
            if (BlockPos[0] == 0 && BlockPos[1] == 0)return 0;//当无block则不进行绘制
            const BOOL DetectMousePos = In_MouseEventJudgment(BlockPos[0] + 30, BlockPos[1] + (30 * LineRow) - 2, 140, 12);//窗口检测
            if (GetForegroundWindow() == EasyGUI_WindowHWND && !Mouse_Slider_)//当最前端窗口为GUI窗口接收按钮事件
            {
                if (!m_CheckboxValue && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && DetectMousePos)
                {
                    m_CheckboxValue = true;
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                }
                else if (m_CheckboxValue && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && DetectMousePos)
                {
                    m_CheckboxValue = false;
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                }
            }
            In_DrawRect(BlockPos[0] - 1 + 30, BlockPos[1] - 1 + (30 * LineRow), 10, 10, { 0,0,0 });
            In_DrawString(BlockPos[0] + 22 + 30 + 1, BlockPos[1] - 3 + (30 * LineRow) + 1, Text, { 0,0,0 }, Global_EasyGUIFont, Global_EasyGUIFontSize);
            In_DrawString(BlockPos[0] + 22 + 30, BlockPos[1] - 3 + (30 * LineRow), Text, TextColor, Global_EasyGUIFont, Global_EasyGUIFontSize);
            if (m_CheckboxValue)//绘制
            {
                In_DrawGradientRect(BlockPos[0] - 1 + 30 + 1, BlockPos[1] - 1 + (30 * LineRow) + 1, 8, 8, Global_EasyGUIColor, { Global_EasyGUIColor[0] / 5,Global_EasyGUIColor[1] / 5,Global_EasyGUIColor[2] / 5 }, true);
                return true;
            }
            else {
                if (DetectMousePos)In_DrawGradientRect(BlockPos[0] - 1 + 30 + 1, BlockPos[1] - 1 + (30 * LineRow) + 1, 8, 8, { Global_EasyGUIColor[0] / 3,Global_EasyGUIColor[1] / 3,Global_EasyGUIColor[2] / 3 }, { 30,30,30 }, true);//移动到按钮按钮变亮
                else In_DrawGradientRect(BlockPos[0] - 1 + 30 + 1, BlockPos[1] - 1 + (30 * LineRow) + 1, 8, 8, { Global_EasyGUIColor[0] / 4,Global_EasyGUIColor[1] / 4,Global_EasyGUIColor[2] / 4 }, { 30,30,30 }, true);
                return false;
            }
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        BOOL GUI_Button(vector<int>BlockPos, short LineRow, string Text, short TextPos, BOOL& m_ButtonValue) noexcept//单击按钮
        {
            if (BlockPos[0] == 0 && BlockPos[1] == 0)return 0;//当无block则不进行绘制
            if (m_ButtonValue)Sleep(30);//更好地让其他循环线程接收
            const BOOL DetectMousePos = In_MouseEventJudgment(BlockPos[0] + 55, BlockPos[1] + (30 * LineRow) - 8, 230, 25);//窗口检测机制
            if (GetForegroundWindow() == EasyGUI_WindowHWND && !Mouse_Slider_)//当最前端窗口为GUI窗口接收按钮事件
            {
                if (!m_ButtonValue && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && DetectMousePos)
                {
                    m_ButtonValue = true;
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                }
                else m_ButtonValue = false;
            }
            In_DrawRect(BlockPos[0] - 2 + 55, BlockPos[1] - 2 + (30 * LineRow) - 8, 234, 29, { 0,0,0 });
            In_DrawRect(BlockPos[0] - 1 + 55, BlockPos[1] - 1 + (30 * LineRow) - 8, 232, 27, { 60,60,60 });
            if (DetectMousePos && !m_ButtonValue)In_DrawGradientRect(BlockPos[0] + 55, BlockPos[1] + (30 * LineRow) - 8, 230, 25, { Global_EasyGUIColor[0] / 5,Global_EasyGUIColor[1] / 5,Global_EasyGUIColor[2] / 5 }, { 20,20,20 }, true);
            else In_DrawGradientRect(BlockPos[0] + 55, BlockPos[1] + (30 * LineRow) - 8, 230, 25, { Global_EasyGUIColor[0] / 7,Global_EasyGUIColor[1] / 7,Global_EasyGUIColor[2] / 7 }, { 20,20,20 }, true);
            In_DrawString(BlockPos[0] + TextPos + 55 + 1, BlockPos[1] + 6 + (30 * LineRow) - 8 + 1, Text, { 0,0,0 }, Global_EasyGUIFont, Global_EasyGUIFontSize);
            In_DrawString(BlockPos[0] + TextPos + 55, BlockPos[1] + 6 + (30 * LineRow) - 8, Text, { 200,200,200 }, Global_EasyGUIFont, Global_EasyGUIFontSize);
            return m_ButtonValue;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        BOOL GUI_Button_Small(vector<int>BlockPos, short LineRow, BOOL& m_ButtonValue) noexcept//单击按钮(小号)
        {
            if (BlockPos[0] == 0 && BlockPos[1] == 0)return 0;//当无block则不进行绘制
            if (m_ButtonValue)Sleep(30);//更好地让其他循环线程接收
            const BOOL DetectMousePos = In_MouseEventJudgment(BlockPos[0] + 10, BlockPos[1] + (30 * LineRow) - 5, 13, 18);//窗口检测机制
            if (GetForegroundWindow() == EasyGUI_WindowHWND && !Mouse_Slider_)//当最前端窗口为GUI窗口接收按钮事件
            {
                if (!m_ButtonValue && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && DetectMousePos)
                {
                    m_ButtonValue = true;
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                }
                else m_ButtonValue = false;
            }
            In_DrawRect(BlockPos[0] - 2 + 10, BlockPos[1] - 2 + (30 * LineRow) - 5, 17, 22, { 0,0,0 });
            In_DrawRect(BlockPos[0] - 1 + 10, BlockPos[1] - 1 + (30 * LineRow) - 5, 15, 20, { 60,60,60 });
            if (DetectMousePos && !m_ButtonValue)In_DrawGradientRect(BlockPos[0] + 10, BlockPos[1] + (30 * LineRow) - 5, 13, 18, { Global_EasyGUIColor[0] / 5,Global_EasyGUIColor[1] / 5,Global_EasyGUIColor[2] / 5 }, { 20,20,20 }, true);
            else In_DrawGradientRect(BlockPos[0] + 10, BlockPos[1] + (30 * LineRow) - 5, 13, 18, { Global_EasyGUIColor[0] / 7,Global_EasyGUIColor[1] / 7,Global_EasyGUIColor[2] / 7 }, { 20,20,20 }, true);
            In_DrawString_Simple(BlockPos[0] + 10 + 2, BlockPos[1] + (30 * LineRow) - 1, "...", { 200,200,200 });
            return m_ButtonValue;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        template<class ValueClass, class CreateClassName>
        ValueClass GUI_Slider(vector<int>BlockPos, short LineRow, string Text, ValueClass StartValue, ValueClass EndValue, ValueClass& m_SliderValue, vector<int> TextColor = { 200,200,200 }) noexcept//滑条
        {
            if (BlockPos[0] == 0 && BlockPos[1] == 0)return 0;//当无block则不进行绘制
            const BOOL DetectMousePos = In_MouseEventJudgment(BlockPos[0] + 55, BlockPos[1] + (6 + 30 * LineRow), 230, 5);//窗口检测
            static BOOL OutSide = false;//防止指针脱落时失去控制力
            if (GetForegroundWindow() == EasyGUI_WindowHWND)//当最前端窗口为GUI窗口接收按钮事件
            {
                static const ValueClass ClassValueDetect = 0.1;
                if (DetectMousePos && GetAsyncKeyState(VK_LEFT) & 0x8000)//当鼠标移动到滑条上方 按键反馈事件
                {
                    if (ClassValueDetect == 0)m_SliderValue--;//检测是否是浮点值
                    else m_SliderValue -= 0.05;
                    keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
                }
                else if (DetectMousePos && GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                    if (ClassValueDetect == 0)m_SliderValue++;//检测是否是浮点值
                    else m_SliderValue += 0.05;
                    keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
                }
                if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && DetectMousePos && !OutSide)OutSide = true;
                if (OutSide && GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
                    m_SliderValue = ((EasyGUI_MousePos.x - BlockPos[0] - 54 - EasyGUI_WindowPos.left) * (EndValue - StartValue) / 230) + StartValue;
                    Mouse_Block_ = true; Mouse_Slider_ = true;
                }
                else if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000))
                {
                    OutSide = false; Mouse_Slider_ = false;
                }
            }
            int SliderPos = (float)(m_SliderValue - StartValue) / (float)(EndValue - StartValue) * 230;
            if (SliderPos >= 230)SliderPos = 230; else if (SliderPos <= 0) SliderPos = 0;
            if (m_SliderValue <= StartValue)m_SliderValue = StartValue; else if (m_SliderValue >= EndValue)m_SliderValue = EndValue;
            stringstream ss; ss << fixed << setprecision(4) << m_SliderValue; ss >> m_SliderValue;//只保留4位小数点后数
            In_DrawRect(BlockPos[0] - 1 + 55, BlockPos[1] - 1 + (6 + 30 * LineRow), 230 + 2, 7, { 0,0,0 });//黑色外边框
            if (DetectMousePos || OutSide)In_DrawGradientRect(BlockPos[0] + 55, BlockPos[1] + (6 + 30 * LineRow), 230, 5, { 30,30,30 }, { Global_EasyGUIColor[0] / 4,Global_EasyGUIColor[1] / 4,Global_EasyGUIColor[2] / 4 }, true);//滑条背景
            else In_DrawGradientRect(BlockPos[0] + 55, BlockPos[1] + (6 + 30 * LineRow), 230, 5, { 20,20,20 }, { Global_EasyGUIColor[0] / 5,Global_EasyGUIColor[1] / 5,Global_EasyGUIColor[2] / 5 }, true);
            In_DrawGradientRect(BlockPos[0] + 55, BlockPos[1] + (6 + 30 * LineRow), SliderPos, 5, Global_EasyGUIColor, { Global_EasyGUIColor[0] / 5,Global_EasyGUIColor[1] / 5,Global_EasyGUIColor[2] / 5 }, true);//滑条
            In_DrawString(BlockPos[0] + 55 + 1, BlockPos[1] - 16 + (6 + 30 * LineRow) + 1, Text, { 0,0,0 }, Global_EasyGUIFont, Global_EasyGUIFontSize);
            In_DrawString(BlockPos[0] + 55, BlockPos[1] - 16 + (6 + 30 * LineRow), Text, TextColor, Global_EasyGUIFont, Global_EasyGUIFontSize);
            In_DrawString_Simple(BlockPos[0] + 230 + 10 + 55, BlockPos[1] - 4 + (6 + 30 * LineRow), ss.str(), { 150,150,150 });//返回值绘制
            return m_SliderValue;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        template<class CreateClassName>
        int GUI_KeySelector(vector<int>BlockPos, short LineRow, int& m_KeySelectValue) noexcept//按键选取按钮
        {
            if (BlockPos[0] == 0 && BlockPos[1] == 0)return 0;//当无block则不进行绘制
            if (m_KeySelectValue == 0xCCCCCCCC)m_KeySelectValue = 0;//修复过量
            const BOOL DetectMousePos = In_MouseEventJudgment(BlockPos[0] + 350, BlockPos[1] + 26 + (30 * (LineRow - 1)), 40, 12);//鼠标坐标检测
            static BOOL BoxMea = false;//只声明一次初始开关设定变量
            if (GetForegroundWindow() == EasyGUI_WindowHWND && !Mouse_Slider_)//当最前端窗口为GUI窗口接收按钮事件
            {
                if (!BoxMea && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && DetectMousePos)
                {
                    BoxMea = true;
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                }
                else if (BoxMea)
                {
                    for (int i = 0x01; i < 0xFE; ++i)//VK键码遍历
                    {
                        if (GetAsyncKeyState(i) & 0x8000)//当按下任意键
                        {
                            m_KeySelectValue = i;
                            BoxMea = false;
                        }
                    }
                    if ((GetAsyncKeyState(VK_BACK) & 0x8000) || (GetAsyncKeyState(VK_ESCAPE) & 0x8000))m_KeySelectValue = 0;//默认无值
                }
            }
            if (!BoxMea)
            {
                string DrawString_VK = In_VKCode_to_String(m_KeySelectValue);
                if (!m_KeySelectValue)DrawString_VK = "[-]";
                if (DetectMousePos)In_DrawString_Simple(BlockPos[0] + 355, BlockPos[1] + 27 + (30 * (LineRow - 1)), DrawString_VK, { 130,130,130 });
                else In_DrawString_Simple(BlockPos[0] + 355, BlockPos[1] + 27 + (30 * (LineRow - 1)), DrawString_VK, { 100,100,100 });
                return m_KeySelectValue;
            }
            else In_DrawString_Simple(BlockPos[0] + 355, BlockPos[1] + 27 + (30 * (LineRow - 1)), "[-]", { 150,130,100 });//激活读取
            return 0;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        BOOL GUI_Tips(vector<int>BlockPos, short LineRow, string TipsString, vector<int>TextColor = { 255,255,255 }) noexcept//鼠标指针提示(只支持单行字符)   (代码写在最后为了不被覆盖绘制)
        {
            if (BlockPos[0] == 0 && BlockPos[1] == 0)return 0;//当无block则不进行绘制
            In_DrawString_Simple(BlockPos[0] + 7, BlockPos[1] + 27 + (30 * (LineRow - 1)), "[?]", { 100,100,100 });//GUI绘制
            if (GetForegroundWindow() == EasyGUI_WindowHWND && In_MouseEventJudgment(BlockPos[0] + 7, BlockPos[1] + 26 + (30 * (LineRow - 1)), 13, 12) && !Mouse_Slider_)//当鼠标移动到问号 且GUI窗口为最顶层
            {
                In_DrawRect(EasyGUI_MousePos.x - EasyGUI_WindowPos.left + 15, EasyGUI_MousePos.y - EasyGUI_WindowPos.top + 15, strlen(TipsString.c_str()) * 6, 20, { 0,0,0 });
                In_DrawRect(EasyGUI_MousePos.x - EasyGUI_WindowPos.left + 15 + 1, EasyGUI_MousePos.y - EasyGUI_WindowPos.top + 15 + 1, strlen(TipsString.c_str()) * 6 - 2, 20 - 2, { 60,60,60 });
                In_DrawRect(EasyGUI_MousePos.x - EasyGUI_WindowPos.left + 15 + 2, EasyGUI_MousePos.y - EasyGUI_WindowPos.top + 15 + 2, strlen(TipsString.c_str()) * 6 - 4, 20 - 4, { 15,15,15 });
                In_DrawString_Simple(EasyGUI_MousePos.x - EasyGUI_WindowPos.left + 15 + 4, EasyGUI_MousePos.y - EasyGUI_WindowPos.top + 15 + 4, TipsString, TextColor);
                return true;
            }
            else return false;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        vector<int> GUI_ColorSelector(vector<int>BlockPos, short LineRow, vector<int>& m_ColorValue) noexcept//颜色选择器
        {
            if (BlockPos[0] == 0 && BlockPos[1] == 0)return { -1,-1,-1 };//当无block则不进行绘制
            if (In_MouseEventJudgment(BlockPos[0] + 360, BlockPos[1] - 6 + (30 * LineRow), 20, 20) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !Mouse_Slider_)//复制选取的颜色值
            {
                const string Color_String_Copy__ = to_string(m_ColorValue[0]) + ", " + to_string(m_ColorValue[1]) + ", " + to_string(m_ColorValue[2]);//要复制的字符串
                OpenClipboard(NULL);//打开剪切板
                EmptyClipboard();//清空剪切板
                const HANDLE hHandle = GlobalAlloc(GMEM_FIXED, strlen(Color_String_Copy__.c_str()) + 1);//分配内存
                strcpy_s((char*)GlobalLock(hHandle), strlen(Color_String_Copy__.c_str()) + 1, Color_String_Copy__.c_str());
                SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
                GlobalUnlock(hHandle);//解除锁定
                CloseClipboard();//关闭剪切板
                Beep(100, 30);//复制成功提醒
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            }
            for (short Color_Bl = 0; Color_Bl <= 2; ++Color_Bl)
            {
                const BOOL DetectMousePos = In_MouseEventJudgment(BlockPos[0] + 218 + 46 * Color_Bl, BlockPos[1] - 6 + (30 * LineRow), 41, 20);
                if (GetForegroundWindow() == EasyGUI_WindowHWND && DetectMousePos && !Mouse_Slider_)//当最前端窗口为GUI窗口接收按钮事件 //当鼠标移动到滑条上方 按键反馈事件
                {
                    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)m_ColorValue[Color_Bl]++;
                    else if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)m_ColorValue[Color_Bl]--;
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
                    if (GetAsyncKeyState(VK_LEFT) & 0x8000)m_ColorValue[Color_Bl] += 5;
                    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)m_ColorValue[Color_Bl] -= 5;
                }
                if (m_ColorValue[Color_Bl] >= 255)m_ColorValue[Color_Bl] = 255;
                else if (m_ColorValue[Color_Bl] <= 0)m_ColorValue[Color_Bl] = 0;
                In_DrawRect(BlockPos[0] + 218 + 46 * Color_Bl, BlockPos[1] - 6 + (30 * LineRow), 41, 20, { 0,0,0 });//Color_Block
                if (DetectMousePos)In_DrawGradientRect(BlockPos[0] + 218 + 46 * Color_Bl + 1, BlockPos[1] - 6 + (30 * LineRow) + 1, 41 - 2, 20 - 2, { Global_EasyGUIColor[0] / 4,Global_EasyGUIColor[1] / 4,Global_EasyGUIColor[2] / 4 }, { 30,30,30 }, true);
                else In_DrawGradientRect(BlockPos[0] + 218 + 46 * Color_Bl + 1, BlockPos[1] - 6 + (30 * LineRow) + 1, 41 - 2, 20 - 2, { Global_EasyGUIColor[0] / 5,Global_EasyGUIColor[1] / 5,Global_EasyGUIColor[2] / 5 }, { 30,30,30 }, true);
            }
            In_DrawString_Simple(BlockPos[0] + 218 + 5, BlockPos[1] - 3 + (30 * LineRow) + 1, "R: " + to_string(m_ColorValue[0]), { 150,150,150 });
            In_DrawString_Simple(BlockPos[0] + 218 + 46 + 5, BlockPos[1] - 3 + (30 * LineRow) + 1, "G: " + to_string(m_ColorValue[1]), { 150,150,150 });
            In_DrawString_Simple(BlockPos[0] + 218 + 46 * 2 + 5, BlockPos[1] - 3 + (30 * LineRow) + 1, "B: " + to_string(m_ColorValue[2]), { 150,150,150 });
            In_DrawRect(BlockPos[0] + 360, BlockPos[1] - 6 + (30 * LineRow), 20, 20, { 0,0,0 });//Color
            In_DrawGradientRect(BlockPos[0] + 360 + 1, BlockPos[1] - 6 + (30 * LineRow) + 1, 20 - 2, 20 - 2, m_ColorValue, { m_ColorValue[0] / 4,m_ColorValue[1] / 4,m_ColorValue[2] / 4 }, true);
            return m_ColorValue;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        vector<float> GUI_PosSelector(vector<int>BlockPos, short LineRow, vector<float>& m_PosValue) noexcept//坐标选择器
        {
            if (BlockPos[0] == 0 && BlockPos[1] == 0)return { -1,-1,-1 };//当无block则不进行绘制
            for (short Color_Bl = 0; Color_Bl <= 2; ++Color_Bl)
            {
                const BOOL DetectMousePos = In_MouseEventJudgment(BlockPos[0] + 180 + 70 * Color_Bl, BlockPos[1] - 6 + (30 * LineRow), 68, 20);
                if (GetForegroundWindow() == EasyGUI_WindowHWND && DetectMousePos && !Mouse_Slider_)//当最前端窗口为GUI窗口接收按钮事件 //当鼠标移动到滑条上方 按键反馈事件
                {
                    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)m_PosValue[Color_Bl] += 0.03;
                    else if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)m_PosValue[Color_Bl] -= 0.03;
                    if (GetAsyncKeyState(VK_LEFT) & 0x8000)m_PosValue[Color_Bl] += 1;
                    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)m_PosValue[Color_Bl] -= 1;
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
                    keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
                    if (GetAsyncKeyState(VK_UP) & 0x8000)m_PosValue[Color_Bl] += 10;//快速变值
                    else if (GetAsyncKeyState(VK_DOWN) & 0x8000)m_PosValue[Color_Bl] -= 10;
                }
                In_DrawRect(BlockPos[0] + 180 + 70 * Color_Bl, BlockPos[1] - 6 + (30 * LineRow), 70, 20, { 0,0,0 });//Color_Block
                if (DetectMousePos)In_DrawGradientRect(BlockPos[0] + 180 + 70 * Color_Bl + 1, BlockPos[1] - 6 + (30 * LineRow) + 1, 70 - 2, 20 - 2, { Global_EasyGUIColor[0] / 4,Global_EasyGUIColor[1] / 4,Global_EasyGUIColor[2] / 4 }, { 30,30,30 }, true);
                else In_DrawGradientRect(BlockPos[0] + 180 + 70 * Color_Bl + 1, BlockPos[1] - 6 + (30 * LineRow) + 1, 70 - 2, 20 - 2, { Global_EasyGUIColor[0] / 5,Global_EasyGUIColor[1] / 5,Global_EasyGUIColor[2] / 5 }, { 30,30,30 }, true);
            }
            stringstream Float_X_; Float_X_ << fixed << setprecision(2) << m_PosValue[0]; Float_X_ >> m_PosValue[0];//只保留2位小数点后数
            stringstream Float_Y_; Float_Y_ << fixed << setprecision(2) << m_PosValue[1]; Float_Y_ >> m_PosValue[1];
            stringstream Float_Z_; Float_Z_ << fixed << setprecision(2) << m_PosValue[2]; Float_Z_ >> m_PosValue[2];
            In_DrawString_Simple(BlockPos[0] + 180 + 5, BlockPos[1] - 3 + (30 * LineRow) + 1, "X: " + Float_X_.str(), { 150,150,150 });
            In_DrawString_Simple(BlockPos[0] + 180 + 70 + 5, BlockPos[1] - 3 + (30 * LineRow) + 1, "Y: " + Float_Y_.str(), { 150,150,150 });
            In_DrawString_Simple(BlockPos[0] + 180 + 70 * 2 + 5, BlockPos[1] - 3 + (30 * LineRow) + 1, "Z: " + Float_Z_.str(), { 150,150,150 });
            return m_PosValue;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
    };
}