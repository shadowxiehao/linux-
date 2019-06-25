#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include "globe.c"

void initstack(struct stack* s) //栈的初始化
{
    s->base = (int*)malloc((stack_size + 1) * sizeof(int));//分配stack_init_size个int大小
    if (!s->base)
    {
        printf("分配空间失败!"); exit(0);
    }
    s->top = s->base;
    s->stacksize = stack_size;
}