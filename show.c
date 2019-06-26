#ifndef _STRUCT_H//防止重复引用
#define _STRUCT_H
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include "struct.h"
#endif

int get_position(int i);
void set_position(int x, int y);

void line1(int num) {//打印多少个"-"
    for (int i = 0; i < num; i++) {
        printf("-");
    }
    printf("\n");
}
void line2(int num) {//打印多少个"|"
    for (int i = 0; i < num; i++) {
        printf("|");
    }
}

void print_stack(int number) {//根据给的数组打印全部框架+数
    int count = 0;
    int num[2] = { 0 };
    line2(1);
    printf("%3d", number);
    line2(1);
    printf("\n");
    line1(5);
}

void travelstack(struct stack* s) //遍历栈并打印
{
    struct stack f = *s;
    struct stack* ff = &f;//这里ff用来复制s,防止读取时造成s的变化
    int e;//用来输出
    printf("目前空闲栈情况:\n");
    line1(5);
    while (ff->base != ff->top)
    {
        e = *(--(ff->top));//原为e = *(--(s->top));
        print_stack(e);
    }
    printf("\n");
}

void print(struct block* head)//打印块号
{
    struct block* p; int n = 0;//n用来每10个换行
    p = head;
    printf("磁盘中空闲的分组(块)有：\n");

    if (head != NULL) {
        line1(41);
        do
        {
            line2(1);
            printf("%d ", p->num);
            n++;
            if (n % 10 == 0) {
                line2(1);
                printf("\n"); 
                line1(41);
            }
            p = p->next;
        } while (p != NULL);
    }
}

void print_linked(struct block* head) {//打印链表
    struct block* p, * p1, * p2;
    printf("\n外存链表:");
    p1 = head;//把新建立的表连到原来的表的前面
    printf("%d ", p1->num);
    p2 = p1->next;
    while (p1->next != NULL)
    {
        p1 = p2;
        printf("%d ", p1->num);
        p2 = p1->next;
    }
    printf("\n");
}

void print_linked_full(struct block* head) {//完整打印链表
    struct block* p, * p1, * p2;
    printf("\n外存链表:");
    p1 = head;//把新建立的表连到原来的表的前面
    printf("%d ", p1->num);
    for (int i = 0; i < 10; i++)
    {
        printf("a:%d ", p1->a[i]);
    }   
    p2 = p1->next;
    while (p1->next != NULL)
    {
        p1 = p2;
        printf("%d ", p1->num);
        for (int i = 0; i < 10; i++)
        {
            printf("a:%d ", p1->a[i]);
        }   
        p2 = p1->next;
    }
    printf("\n");
}