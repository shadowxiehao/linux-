/*主动演示功能的核心*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include "struct.h"
#include "global.c"

struct block* creat(void);   //创建100个编号0~99的块，10块为一组;
void print_block(struct block* head);//打印块号;
//实现顺序栈的操作（栈空判断、出栈、入栈、读取栈顶元素,遍历栈）。
void initstack(struct stack* s); //栈的初始化
void travel_stack(struct stack* s);//遍历栈
struct block* assign(struct block* head, struct stack* s, int record[file_nums], int file[file_nums][10], int n);//申请分配块
struct block* callback(struct block* head, struct stack* s, int record[file_nums], int file[file_nums][10]);//回收
//void print_linked(struct block* head);//打印链表
//void print_linked_full(struct block* head);//完整打印链表
int get_position(int i);
void set_position(int x, int y);
void active_menu1();
int active_menu2(int q);
int active_menu3(int q);
int active_menu4(int q);
void draw_stack(struct stack* s);//绘图_栈
void draw_block(struct block* head);//绘图 组

//各种栈和块的结构体申明
struct stack s;
struct stack* ps;
struct block* head, * p;

int file[file_nums][file_max] = { 0 };//文件，用来记录申请的文件号和申请到的块号
int record[file_nums] = { 0 };//记录，用来记录哪个文件申请了块

int active_assign(int f) {
    if (f == 0) {//不符合
        return 1;
    }
    head = assign(p, ps, record, file, f);//分配
    p = head;

    return 0;
}
int active_callback() {
    p = callback(head, ps, record, file);//回收
    head = p;
}
int active_travelstack(){
    travel_stack(ps);
    draw_stack(ps);
    return 0;
}
int active_print() {
    print_block(head);
    draw_block(head);
}

void active_show()
{
    system("color f0\n");
    system("cls");
    printf("欢迎进入主动演示!\n\n");
    Sleep(850);
    system("cls");

    int n = 0, i = 0, m = 0, j = 0;//用于计数等的变量
    int d = 30; int f = 5;//定义分配和回收的次数

    int po1[2] = { 0 }, po2[2] = { 0 };//记录光标位置

    ps = &s;
    initstack(ps);//初始化堆栈
    p = head = creat();
    printf("\n");

    while (1) {//主动演示主菜单
            int k = 10, f = 0;

            po1[0] = get_position(0); po1[1] = get_position(1);
            active_menu1();
            po2[0] = get_position(0); po2[1] = get_position(1);
            //scanf_s("%d", &k);
            if ((k = _getch()) == '\n') {//防干扰且无需回车式读入k
                k = _getch();
            }
            switch (k)
            {
            case '1':  f=active_menu2(po1[1]);  active_assign(f); break;
            case '2': active_menu3(po1[1]); active_callback(); break;
            case '3': active_menu4(po1[1]); active_travelstack(); break;
            case '4': active_menu4(po1[1]); active_print(); break;
            case '0':return;
            default: {active_menu4(po1[1]); break; }
            }

            printf("\n\t\t\t按任意键继续");
            //用于消除上面的按任意键继续
            po2[1] = get_position(1);
            _getch();
            printf("%c[2K", 27);//清除当前行内容
            set_position(0, po2[1] - 1);
    }
    printf("\n\t主动演示完成");
}

