#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include "global.c"

int gettop(struct stack* s);


void initstack(struct stack* s) //ջ�ĳ�ʼ��
{
    s->base = (int*)malloc((stack_size + 1) * sizeof(int));//����stack_init_size��int��С
    if (!s->base)
    {
        printf("����ռ�ʧ��!"); exit(0);
    }
    s->top = s->base;
    s->stacksize = stack_size;
}
void init_stack(struct stack* s, struct block* head) {
    struct block* p, * p1;
    struct stack* ps;
    ps = s;
    p1 = p = head;
    int i, e = 10, t, j = 0, r = 0, m = 0;

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
}