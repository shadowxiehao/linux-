#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include "struct.h"

struct block* creat(void);   //����100�����0~99�Ŀ飬10��Ϊһ��;
void print(struct block* head);//��ӡ���;
//ʵ��˳��ջ�Ĳ�����ջ���жϡ���ջ����ջ����ȡջ��Ԫ��,����ջ����
void initstack(struct stack* s); //ջ�ĳ�ʼ��
void push(struct stack* s, int e); //��ջ
int gettop(struct stack* s); //���ջ��Ԫ��
int pop(struct stack* s); //��ջ
int judge(struct stack* s); //�ж�ջ�Ƿ�Ϊ��
void travelstack(struct stack* s);//����ջ
struct block* assign(struct block* head, struct stack* s, int record[100], int file[100][10], int n);//��������
struct block* callback(struct block* head, struct stack* s, int record[100], int file[100][10]);//����
void print_linked(struct block* head);//��ӡ����
void print_linked_full(struct block* head);//������ӡ����

void first()
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

    for (i = 1; i <= 5; i++)       //����ͻ��գ�����ڻ��վӶ�
    {
        n = rand() % 10 + 1;//�������1~10����
        printf("��%d��,%d\n",i,n);
        if (n >= 4)
        {

            if ((gettop(ps) < n) & (p == NULL)) { i--; printf("����\n"); continue; }

            head = assign(p, ps, record, file, 10);//����
            p = head;

        }
        else
        {
            p = callback(head, ps, record, file);//����
            head = p;
        }
        printf("��%d��,%d done\n",i, n);
        printf("\n");
        print(head);
        printf("\n");
        travelstack(ps);
        printf("\n");
        print_linked(head);
    }
    printf("����������ɺ󣬴����п��еĿ���У�\n\n");
    print(head);
    printf("\n");
    travelstack(ps);
    print_linked_full(head);
}

