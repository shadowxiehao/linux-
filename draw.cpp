/*主要负责绘图,这一块进行了兼容性处理,使其C++库得以在C中调用*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include "struct.h"

LOGFONT f;

void refont() {
    gettextstyle(&f);						// 获取当前字体设置
    setbkmode(TRANSPARENT);//设置字体背景透明
    _tcscpy_s(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”
    //f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿 
    f.lfHeight = 25;						// 设置字体高度为 48

    settextstyle(&f);						// 设置字体样式
}

void reouttext(int m) {//输出数字
    // 输出数值，先将数字格式化输出为字符串
    char s[5];
    sprintf_s(s, "%d", m);
    outtext(s);
}


extern "C" {//使C++兼容C,能够从C进行调用
    void draw_block_help(struct block* head)//打印块号
    {
        struct block* p; int n = 0;//n用来每10个换行
        p = head;
        int count1 = 0,count2=0;//行与列计数

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
    void draw_stack_help(struct stack* s) //遍历栈并打印
    {
        struct stack f = *s;
        struct stack* ff = &f;//这里ff用来复制s,防止读取时造成s的变化
        int e;//用来输出
        int count = 0;
        while (ff->base != ff->top)
        {
            e = *(--(ff->top));//原为e = *(--(s->top));
            moveto(80, 10+40*(count++));
            reouttext(e);
        }
        printf("\n");
    }

    void draw_stack(struct stack* s) {//绘图_栈
        initgraph(200, 440,SHOWCONSOLE);//初始化窗口大小,同时显示控制台
        setbkcolor(WHITE);
        cleardevice();
        setcolor(BLACK);
        refont();//设置字体

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

        draw_stack_help(s);//将栈中数据填入

        _getch();					//按任意键
        closegraph();			 //关闭绘图窗口
        //system("pause");
    }
    void draw_block(struct block* head) {//绘图_块组
        initgraph(400, 400, SHOWCONSOLE);//初始化窗口大小,同时显示控制台
        setbkcolor(WHITE);
        cleardevice();
        setcolor(BLACK);
        refont();//设置字体

        setlinecolor(DARKGRAY);
        setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 2);

        setfillcolor(0xFFDEAD);////第1次填色
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

        setfillcolor(0xFFB90F);//第9次填色
        fillrectangle(0, 320, 400, 360);

        setfillcolor(0xFF00FF);//第10次填色
        fillrectangle(0, 360, 400, 400);

        for (int i = 40; i <= 400; i += 40) {
            line(0, i, 400, i);
        }
        for (int i = 40; i <= 400; i += 40) {
            line(i, 0, i, 400);
        }

        draw_block_help(head);

        _getch();					//按任意键
        closegraph();			 //关闭绘图窗口
    }
}