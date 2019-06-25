#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include "struct.h"

struct block* creat(void);   //创建100个编号0~99的块，10块为一组;
void print(struct block* head);//打印块号;
//实现顺序栈的操作（栈空判断、出栈、入栈、读取栈顶元素,遍历栈）。
void initstack(struct stack* s); //栈的初始化
void push(struct stack* s, int e); //入栈
int gettop(struct stack* s); //获得栈顶元素
int pop(struct stack* s); //出栈
int judge(struct stack* s); //判断栈是否为空
void travelstack(struct stack* s);//遍历栈
struct block* assign(struct block* head, struct stack* s, int record[100], int file[100][10], int n);//申请分配块
struct block* callback(struct block* head, struct stack* s, int record[100], int file[100][10]);//回收
void print_linked(struct block* head);//打印链表
void print_linked_full(struct block* head);//完整打印链表

void first()
{
    struct stack s;
    struct stack* ps;
    struct block* head, * p;
    int n, i, m = 0;
    int file[100][10] = { 0 };//文件，用来记录申请的文件号和申请到的块号
    int record[100] = { 0 };//记录，用来记录哪个文件申请了块
    ps = &s;
    initstack(ps);//初始化堆栈
    p = head = creat();
    printf("开始时空闲的块：\n\n");
    print(head);
    printf("\n");
    srand(time(NULL));//用于随机函数

    for (i = 1; i <= 5; i++)       //分配和回收，后半期回收居多
    {
        n = rand() % 10 + 1;//随机生成1~10的数
        printf("第%d次,%d\n",i,n);
        if (n >= 4)
        {

            if ((gettop(ps) < n) & (p == NULL)) { i--; printf("重来\n"); continue; }

            head = assign(p, ps, record, file, 10);//分配
            p = head;

        }
        else
        {
            p = callback(head, ps, record, file);//回收
            head = p;
        }
        printf("哈%d次,%d done\n",i, n);
        printf("\n");
        print(head);
        printf("\n");
        travelstack(ps);
        printf("\n");
        print_linked(head);
    }
    printf("所有请求完成后，磁盘中空闲的块号有：\n\n");
    print(head);
    printf("\n");
    travelstack(ps);
    print_linked_full(head);
}

