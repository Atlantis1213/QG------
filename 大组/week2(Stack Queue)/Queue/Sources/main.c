#include "LQueue.h" 
#include<stdio.h>
#include<stdlib.h>

void getdata(void **data,char i) {
    switch (i)
    {case 'a':
        printf("请输入数据：");
        int *p = (int*)malloc(sizeof(int));
        scanf_s("%d", p);
        *data = (void*)p;
        break;
    case 'b':
        printf("请输入数据：");
        char* q = (char*)malloc(sizeof(char));
        scanf_s("%c", q);
        scanf_s("%c", q);
        *data = (void*)q;
        break;
    case 'c':
        printf("请输入数据：");
        float* r = (float*)malloc(sizeof(float));
        scanf_s("%f", r);
        *data = (void*)r;
        break;
    default:
        printf("数据错误！");
        break;
    }
}

void printdata(void* data,int j) {
    switch (datatype[j])
    {
    case 'a':
        printf("%d", *(int*)data);
        break;
    case 'b':
        printf("%c", *(char*)data);
        break;
    case 'c':
        printf("%f", *(float*)data);
        break;;
    default:
        printf("数据错误！");
        break;
    }
}


int main() {
    int k,a;
    void* data;
    datatype[1] = 0;
    int j = 1,c = 1;
    LQueue l;
    l.length = -1;
    while (1)
    {
        printf("          *********************************             *********************************\n");
        printf("          *        1.初始化队列           *             *          2.入队               *\n");
        printf("          *        3.出队                 *             *          4.输出队内元素       *\n");
        printf("          *        5.队列节点个数         *             *          6.输出队头元素       *\n");
        printf("          *        7.清空队列             *             *          8.退出系统           *\n");
        printf("          *********************************             *********************************\n");
        do {
            printf("请输入0到8之间的数字：");
            if (scanf_s("%d", &a) != 1 || a < 0 || a > 8) {
                printf("输入无效，请重新输入。\n");
                a = 9;
                while (getchar() != '\n'); // 清空输入缓冲区
            }
        } while (a < 0 || a > 8);
        switch (a)
        {
        case 1:
            if (l.length != -1) {
                printf("请勿重复初始化！\n");
                break;
            }
            InitLQueue(&l);
            printf("初始化成功！");
            break;
        case 2:
            if (l.length == -1) {
                printf("请先初始化队列！");
                break;
            }
            printf("请选择你要存储的数据，a-int b-char c-float:");
            scanf_s("%c", &datatype[j]);
            scanf_s("%c", &datatype[j]);
            if (datatype[j] != 'a' && datatype[j] != 'b' && datatype[j] != 'c') {
                printf("请按照格式输入！\n");
                break;
            }
            getdata(&data, datatype[j]);
            EnLQueue(&l, data);
            j++;
            printf("入队成功！\n");
            break;
        case 3:
            if (l.length == -1) {
                printf("请先初始化队列！");
                break;
            }
            else if (l.length == 0) {
                printf("队空，无法出队！");
                break;
            }
            DeLQueue(&l);
            printf("出队成功！");
            c++;
            break;
        case 4:
            if (l.length == -1) {
                printf("请先初始化队列！");
                break;
            }
            else if (l.length == 0) {
                printf("队空！");
                break;
            }
            k = c;
            Node* temp = l.front; // 用临时指针保存队列的头指针

            while (temp != NULL) {
                printdata(temp->data, k);
                printf("->");
                k++;
                temp = temp->next;
            }

            printf("NULL\n");
            break;

        case 5:
            if (l.length == -1) {
                printf("请先初始化队列！");
                break;
            }
            printf("队列节点个数为：%d", l.length);
            printf("\n");
            break;
        case 6:
            if (l.length == -1) {
                printf("请先初始化队列！");
                break;
            }
            else if (l.length == 0) {
                printf("队空！");
                break;
            }
            printf("队头元素为：");
            printdata(l.front->data, c);
            printf("\n");
            break;
        case 7:
            if (l.length == -1) {
                printf("请先初始化队列！");
                break;
            }
            ClearLQueue(&l);
            j = c = 1;
            printf("已清空！");
            printf("\n");
            break;
        case 8:
            exit(0);

        default:
            break;
        }
        system("pause");
        system("cls");
    }

    system("pause");
    return 0;
}