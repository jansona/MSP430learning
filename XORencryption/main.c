#include <stdio.h>
#include <stdlib.h>
#include "xor.h"

int main()
{
    char key = '&';
    int ctrl = 0;
    wchar_t safety = '0';
    //scanf("%c", &key);

    /**********************************************************
    ����ĳ��δ֪��ԭ�򣬻�����λ��Ĳ��죬ÿ�ν�����Ҫ��
    ���ַ�safetyת��Ϊ����ctrlʱ�������������������������
    �磬safety��Ϊ��2����������0 2������������λ2��ǰ����
    ����scanf������䡣��Ҫ�۲�����󣬿ɽ���ע�Ͷ��ϵ���
    �� fflush(stdin) ���Ρ�
    ***********************************************************/
    printf("��ӭʹ��XOR�����ݼ���/�������Console�棬�˰汾��֧�ֶ�Ӧ��ASCII����Ԫ�صĲ��������鲻Ҫʹ������\
\����ϵͳ���������ݴ��һ��޷�ʵ�ּ��ܡ�\n");
    printf("���������/����ʱʹ�õ���Կ�����ַ�����");
    scanf("%c", &key);
    MARK:
    fflush(stdin);
    printf("������������ֹ���ģʽ:\n");
    printf("1. c2c \n2. c2f(newdata.txt) \n3. f2c(origindata.txt) \n4. f2f \n5. �˳�\n");
    printf("�������Ӧ��Ų��Իس���(\\n)������");
    scanf("%c", &safety);
    if((safety<='z' && safety>='a') || (safety<='Z' && safety>='A'))
    {
        printf("\nfuck off\n");
        exit(0);
    }
    ctrl = (long)_wtoi(&safety);
    //printf("%d\n", ctrl);
    switch(ctrl)
    {
        case 1: xor_c2c(key); goto MARK;
        case 2: xor_c2f(key); goto MARK;
        case 3: xor_f2c(key); goto MARK;
        case 4: xor_f2f(key); goto MARK;
        case 5: break;
        default : printf("\n��������ѡ�ƥ�䣬���������롣\n\n"); goto MARK;
    }
    return 0;
}
