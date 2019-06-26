#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include "struct.h"
#include "global.c"

struct block* creat(void);   //创建100个编号0~99的块，10块为一组;
void print(struct block* head);//打印块号;
//实现顺序栈的操作（栈空判断、出栈、入栈、读取栈顶元素,遍历栈）。
void initstack(struct stack* s); //栈的初始化
void push(struct stack* s, int e); //入栈
int gettop(struct stack* s); //获得栈顶元素
int pop(struct stack* s); //出栈
int judge(struct stack* s); //判断栈是否为空
void travelstack(struct stack* s);//遍历栈
struct block* assign(struct block* head, struct stack* s, int record[file_nums], int file[file_nums][10], int n);//申请分配块
struct block* callback(struct block* head, struct stack* s, int record[file_nums], int file[file_nums][10]);//回收
void print_linked(struct block* head);//打印链表
void print_linked_full(struct block* head);//完整打印链表
void set_position(int x, int y);
int get_position(int i);
void set_position(int x, int y);

void random_show()
{
    system("cls");
    printf("欢迎进入随机演示!(每次均会暂停以便查看结果,按任意键即可继续)\n\n");
    Sleep(1200);
    system("cls");
    //各种栈和块的结构体申明
    struct stack s;
    struct stack* ps;
    struct block* head, * p;

    int n=0, i=0, m=0, j = 0;//用于计数等的变量
    int d = 30; int f = 5;//定义分配和回收的次数
    
    int po1[2] = { 0 }, po2[2] = { 0 };//记录光标位置

    int file[file_nums][file_max] = { 0 };//文件，用来记录申请的文件号和申请到的块号
    int record[file_nums] = { 0 };//记录，用来记录哪个文件申请了块
    ps = &s;
    initstack(ps);//初始化堆栈
    p = head = creat();
    printf("开始时:");
    print(head);
    printf("\n");
    printf("进行随机分配回收,前半段主随机分配,后半段主随机回收\n\n");

    printf("前半段__");
    po1[0]=get_position(0);
    po1[1] = get_position(1);
    printf("___次, 后半段__");
    po2[0] = get_position(0);
    po2[1] = get_position(1);
    printf("___次 ?");
    
    set_position(po1[0], po1[1]);
    scanf_s("%d", &d);
    set_position(po2[0], po2[1]);
    scanf_s("%d", &f);

    set_position(0, po2[1]+2);
    
    srand(time(NULL));//用于随机函数
    for (i = 1; i <= d; i++)       //分配和回收，前半期分配居多
    {
        po1[0] = get_position(0);
        po1[1] = get_position(1);//记录光标,用于友好化演示

        n = rand() % 10 + 1;//随机生成1~10的数
        printf("前半段第%d次\n", i);
        if (n >= 3)
        {
            j = rand() % 10 + 1;//随机生成1~10的数
            printf("进行分配,");

            if ((gettop(ps) < n) & (p == NULL)) { printf("\n空闲栈和空闲组均无空间,分配失败,跳转至下一轮\n\n"); continue; }

            head = assign(p, ps, record, file, j);//分配
            p = head;

            printf("前半段第%d次分配完成\n", i);
        }
        else
        {
            printf("进行回收:\n");

            p = callback(head, ps, record, file);//回收
            head = p;

            printf("前半段第%d次回收完成\n", i);
        }
        printf("\n");
        travelstack(ps);
        printf("\n");
        print(head);
        printf("\n");
        
        po2[0] = get_position(0);
        po2[1] = get_position(1);
        set_position(po1[0], po1[1]-1);

        _getch();//等待任意键继续
        set_position(po2[0], po2[1]);
    }
    for (i = 1; i <= f; i++)       //分配和回收，后半期回收居多
    {
        po1[0] = get_position(0);
        po1[1] = get_position(1);//记录光标,用于友好化演示

        n = rand() % 10 + 1;//随机生成1~10的数
        printf("后半段第%d次\n", i);
        if (n >= 7)
        {
            j = rand() % 10 + 1;//随机生成1~10的数
            printf("进行分配,");

            if ((gettop(ps) < n) & (p == NULL)) { i--; printf("重来\n"); continue; }

            head = assign(p, ps, record, file, j);//分配
            p = head;

            printf("后半段第%d次分配完成\n", i);
        }
        else
        {
            printf("进行回收:\n");

            p = callback(head, ps, record, file);//回收
            head = p;

            printf("后半段第%d次回收完成\n", i);
        }
        printf("\n");
        travelstack(ps);
        printf("\n");
        print(head);
        printf("\n");

        po2[0] = get_position(0);
        po2[1] = get_position(1);
        set_position(po1[0], po1[1]-1);

        _getch();//等待任意键继续
        set_position(po2[0], po2[1]);
    }
    travelstack(ps);
    printf("\n");
    print(head);
    //print_linked_full(head);打印外存
    printf("\n\t随机演示完成");

}

