/*������ʾ���ܵĺ���*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include "struct.h"
#include "global.c"

struct block* creat(void);   //����100�����0~99�Ŀ飬10��Ϊһ��;
void print_block(struct block* head);//��ӡ���;
//ʵ��˳��ջ�Ĳ�����ջ���жϡ���ջ����ջ����ȡջ��Ԫ��,����ջ����
void initstack(struct stack* s); //ջ�ĳ�ʼ��
void travel_stack(struct stack* s);//����ջ
struct block* assign(struct block* head, struct stack* s, int record[file_nums], int file[file_nums][10], int n);//��������
struct block* callback(struct block* head, struct stack* s, int record[file_nums], int file[file_nums][10]);//����
//void print_linked(struct block* head);//��ӡ����
//void print_linked_full(struct block* head);//������ӡ����
int get_position(int i);
void set_position(int x, int y);
void active_menu1();
int active_menu2(int q);
int active_menu3(int q);
int active_menu4(int q);
void draw_stack(struct stack* s);//��ͼ_ջ
void draw_block(struct block* head);//��ͼ ��

//����ջ�Ϳ�Ľṹ������
struct stack s;
struct stack* ps;
struct block* head, * p;

int file[file_nums][file_max] = { 0 };//�ļ���������¼������ļ��ź����뵽�Ŀ��
int record[file_nums] = { 0 };//��¼��������¼�ĸ��ļ������˿�

int active_assign(int f) {
    if (f == 0) {//������
        return 1;
    }
    head = assign(p, ps, record, file, f);//����
    p = head;

    return 0;
}
int active_callback() {
    p = callback(head, ps, record, file);//����
    head = p;
}
int active_travelstack(){
    travel_stack(ps);
    draw_stack(ps);
    return 0;
}
int active_print() {
    print_block(head);
    draw_block(head);
}

void active_show()
{
    system("color f0\n");
    system("cls");
    printf("��ӭ����������ʾ!\n\n");
    Sleep(850);
    system("cls");

    int n = 0, i = 0, m = 0, j = 0;//���ڼ����ȵı���
    int d = 30; int f = 5;//�������ͻ��յĴ���

    int po1[2] = { 0 }, po2[2] = { 0 };//��¼���λ��

    ps = &s;
    initstack(ps);//��ʼ����ջ
    p = head = creat();
    printf("\n");

    while (1) {//������ʾ���˵�
            int k = 10, f = 0;

            po1[0] = get_position(0); po1[1] = get_position(1);
            active_menu1();
            po2[0] = get_position(0); po2[1] = get_position(1);
            //scanf_s("%d", &k);
            if ((k = _getch()) == '\n') {//������������س�ʽ����k
                k = _getch();
            }
            switch (k)
            {
            case '1':  f=active_menu2(po1[1]);  active_assign(f); break;
            case '2': active_menu3(po1[1]); active_callback(); break;
            case '3': active_menu4(po1[1]); active_travelstack(); break;
            case '4': active_menu4(po1[1]); active_print(); break;
            case '0':return;
            default: {active_menu4(po1[1]); break; }
            }

            printf("\n\t\t\t�����������");
            //������������İ����������
            po2[1] = get_position(1);
            _getch();
            printf("%c[2K", 27);//�����ǰ������
            set_position(0, po2[1] - 1);
    }
    printf("\n\t������ʾ���");
}

