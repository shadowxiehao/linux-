#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include "struct.h"
#include "global.c"

struct block* creat(void);   //����100�����0~99�Ŀ飬10��Ϊһ��;
void print(struct block* head);//��ӡ���;
//ʵ��˳��ջ�Ĳ�����ջ���жϡ���ջ����ջ����ȡջ��Ԫ��,����ջ����
void initstack(struct stack* s); //ջ�ĳ�ʼ��
void push(struct stack* s, int e); //��ջ
int gettop(struct stack* s); //���ջ��Ԫ��
int pop(struct stack* s); //��ջ
int judge(struct stack* s); //�ж�ջ�Ƿ�Ϊ��
void travelstack(struct stack* s);//����ջ
struct block* assign(struct block* head, struct stack* s, int record[file_nums], int file[file_nums][10], int n);//��������
struct block* callback(struct block* head, struct stack* s, int record[file_nums], int file[file_nums][10]);//����
void print_linked(struct block* head);//��ӡ����
void print_linked_full(struct block* head);//������ӡ����
void set_position(int x, int y);
int get_position(int i);
void set_position(int x, int y);

void random_show()
{
    system("cls");
    printf("��ӭ���������ʾ!(ÿ�ξ�����ͣ�Ա�鿴���,����������ɼ���)\n\n");
    Sleep(1200);
    system("cls");
    //����ջ�Ϳ�Ľṹ������
    struct stack s;
    struct stack* ps;
    struct block* head, * p;

    int n=0, i=0, m=0, j = 0;//���ڼ����ȵı���
    int d = 30; int f = 5;//�������ͻ��յĴ���
    
    int po1[2] = { 0 }, po2[2] = { 0 };//��¼���λ��

    int file[file_nums][file_max] = { 0 };//�ļ���������¼������ļ��ź����뵽�Ŀ��
    int record[file_nums] = { 0 };//��¼��������¼�ĸ��ļ������˿�
    ps = &s;
    initstack(ps);//��ʼ����ջ
    p = head = creat();
    printf("��ʼʱ:");
    print(head);
    printf("\n");
    printf("��������������,ǰ������������,�������������\n\n");

    printf("ǰ���__");
    po1[0]=get_position(0);
    po1[1] = get_position(1);
    printf("___��, ����__");
    po2[0] = get_position(0);
    po2[1] = get_position(1);
    printf("___�� ?");
    
    set_position(po1[0], po1[1]);
    scanf_s("%d", &d);
    set_position(po2[0], po2[1]);
    scanf_s("%d", &f);

    set_position(0, po2[1]+2);
    
    srand(time(NULL));//�����������
    for (i = 1; i <= d; i++)       //����ͻ��գ�ǰ���ڷ���Ӷ�
    {
        po1[0] = get_position(0);
        po1[1] = get_position(1);//��¼���,�����Ѻû���ʾ

        n = rand() % 10 + 1;//�������1~10����
        printf("ǰ��ε�%d��\n", i);
        if (n >= 3)
        {
            j = rand() % 10 + 1;//�������1~10����
            printf("���з���,");

            if ((gettop(ps) < n) & (p == NULL)) { printf("\n����ջ�Ϳ�������޿ռ�,����ʧ��,��ת����һ��\n\n"); continue; }

            head = assign(p, ps, record, file, j);//����
            p = head;

            printf("ǰ��ε�%d�η������\n", i);
        }
        else
        {
            printf("���л���:\n");

            p = callback(head, ps, record, file);//����
            head = p;

            printf("ǰ��ε�%d�λ������\n", i);
        }
        printf("\n");
        travelstack(ps);
        printf("\n");
        print(head);
        printf("\n");
        
        po2[0] = get_position(0);
        po2[1] = get_position(1);
        set_position(po1[0], po1[1]-1);

        _getch();//�ȴ����������
        set_position(po2[0], po2[1]);
    }
    for (i = 1; i <= f; i++)       //����ͻ��գ�����ڻ��վӶ�
    {
        po1[0] = get_position(0);
        po1[1] = get_position(1);//��¼���,�����Ѻû���ʾ

        n = rand() % 10 + 1;//�������1~10����
        printf("���ε�%d��\n", i);
        if (n >= 7)
        {
            j = rand() % 10 + 1;//�������1~10����
            printf("���з���,");

            if ((gettop(ps) < n) & (p == NULL)) { i--; printf("����\n"); continue; }

            head = assign(p, ps, record, file, j);//����
            p = head;

            printf("���ε�%d�η������\n", i);
        }
        else
        {
            printf("���л���:\n");

            p = callback(head, ps, record, file);//����
            head = p;

            printf("���ε�%d�λ������\n", i);
        }
        printf("\n");
        travelstack(ps);
        printf("\n");
        print(head);
        printf("\n");

        po2[0] = get_position(0);
        po2[1] = get_position(1);
        set_position(po1[0], po1[1]-1);

        _getch();//�ȴ����������
        set_position(po2[0], po2[1]);
    }
    travelstack(ps);
    printf("\n");
    print(head);
    //print_linked_full(head);��ӡ���
    printf("\n\t�����ʾ���");

}

