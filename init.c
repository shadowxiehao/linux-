#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include "globe.c"

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