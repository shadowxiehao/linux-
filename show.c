#ifndef _STRUCT_H//��ֹ�ظ�����
#define _STRUCT_H
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include "struct.h"
#endif
void travelstack(struct stack* s) //����ջ
{
    struct stack f = *s;
    struct stack* ff = &f;//����ff��������s,��ֹ��ȡʱ���s�ı仯
    int count = 1;
    int e;//�������
    printf("ջ�л���Ԫ��:\n");
    while (ff->base != ff->top)
    {
        e = *(--(ff->top));//ԭΪe = *(--(s->top));
        printf("%d ", e);
        count++;
    }
    printf("\n");
}

void print(struct block* head)//��ӡ���
{
    struct block* p; int n = 0;//n����ÿ10������
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

void print_linked(struct block* head) {//��ӡ����
    struct block* p, * p1, * p2;
    printf("\n�������:");
    p1 = head;//���½����ı�����ԭ���ı��ǰ��
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

void print_linked_full(struct block* head) {//������ӡ����
    struct block* p, * p1, * p2;
    printf("\n�������:");
    p1 = head;//���½����ı�����ԭ���ı��ǰ��
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