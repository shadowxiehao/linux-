#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include "global.c"

void main_menu();
void random_show();
void active_show();
int WINAPI animate(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow);
stack_size=10;//ջ��ʼ��С

void main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow)
{
    system("color f0\n");
    while (1)
    {
        int k;
        main_menu();
        scanf_s("%d", &k);
        switch (k)
        {
        case 10:system("cls");  break;
        case 1:system("cls"); ; active_show(); break;
        case 2:system("cls"); random_show(); break;
        case 3:system("cls"); animate(hInstance, hPrevInstance, lpCmdLine, iCmdShow); break;

        case 0:return;
        default: {system("cls"); printf("Please try again!"); break; }
        }
        printf("\n\t\t\t�����������");
        _getch();
    }
}