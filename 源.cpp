#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include "struct.h"

struct block* creat(void);   //����100�����0~99�Ŀ飬10��Ϊһ��;
    void print(struct block* head);//��ӡ���;
    //ʵ��˳��ջ�Ĳ�����ջ���жϡ���ջ����ջ����ȡջ��Ԫ��,����ջ����
    void initstack(struct stack* s); //ջ�ĳ�ʼ��
    void push(struct stack* s, int e) //��ջ
    int gettop(struct stack* s); //���ջ��Ԫ��
int pop(struct stack* s); //��ջ
    int judge(struct stack* s); //�ж�ջ�Ƿ�Ϊ��
    void travelstack(struct stack* s);//����ջ
    struct block* assign(struct block* head, struct stack* s, int record[100], int file[100][10], int n);//��������
    struct block* callback(struct block* head, struct stack* s, int record[100], int file[100][10]);//����
void main()
{
    struct stack s;
    struct stack* ps;
    struct block* head, * p;
    int n, i, m = 0;
    int file[100][10] = { 0 };//�ļ���������¼������ļ��ź����뵽�Ŀ��
    int record[100] = { 0 };//��¼��������¼�ĸ��ļ������˿�
    ps = &s;
    initstack(ps);//��ʼ����ջ
    p = head = creat();
    printf("��ʼʱ���еĿ飺\n\n");
    print(head);
    printf("\n");
    srand(time(NULL));//�����������
    for (i = 1; i <= 100; i++)       //����ͻ���,ǰ��������Ӷ�
    {
        n = rand() % 10 + 1;//�������1~10����			
        if (n >= 3)
        {
            if ((gettop(ps) < n) & (p == NULL)) { i--; continue; }
            //���100�鶼�����ˣ��Ͳ����䣬����ѭ��	
            head = assign(p, ps, record, file, n);//����
            p = head;
        }
        else
        {
            p = callback(head, ps, record, file);//����
            head = p;
        }
    }
    for (i = 1; i <= 100; i++)       //����ͻ��գ�����ڻ��վӶ�
    {
        n = rand() % 10 + 1;//�������1~10����
        if (n >= 5)
        {

            if ((gettop(ps) < n) & (p == NULL)) { i--; continue; }

            head = assign(p, ps, record, file, n);//����
            p = head;

        }
        else
        {
            p = callback(head, ps, record, file);//����
            head = p;
        }
    }
    printf("����������ɺ󣬴����п��еĿ���У�\n\n");
    print(head);
    printf("\n");
    travelstack(ps);
}

