/*�����ܣ����button��ť�����������ı�*/
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

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);  //��������

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
        MessageBox(NULL, TEXT("����Ҫ�� Windows NT ϵͳ!"), szAppName, MB_ICONERROR);

        return 0;
    }

    hwnd = CreateWindow(szAppName,
        TEXT("WindowsAPI����-��ťʵ�� "),
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

//���ڹ��̺���
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    static HWND hwndButton[NUM];  //��ť�������
    static HWND hwndTxt;
    static HWND hwndBtnSure;
    static HWND hwndBtnSure2;
    static HWND hwndChild;
    static RECT rect; //���νṹ��
    //char����
    static TCHAR szTop[] = TEXT("���ܣ������ť��ʾ�ı�������"),
        szUnd[] = TEXT("_______          ______          ______"),
        szFormat[] = TEXT("%-16s%04X-%04X         %04X-%04X"),  //���ڸ�ʽ���ַ����ο� http://blog.163.com/c__0/blog/static/188312066201162661240584/
        szBuffer[50];
    char constStr[] = { "��ʱ�䲻��,��δ���" };
    char outputStr[256];
    static int cxChar, cyChar;
    HDC    hdc;     //��ͼʵ�����
    HDC    childHdc;
    PAINTSTRUCT ps; //���ƽṹ��
    int i, len;
    switch (message)
    {
        //����
    case WM_CREATE:

        cxChar = LOWORD(GetDialogBaseUnits());
        cyChar = HIWORD(GetDialogBaseUnits());


        //�ı���
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

        //��ť
        hwndBtnSure2 = CreateWindow(
            TEXT("button"),
            "�����2",
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
            "�����",
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

        SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));  //ѡȡ��ǰ����
        SetBkMode(hdc, TRANSPARENT);// �������ó�͸��

       // SetBkColor(hdc,GetSysColor(COLOR_BTNFACE));
        SetTextColor(hdc, GetSysColor(COLOR_BTNTEXT)); //�����ı���ɫ

        TextOut(hdc, 24 * cxChar, cyChar, szTop, lstrlen(szTop));
        //TextOut(hdc,24*cxChar,cyChar,szUnd,lstrlen(szUnd));



        EndPaint(hwnd, &ps);
        return 0;

    case WM_DRAWITEM:
    case WM_COMMAND:

        hdc = GetDC(hwnd);
        SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));  //ѡȡ��ǰ����

        //��ȡ��ǰ�Ӵ��ھ��
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
            MessageBox(NULL, szBuff, TEXT("��ʾ"), 0);
        }
        else if (hwndChild == hwndBtnSure2)
        {
            MessageBox(NULL, TEXT("��ť2�����"), TEXT("��ʾ"), 0);
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