/*程序功能：点击button按钮弹出输入框的文本*/
#include<windows.h>

struct
{
    int iStyle;
    TCHAR* szText;
}
button[] =
{
    BS_PUSHBUTTON,          TEXT("BS_PUSHBUTTON"),
    BS_DEFPUSHBUTTON,       TEXT("BS_DEFPUSHBUTTON")
};

#define NUM (sizeof button /sizeof button[0])  //num=2

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);  //申明函数

int WINAPI animate(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("app1");

    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("程序要求 Windows NT 系统!"), szAppName, MB_ICONERROR);

        return 0;
    }

    hwnd = CreateWindow(szAppName,
        TEXT("WindowsAPI程序-按钮实例 "),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;

}

//窗口过程函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    static HWND hwndButton[NUM];  //按钮句柄集合
    static HWND hwndTxt;
    static HWND hwndBtnSure;
    static HWND hwndBtnSure2;
    static HWND hwndChild;
    static RECT rect; //矩形结构体
    //char数组
    static TCHAR szTop[] = TEXT("功能：点击按钮显示文本框内容"),
        szUnd[] = TEXT("_______          ______          ______"),
        szFormat[] = TEXT("%-16s%04X-%04X         %04X-%04X"),  //关于格式化字符串参考 http://blog.163.com/c__0/blog/static/188312066201162661240584/
        szBuffer[50];
    char constStr[] = { "，时间不够,暂未完成" };
    char outputStr[256];
    static int cxChar, cyChar;
    HDC    hdc;     //绘图实例句柄
    HDC    childHdc;
    PAINTSTRUCT ps; //绘制结构体
    int i, len;
    switch (message)
    {
        //创建
    case WM_CREATE:

        cxChar = LOWORD(GetDialogBaseUnits());
        cyChar = HIWORD(GetDialogBaseUnits());


        //文本框
        hwndTxt = CreateWindow(
            "edit",
            "",
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_TEXT,
            250, 100, 300, 22,
            hwnd,
            (HMENU)1,
            ((LPCREATESTRUCT)lParam)->hInstance,
            NULL
        );

        //按钮
        hwndBtnSure2 = CreateWindow(
            TEXT("button"),
            "点击我2",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            230,
            190,
            20 * cxChar,
            7 * cyChar / 4,
            hwnd,
            (HMENU)3,
            ((LPCREATESTRUCT)lParam)->hInstance,
            NULL
        );



        hwndBtnSure = CreateWindow(
            TEXT("Button"),
            "点击我",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            230,
            150,
            20 * cxChar,
            7 * cyChar / 4,
            hwnd,
            (HMENU)2,
            ((LPCREATESTRUCT)lParam)->hInstance, NULL);




        return 0;

    case WM_SIZE:
        rect.left = 24 * cxChar;
        rect.top = 2 * cyChar;
        rect.right = LOWORD(lParam);
        rect.bottom = HIWORD(lParam);
        return 0;

    case WM_PAINT:

        InvalidateRect(hwnd, &rect, TRUE);

        hdc = BeginPaint(hwnd, &ps);

        SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));  //选取当前字体
        SetBkMode(hdc, TRANSPARENT);// 背景设置成透明

       // SetBkColor(hdc,GetSysColor(COLOR_BTNFACE));
        SetTextColor(hdc, GetSysColor(COLOR_BTNTEXT)); //设置文本颜色

        TextOut(hdc, 24 * cxChar, cyChar, szTop, lstrlen(szTop));
        //TextOut(hdc,24*cxChar,cyChar,szUnd,lstrlen(szUnd));



        EndPaint(hwnd, &ps);
        return 0;

    case WM_DRAWITEM:
    case WM_COMMAND:

        hdc = GetDC(hwnd);
        SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));  //选取当前字体

        //获取当前子窗口句柄
        hwndChild = (HWND)lParam;
        if (hwndChild == hwndBtnSure)
        {
            char szBuff[256];
            GetWindowText(hwndTxt, szBuff, sizeof(szBuff));
            if (strlen(szBuff) == 0)
                return 0;

            for (i = 0; i < sizeof(outputStr); i++)
            {
                if (i == 0)
                    len = strlen(szBuff)-1;
                szBuff[len++] = constStr[i];
            }
            MessageBox(NULL, szBuff, TEXT("提示"), 0);
        }
        else if (hwndChild == hwndBtnSure2)
        {
            MessageBox(NULL, TEXT("按钮2点击了"), TEXT("提示"), 0);
        }

        ReleaseDC(hwnd, hdc);
        ValidateRect(hwnd, &rect);
        break;

    case WM_CTLCOLORBTN:
        /*
            childHdc=(HDC)wParam;
         SetBkColor(childHdc,GetSysColor(COLOR_BTNFACE));
         SetTextColor(childHdc,GetSysColor(COLOR_HIGHLIGHT));
         ReleaseDC((HWND)lParam,childHdc);
         */
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}