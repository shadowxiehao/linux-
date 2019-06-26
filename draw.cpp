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


extern "C" {//ʹC++����C
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

    void draw_stack(struct stack* s) {
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
}