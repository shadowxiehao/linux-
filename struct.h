#ifndef _STRUCT_H//��ֹ�ظ�����
#define _STRUCT_H
#define stack_init_size 11//ջ�ĳ�ʼ����СΪ11����λ
#define stackincrement 10
#endif

struct stack         //��ջ�����ݽṹ
{
    int* base;
    int* top;
    int stacksize;
};
struct block        //�������ӵ����ݽṹ
{
    int a[1024];   //ģ��ÿ��1024B
    int num;
    struct block* next;
};
struct file        //�������ļ������ݽṹ
{
    int *stacks;
}*files;