#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include "struct.h"
#include "globe.c"

struct block* creat(void)   //����100�����0~99�Ŀ飬10��Ϊһ��
{
    struct block* head;
    struct block* p1, * p2;
    int n = 100, i; int m = 0;//��¼���0~99
    p1 = p2 = (struct block*)malloc(sizeof(struct block));
    p1->num = m++;
    for (i = 0; i < 10; i++) p1->a[i] = 0;
    head = NULL;
    while (n != 0)
    {
        if (n == 100) head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = (struct block*)malloc(sizeof(struct block));
        p1->num = m++;
        for (i = 0; i < 10; i++) p1->a[i] = 0;
        n--;
    }
    p2->next = NULL;
    p1 = p2 = head; m = 1;
    while (p1->num < 90) { //����һ���10����Ŵ�����һ��Ŀ�ͷ��
        if (p1->num % 10 == 0) {
            for (i = 0; i < 10; i++) p1->a[i] = m + 9 + i; 
        }
        m+=10;//��Ϊ10��һ��,����ֱ����10��
        for(int q=0;q<10;q++)
            p1 = p1->next;
    };
    return(head);
}


//ʵ��˳��ջ�Ĳ�����ջ���жϡ���ջ����ջ����ȡջ��Ԫ��,����ջ����

void push(struct stack* s, int e) //��ջ
{
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (int*)realloc(s->base, (s->stacksize + stackincrement) * sizeof(int));
        if (!s->base)
        {
            printf("�洢����ʧ��!\n"); exit(0);
        }
        s->top = s->base + s->stacksize;
        s->stacksize += stackincrement;
    }
    *s->top++ = e;
}
int gettop(struct stack* s) //���ջ��Ԫ��
{
    int e;
    if (s->top == s->base)
    {
        return 0;
    }
    e = *(s->top - 1);
    return e;
}
int pop(struct stack* s) //��ջ
{
    int e;
    if (s->top == s->base)return 0;
    else return e = *--s->top;
}
int judge(struct stack* s) //�ж�ջ�Ƿ�Ϊ��
{
    if (s->top == s->base)return 0;
    else return 1;
}

struct block* assign(struct block* head, struct stack* s, int record[100], int file[100][10], int n) {//��������
    struct block* p, * p1;
    struct stack* ps;
    int i, e = 10, t, j = 0, r = 0, m = 0;
    ps = s;
    p1 = p = head;
    for (i = 0; i < 100; i++)
        if (record[i] == 0) break; 
    m = i;//��¼������ļ���
    record[m] = 1;
    printf("���� file[%d] %d��:", m, n);

    while (n != 0) {
        if (gettop(ps) == 0) { //��ջ��û��Ԫ�أ��򽫱��е�һ����ջ��ÿ����10��
            printf("������һ����ջ\n");
            for (i = 0; i < stack_size; i++) {
                push(ps, p->num);
                p1 = p;
                p = p->next;
                free(p1);//�ͷſռ�
            }
            push(ps, e);//ջ������ջ��Ԫ�ظ���
        }
        else {  //�����
            printf("\nֱ�ӷ���:");
            t = pop(ps);
            file[m][r++] = pop(ps);//��¼�������Ǹ��ļ����ļ�����������ļ�
            printf("%d ", file[m][r - 1]);
            if (t != 1)
                push(ps, t - 1);
            else t = 0;
            n--;
        }
    }
    printf("\n\n");
    return p;
}


struct block* callback(struct block* head, struct stack* s, int record[100], int file[100][10])
{
    struct block* p, * p1, * p2, * newhead = NULL;
    struct stack* ps;
    int i, j, t, m = 101, n = 0;
    ps = s;
    p = head;

    //�ж��ĸ��ļ������˿飬��������ļ���������Ŀ����
    for (i = 0; i < 100; i++)
        if (record[i] == 1) m = i; 
    if (m!=101)
    {
        record[m] = 0;
    }
    else if (m == 101) return head;//���ȫ���ļ�����û�����뵽�飬����ʧ�ܣ�����

    for (i = 0; i < 10; i++) if (file[m][i] != 0) n++;
    printf("���� file[%d] %d��:", m, n);
    printf("����gettop(ps):%d", gettop(ps));
    for (i = 0; i < n; i++)
    {
        if (gettop(ps) != 10)//��ջ�������ľ���ջ
        {
            t = pop(ps);
            push(ps, file[m][i]);//���ļ�m���뵽�Ŀ����ջ����¼��ŵ�file[m][i]����
            printf("%d ", file[m][i]);
            file[m][i] = 0;
            t++;
            push(ps, t);

        }
        else if (gettop(ps) == 10) { //ջ���˾ʹ���һ������������ջ����Ŀ�
            t = pop(ps);
            newhead = p1 = p2 = (struct block*)malloc(sizeof(struct block));
            p1->num = pop(ps);
            if (p != NULL)
            {
                for (j = 0; j < 10; j++) { p1->a[j] = p->num; p = p->next; }
            }
            while (t != 0)
            {
                if (t == 10)
                    newhead = p1;
                else
                    p2->next = p1;
                p2 = p1;
                p1 = (struct block*)malloc(sizeof(struct block));
                p1->num = pop(ps);
                for (j = 0; j < 10; j++) p1->a[j] = 0;
                t--;
            }
            p2->next = NULL; push(ps, t);
            t = pop(ps);
            push(ps, file[m][i]);//���ļ�m���뵽�Ŀ����ջ����¼��ŵ�file[m][i]����
            printf("%d ", file[m][i]);
            file[m][i] = 0;
            t++;
            push(ps, t);

            p1 = newhead;//���½����ı�����ԭ���ı��ǰ��
            p2 = p1->next;
            while (p1->next != NULL)
            {
                p1 = p2;
                p2 = p1->next;
            }
            p1->next = head;
            head = newhead;
        }
    }
    printf("\n\n");
    return(head);
}

