#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>

void main_menu();
void first();

void main()
{
    system("color f0\n");
    while (1)
    {
        int k;
        main_menu();
        scanf_s("%d", &k);
        switch (k)
        {
        //case 10:system("cls"); initial(); save(); break;
        case 1:system("cls"); first(); break;
        //case 2:system("cls"); change(); break;
        //case 3:system("cls"); open(); display(); break;
        //case 4:system("cls"); open(); order(); break;
        //case 5:system("cls"); open(); statistics(); break;
        //case 9:system("cls"); clear(); break;
        //case 0:return;
        default: {system("cls"); printf("Please try again!"); break; }
        }
        printf("\n\t\t\t按任意键返回");
        _getch();
    }
}