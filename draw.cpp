/*��Ҫ�����ͼ,��һ������˼����Դ���,ʹ��C++�������C�е���*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include "struct.h"

LOGFONT f;

void refont() {
    gettextstyle(&f);						// ��ȡ��ǰ��������
    setbkmode(TRANSPARENT);//�������屳��͸��
    _tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱
    //f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ����� 
    f.lfHeight = 25;						// ��������߶�Ϊ 48

    settextstyle(&f);						// ����������ʽ
}

void reouttext(int m) {//�������
    // �����ֵ���Ƚ����ָ�ʽ�����Ϊ�ַ���
    char s[5];
    sprintf_s(s, "%d", m);
    outtext(s);
}


extern "C" {//ʹC++����C,�ܹ���C���е���
    void draw_block_help(struct block* head)//��ӡ���
    {
        struct block* p; int n = 0;//n����ÿ10������
        p = head;
        int count1 = 0,count2=0;//�����м���

        if (head != NULL) {
            do
            {
                moveto((40 * count1++) + 10, 10 + (40 * count2));
                reouttext(p->num);
                n++;
                if (n % 10 == 0) {
                    count2++;
                    count1 = 0;
                }
                p = p->next;
            } while (p != NULL);
        }
    }
    void draw_stack_help(struct stack* s) //����ջ����ӡ
    {
        struct stack f = *s;
        struct stack* ff = &f;//����ff��������s,��ֹ��ȡʱ���s�ı仯
        int e;//�������
        int count = 0;
        while (ff->base != ff->top)
        {
            e = *(--(ff->top));//ԭΪe = *(--(s->top));
            moveto(80, 10+40*(count++));
            reouttext(e);
        }
        printf("\n");
    }

    void draw_stack(struct stack* s) {//��ͼ_ջ
        initgraph(200, 440,SHOWCONSOLE);//��ʼ�����ڴ�С,ͬʱ��ʾ����̨
        setbkcolor(WHITE);
        cleardevice();
        setcolor(BLACK);
        refont();//��������

        setlinecolor(DARKGRAY);
        setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 2);

        for (int i = 40; i <= 440; i += 40) {
            line(0, i, 200, i);
        }

        setfillcolor(0x00FF00);
        fillrectangle(0,0,200,40);

        setfillcolor(0xFFFFCC);
        for (int i = 40; i <= 440; i += 40) {
            fillrectangle(0, i, 200, i+40);
        }

        draw_stack_help(s);//��ջ����������

        _getch();					//�������
        closegraph();			 //�رջ�ͼ����
        //system("pause");
    }
    void draw_block(struct block* head) {//��ͼ_����
        initgraph(400, 400, SHOWCONSOLE);//��ʼ�����ڴ�С,ͬʱ��ʾ����̨
        setbkcolor(WHITE);
        cleardevice();
        setcolor(BLACK);
        refont();//��������

        setlinecolor(DARKGRAY);
        setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 2);

        setfillcolor(0xFFDEAD);////��1����ɫ
        fillrectangle(0, 0, 400, 40);

        setfillcolor(0xEE6AA7);//2
        fillrectangle(0, 40, 400, 80);

        setfillcolor(0xFFB6C1);//3
        fillrectangle(0, 80, 400, 120);

        setfillcolor(0xEE00EE);//4
        fillrectangle(0, 120, 400, 160);

        setfillcolor(0x00EE00);//5
        fillrectangle(0, 160, 400, 200);

        setfillcolor(0xFF69B4);//6
        fillrectangle(0, 200, 400, 240);

        setfillcolor(0xFF3030);//7
        fillrectangle(0, 240, 400, 280);

        setfillcolor(0xADFF2F);//8
        fillrectangle(0, 280, 400, 320);

        setfillcolor(0xFFB90F);//��9����ɫ
        fillrectangle(0, 320, 400, 360);

        setfillcolor(0xFF00FF);//��10����ɫ
        fillrectangle(0, 360, 400, 400);

        for (int i = 40; i <= 400; i += 40) {
            line(0, i, 400, i);
        }
        for (int i = 40; i <= 400; i += 40) {
            line(i, 0, i, 400);
        }

        draw_block_help(head);

        _getch();					//�������
        closegraph();			 //�رջ�ͼ����
    }
}