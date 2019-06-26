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


extern "C" {//使C++兼容C
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

    void draw_stack(struct stack* s) {
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
}