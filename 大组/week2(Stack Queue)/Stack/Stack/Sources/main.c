#include "LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>


int main()
{
    LinkStack l;
    LinkStackPtr p;
    l.count = -1;//设置count为-1时栈未被初始化
    int a,data;
    unsigned char flag_data;
    while(1)
    {
    printf("          *********************************             *********************************\n");
    printf("          *        1.初始化栈             *             *          2.压栈               *\n");
    printf("          *        3.出栈                 *             *          4.输出栈内元素       *\n");
    printf("          *        5.栈节点个数           *             *          6.栈顶数据           *\n");
    printf("          *        7.清空栈               *             *          8.退出系统           *\n");
    printf("          *********************************             *********************************\n");
    do {
        printf("请输入0到8之间的数字：");
        if (scanf("%d", &a) != 1 || a < 0 || a > 8) {
            printf("输入无效，请重新输入。\n");
            a = 9;
            while (getchar() != '\n'); // 清空输入缓冲区
        }
    }while (a < 0 || a > 8);
    switch (a)
    {
    case 1:
        if(initLStack(&l))
            printf("初始化成功！\n");
        else
            printf("请勿重复初始化\n");
        system("pause");
        break;
    case 2:
        if(l.count==-1){
            printf("请先初始化栈！\n");
            system("pause");
            break;
            }
        do{
            printf("请输入一个整数：");
            flag_data = scanf("%d", &data);
            if(!flag_data){
                printf("数据错误！请输入一个整数！\n");
                while(getchar()!='\n');  //清空缓存区
            }
        } while (!flag_data);
        pushLStack(&l, data);
        printf("压栈成功！");
        system("pause");
        break;
        case 3:
        if(l.count==-1){
            printf("请先初始化栈！\n");
            system("pause");
            break;
        }
        else if(l.count==0){
            printf("栈空！无法出栈");
            system("pause");
            break;
        }
        popLStack(&l, &data);
        printf("出栈成功！出栈数据为：%d", data);
        system("pause");
        break;
        case 4:
        if(l.count==-1){
            printf("请先初始化栈！\n");
            system("pause");
            break;
        }
        else if(l.count==0){
            printf("栈空！无数据\n");
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
            printf("请先初始化栈！\n");
            system("pause");
            break;
        }
        LStackLength(&l, &data);
        printf("栈长为：%d\n", data);
        system("pause");
        break;
        case 6:
        if(l.count==-1){
            printf("请先初始化栈！\n");
            system("pause");
            break;
        }
        else if(l.count==0){
            printf("栈空！无栈顶数据\n");
            system("pause");
            break;
        }
        getTopLStack(&l, &data);
        printf("栈顶数据为：%d", data);
        system("pause");
         break;
        case 7:
        if(l.count==-1){
            printf("请先初始化栈！\n");
            system("pause");
            break;
        }
        clearLStack(&l);
        printf("已清空！");
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