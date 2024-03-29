/*主要负责初始化结构体并将其设置成空闲栈与分组的块的样式*/

#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include "global.c"

void push(struct stack* s, int e); //入栈
int gettop(struct stack* s); //获得栈顶元素
int pop(struct stack* s); //出栈
int judge(struct stack* s); //判断栈是否为空


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
void init_stack(struct stack* s, struct block* head) {
    struct block* p, * p1;
    struct stack* ps;
    ps = s;
    p1 = p = head;
    int i, e = 10, t, j = 0, r = 0, m = 0;

    if (gettop(ps) == 0) { //若栈中没有元素，则将表中的一组入栈，每次入10块
        printf("将表中一组入栈\n");
        for (i = 0; i < stack_size; i++) {
            push(ps, p->num);
            p1 = p;
            p = p->next;
            free(p1);//释放空间
        }
        push(ps, e);//栈顶放着栈中元素个数
    }
}