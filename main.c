#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include "global.c"

void main_menu();
void random_show();
void active_show();
int WINAPI animate(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow);
stack_size=10;//栈初始大小

void main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow)
{
    system("color f0\n");
    while (1)//主界面主菜单
    {
        int k;
        main_menu();
        //scanf_s("%d", &k);
        if ((k= _getch()) == '\n') {//防干扰且无需回车式读入k
            k = _getch();
        }
        switch (k)
        {
        case '1':system("cls"); ; active_show(); break;
        case '2':system("cls"); random_show(); break;
        case '3':system("cls"); animate(hInstance, hPrevInstance, lpCmdLine, iCmdShow); break;

        case 0:return;
        default: {system("cls"); printf("Please try again!"); break; }
        }
        printf("\n\t\t\t按任意键返回");
        _getch();
    }
}