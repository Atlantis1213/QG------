#include "LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>


int main()
{
    LinkStack l;
    LinkStackPtr p;
    l.count = -1;//����countΪ-1ʱջδ����ʼ��
    int a,data;
    unsigned char flag_data;
    while(1)
    {
    printf("          *********************************             *********************************\n");
    printf("          *        1.��ʼ��ջ             *             *          2.ѹջ               *\n");
    printf("          *        3.��ջ                 *             *          4.���ջ��Ԫ��       *\n");
    printf("          *        5.ջ�ڵ����           *             *          6.ջ������           *\n");
    printf("          *        7.���ջ               *             *          8.�˳�ϵͳ           *\n");
    printf("          *********************************             *********************************\n");
    do {
        printf("������0��8֮������֣�");
        if (scanf("%d", &a) != 1 || a < 0 || a > 8) {
            printf("������Ч�����������롣\n");
            a = 9;
            while (getchar() != '\n'); // ������뻺����
        }
    }while (a < 0 || a > 8);
    switch (a)
    {
    case 1:
        if(initLStack(&l))
            printf("��ʼ���ɹ���\n");
        else
            printf("�����ظ���ʼ��\n");
        system("pause");
        break;
    case 2:
        if(l.count==-1){
            printf("���ȳ�ʼ��ջ��\n");
            system("pause");
            break;
            }
        do{
            printf("������һ��������");
            flag_data = scanf("%d", &data);
            if(!flag_data){
                printf("���ݴ���������һ��������\n");
                while(getchar()!='\n');  //��ջ�����
            }
        } while (!flag_data);
        pushLStack(&l, data);
        printf("ѹջ�ɹ���");
        system("pause");
        break;
        case 3:
        if(l.count==-1){
            printf("���ȳ�ʼ��ջ��\n");
            system("pause");
            break;
        }
        else if(l.count==0){
            printf("ջ�գ��޷���ջ");
            system("pause");
            break;
        }
        popLStack(&l, &data);
        printf("��ջ�ɹ�����ջ����Ϊ��%d", data);
        system("pause");
        break;
        case 4:
        if(l.count==-1){
            printf("���ȳ�ʼ��ջ��\n");
            system("pause");
            break;
        }
        else if(l.count==0){
            printf("ջ�գ�������\n");
            system("pause");
            break;
        }
        p = l.top;
        do {
            printf("%d", p->data);
            printf("->");
            p = p->next;
        } while (p);
        printf("NULL");
        system("pause");
        break;
        case 5:
        if(l.count==-1){
            printf("���ȳ�ʼ��ջ��\n");
            system("pause");
            break;
        }
        LStackLength(&l, &data);
        printf("ջ��Ϊ��%d\n", data);
        system("pause");
        break;
        case 6:
        if(l.count==-1){
            printf("���ȳ�ʼ��ջ��\n");
            system("pause");
            break;
        }
        else if(l.count==0){
            printf("ջ�գ���ջ������\n");
            system("pause");
            break;
        }
        getTopLStack(&l, &data);
        printf("ջ������Ϊ��%d", data);
        system("pause");
         break;
        case 7:
        if(l.count==-1){
            printf("���ȳ�ʼ��ջ��\n");
            system("pause");
            break;
        }
        clearLStack(&l);
        printf("����գ�");
        system("pause");
        break;
        case 8:
            exit(0);
    default : 
        system("pause");
        break;
    }

    system("cls");
    }
    return 0;
}