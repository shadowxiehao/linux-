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
           "\t****************** ��ӭʹ�ó���������ʾϵͳV1.0  *************\n"
           "\t********                                              ********\n"
           "\t********            1.������ʾϵͳ                    ********\n"
           "\t********            2.���������ʾ                    ********\n"
           "\t********            3.(ȫͼ����ʾϵͳ)(��չ��ʾ,ʱ�䲻��ʵ��)*\n"
           "\t********            0.�˳�                            ********\n"
           "\t********                                              ********\n"
           "\t******************˵��:Ϊ�˱�����ʾ,��Ĭ��ȡ��С��ʾ��ֵ******\n"
           "\t**************************************************************\n"
           "\t                        ����Ҫִ�е��ǣ�");
}

void active_menu1() {
    printf("\n"
        "\t********             1.����                   ********\n"
        "\t********             2.����                   ********\n"
        "\t********             3.�鿴��ǰջ             ********\n"
        "\t********             4.�鿴��ǰʣ�����       ********\n"
        "\t********             0.������ʾ������         ********\n"
    );
}

int active_menu2(int q) {//��������˵������Ѻû���ʾ
    int po1[2] = { 0 }, po2[2] = { 0 };//��¼���λ��
    int back = 0;
    printf("\n"
           "\t����___" );
    po1[0] = get_position(0); po1[1] = get_position(1);
    printf("____��(Ĭ��1~%d,��ȥ�궨���޸�)", file_max);
    po2[0] = get_position(0); po2[1] = get_position(1);
    set_position(po1[0], po1[1]);
    scanf_s("%d", &back);
    if (back > file_max) {
        set_position(po1[0], po1[1]+3);
        printf("���ڹ涨��ֵ��,����������!");
        po2[0] = get_position(0); po2[1] = get_position(1);
        Sleep(1500);
        reset_clear(q, po2[1]);
        return 0;
    }
    reset_clear(q,po2[1]);
    printf("����%d��:\n", back);
    Sleep(500);

    return back;
}

int active_menu3(int q) {//�������ղ˵������Ѻû���ʾ
    int  po2[2] = { 0 };//��¼���λ��
    po2[0] = get_position(0); po2[1] = get_position(1);
    reset_clear(q, po2[1]);
    printf("����:\n");
    return 0;
}
int active_menu4(int q) {//�����˵��Ѻû���ʾ
    int  po2[2] = { 0 };//��¼���λ��
    po2[0] = get_position(0); po2[1] = get_position(1);
    reset_clear(q, po2[1]);
    return 0;
}