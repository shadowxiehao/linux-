#ifndef _STRUCT_H//防止重复引用
#define _STRUCT_H
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
    int a[1024];   //模拟每块1024B
    int num;
    struct block* next;
};
struct file        //申请块的文件的数据结构
{
    int *stacks;
}*files;