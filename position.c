/*�����������̨���λ�õ��Ѻû���ʾ����*/
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int get_position(int i)//��ȡ��ǰ�������(x:��������,y:���ϵ���)
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

    COORD point = {x,y};//���Ҫ���õ�λ��x,y
    HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//ʹ��GetStdHandle(STD_OUTPUT_HANDLE)����ȡ��׼����ľ��
    SetConsoleCursorPosition(HOutput, point);//���ù��λ��
}
void reset_clear(int y1, int y2) {//�����y1~y2���е�����,������궨λ��y1�еĵ�һ��(y1<y2)
    int k = y2 - y1;
    for (int i = y2; i >= y1; i--) {
        set_position(0, i);
        printf("%c[2K", 27);//�����ǰ������
    }
}