#ifndef _STRUCT_H//��ֹ�ظ�����
#define _STRUCT_H
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include "struct.h"
#endif

int get_position(int i);
void set_position(int x, int y);

void line1(int num) {//��ӡ���ٸ�"-"
    for (int i = 0; i < num; i++) {
        printf("-");
    }
    printf("\n");
}
void line2(int num) {//��ӡ���ٸ�"|"
    for (int i = 0; i < num; i++) {
        printf("|");
    }
}

void print_stack(int number) {//���ݸ��������ӡȫ�����+��
    int count = 0;
    int num[2] = { 0 };
    line2(1);
    printf("%3d", number);
    line2(1);
    printf("\n");
    line1(5);
}

void travelstack(struct stack* s) //����ջ����ӡ
{
    struct stack f = *s;
    struct stack* ff = &f;//����ff��������s,��ֹ��ȡʱ���s�ı仯
    int e;//�������
    printf("Ŀǰ����ջ���:\n");
    line1(5);
    while (ff->base != ff->top)
    {
        e = *(--(ff->top));//ԭΪe = *(--(s->top));
        print_stack(e);
    }
    printf("\n");
}

void print(struct block* head)//��ӡ���
{
    struct block* p; int n = 0;//n����ÿ10������
    p = head;
    printf("�����п��еķ���(��)�У�\n");

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