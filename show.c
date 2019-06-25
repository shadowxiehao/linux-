#ifndef _STRUCT_H//防止重复引用
#define _STRUCT_H
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include "struct.h"
#endif
void travelstack(struct stack* s) //遍历栈
{
    struct stack f = *s;
    struct stack* ff = &f;//这里ff用来复制s,防止读取时造成s的变化
    int count = 1;
    int e;//用来输出
    printf("栈中还有元素:\n");
    while (ff->base != ff->top)
    {
        e = *(--(ff->top));//原为e = *(--(s->top));
        printf("%d ", e);
        count++;
    }
    printf("\n");
}

void print(struct block* head)//打印块号
{
    struct block* p; int n = 0;//n用来每10个换行
    p = head;
    if (head != NULL) {
        do
        {
            printf("%d ", p->num);
            n++;
            if (n % 10 == 0)printf("\n");
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