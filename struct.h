#ifndef _STRUCT_H//��ֹ�ظ�����
#define _STRUCT_H
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
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
    int a[10];
    int num;
    struct block* next;
};
