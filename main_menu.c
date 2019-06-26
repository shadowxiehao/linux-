#include<Windows.h>
#include<stdio.h>
#include"global.c"

int get_position(int i);
void set_position(int x, int y);
void reset_clear(int y1, int y2);

void main_menu()
{
    system("cls");
    printf("\t**************************************************************\n"
           "\t****************** 欢迎使用成组链接演示系统V1.0  *************\n"
           "\t********                                              ********\n"
           "\t********            1.主动演示系统                    ********\n"
           "\t********            2.随机生成演示                    ********\n"
           "\t********            3.(全图形演示系统)(扩展演示,时间不足实现)*\n"
           "\t********            0.退出                            ********\n"
           "\t********                                              ********\n"
           "\t******************说明:为了便于演示,均默认取较小演示数值******\n"
           "\t**************************************************************\n"
           "\t                        您需要执行的是：");
}

void active_menu1() {
    printf("\n"
        "\t********             1.分配                   ********\n"
        "\t********             2.回收                   ********\n"
        "\t********             3.查看当前栈             ********\n"
        "\t********             4.查看当前剩余块组       ********\n"
        "\t********             0.结束演示并返回         ********\n"
    );
}

int active_menu2(int q) {//主动分配菜单附加友好化显示
    int po1[2] = { 0 }, po2[2] = { 0 };//记录光标位置
    int back = 0;
    printf("\n"
           "\t申请___" );
    po1[0] = get_position(0); po1[1] = get_position(1);
    printf("____个(默认1~%d,可去宏定义修改)", file_max);
    po2[0] = get_position(0); po2[1] = get_position(1);
    set_position(po1[0], po1[1]);
    scanf_s("%d", &back);
    if (back > file_max) {
        set_position(po1[0], po1[1]+3);
        printf("不在规定数值内,请重新输入!");
        po2[0] = get_position(0); po2[1] = get_position(1);
        Sleep(1500);
        reset_clear(q, po2[1]);
        return 0;
    }
    reset_clear(q,po2[1]);
    printf("分配%d个:\n", back);
    Sleep(500);

    return back;
}

int active_menu3(int q) {//主动回收菜单附加友好化显示
    int  po2[2] = { 0 };//记录光标位置
    po2[0] = get_position(0); po2[1] = get_position(1);
    reset_clear(q, po2[1]);
    printf("回收:\n");
    return 0;
}
int active_menu4(int q) {//单纯菜单友好化显示
    int  po2[2] = { 0 };//记录光标位置
    po2[0] = get_position(0); po2[1] = get_position(1);
    reset_clear(q, po2[1]);
    return 0;
}