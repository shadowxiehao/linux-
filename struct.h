#ifndef _STRUCT_H//防止重复引用
#define _STRUCT_H
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define stack_init_size 11//栈的初始化大小为11个单位
#define stackincrement 10
#endif

struct stack         //堆栈的数据结构
{
    int* base;
    int* top;
    int stacksize;
};
struct block        //成组链接的数据结构
{
    int a[10];
    int num;
    struct block* next;
};
