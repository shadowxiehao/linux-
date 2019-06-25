#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include "struct.h"
#include "globe.c"

struct block* creat(void)   //创建100个编号0~99的块，10块为一组
{
    struct block* head;
    struct block* p1, * p2;
    int n = 100, i; int m = 0;//记录块号0~99
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
    while (p1->num < 90) { //将下一组的10个块号存入上一组的块头中
        if (p1->num % 10 == 0) {
            for (i = 0; i < 10; i++) p1->a[i] = m + 9 + i; 
        }
        m+=10;//因为10个一组,所以直接跳10个
        for(int q=0;q<10;q++)
            p1 = p1->next;
    };
    return(head);
}


//实现顺序栈的操作（栈空判断、出栈、入栈、读取栈顶元素,遍历栈）。

void push(struct stack* s, int e) //入栈
{
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (int*)realloc(s->base, (s->stacksize + stackincrement) * sizeof(int));
        if (!s->base)
        {
            printf("存储分配失败!\n"); exit(0);
        }
        s->top = s->base + s->stacksize;
        s->stacksize += stackincrement;
    }
    *s->top++ = e;
}
int gettop(struct stack* s) //获得栈顶元素
{
    int e;
    if (s->top == s->base)
    {
        return 0;
    }
    e = *(s->top - 1);
    return e;
}
int pop(struct stack* s) //出栈
{
    int e;
    if (s->top == s->base)return 0;
    else return e = *--s->top;
}
int judge(struct stack* s) //判断栈是否为空
{
    if (s->top == s->base)return 0;
    else return 1;
}

struct block* assign(struct block* head, struct stack* s, int record[100], int file[100][10], int n) {//申请分配块
    struct block* p, * p1;
    struct stack* ps;
    int i, e = 10, t, j = 0, r = 0, m = 0;
    ps = s;
    p1 = p = head;
    for (i = 0; i < 100; i++)
        if (record[i] == 0) break; 
    m = i;//记录分配的文件号
    record[m] = 1;
    printf("分配 file[%d] %d个:", m, n);

    while (n != 0) {
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
        else {  //分配块
            printf("\n直接分配:");
            t = pop(ps);
            file[m][r++] = pop(ps);//记录块分配给那个文件，哪几块分配给这个文件
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

    //判断哪个文件分配了块，找最近的文件，将里面的块回收
    for (i = 0; i < 100; i++)
        if (record[i] == 1) m = i; 
    if (m!=101)
    {
        record[m] = 0;
    }
    else if (m == 101) return head;//如果全部文件都还没有申请到块，回收失败，返回

    for (i = 0; i < 10; i++) if (file[m][i] != 0) n++;
    printf("回收 file[%d] %d个:", m, n);
    printf("测试gettop(ps):%d", gettop(ps));
    for (i = 0; i < n; i++)
    {
        if (gettop(ps) != 10)//若栈不是满的就入栈
        {
            t = pop(ps);
            push(ps, file[m][i]);//将文件m申请到的块号入栈，记录块号的file[m][i]置零
            printf("%d ", file[m][i]);
            file[m][i] = 0;
            t++;
            push(ps, t);

        }
        else if (gettop(ps) == 10) { //栈满了就创建一个新链表，回收栈里面的块
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
            push(ps, file[m][i]);//将文件m申请到的块号入栈，记录块号的file[m][i]置零
            printf("%d ", file[m][i]);
            file[m][i] = 0;
            t++;
            push(ps, t);

            p1 = newhead;//把新建立的表连到原来的表的前面
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

