/*负责调整控制台光标位置等友好化演示函数*/
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int get_position(int i)//获取当前光标坐标(x:从做到右,y:从上到下)
{
    int num[2] = { 0 };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        num[0] = csbi.dwCursorPosition.X;
        num[1]=csbi.dwCursorPosition.Y;
        if (i == 0) {
            return num[0];
        }
        else {
            return num[1];
        }
    }
}

void set_position(int x,int y)
{

    COORD point = {x,y};//光标要设置的位置x,y
    HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//使用GetStdHandle(STD_OUTPUT_HANDLE)来获取标准输出的句柄
    SetConsoleCursorPosition(HOutput, point);//设置光标位置
}
void reset_clear(int y1, int y2) {//清除从y1~y2的行的内容,并将光标定位到y1行的第一列(y1<y2)
    int k = y2 - y1;
    for (int i = y2; i >= y1; i--) {
        set_position(0, i);
        printf("%c[2K", 27);//清除当前行内容
    }
}