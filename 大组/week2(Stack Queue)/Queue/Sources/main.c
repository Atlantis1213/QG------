#include "LQueue.h" 
#include<stdio.h>
#include<stdlib.h>

void getdata(void **data,char i) {
    switch (i)
    {case 'a':
        printf("���������ݣ�");
        int *p = (int*)malloc(sizeof(int));
        scanf_s("%d", p);
        *data = (void*)p;
        break;
    case 'b':
        printf("���������ݣ�");
        char* q = (char*)malloc(sizeof(char));
        scanf_s("%c", q);
        scanf_s("%c", q);
        *data = (void*)q;
        break;
    case 'c':
        printf("���������ݣ�");
        float* r = (float*)malloc(sizeof(float));
        scanf_s("%f", r);
        *data = (void*)r;
        break;
    default:
        printf("���ݴ���");
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
        printf("���ݴ���");
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
        printf("          *        1.��ʼ������           *             *          2.���               *\n");
        printf("          *        3.����                 *             *          4.�������Ԫ��       *\n");
        printf("          *        5.���нڵ����         *             *          6.�����ͷԪ��       *\n");
        printf("          *        7.��ն���             *             *          8.�˳�ϵͳ           *\n");
        printf("          *********************************             *********************************\n");
        do {
            printf("������0��8֮������֣�");
            if (scanf_s("%d", &a) != 1 || a < 0 || a > 8) {
                printf("������Ч�����������롣\n");
                a = 9;
                while (getchar() != '\n'); // ������뻺����
            }
        } while (a < 0 || a > 8);
        switch (a)
        {
        case 1:
            if (l.length != -1) {
                printf("�����ظ���ʼ����\n");
                break;
            }
            InitLQueue(&l);
            printf("��ʼ���ɹ���");
            break;
        case 2:
            if (l.length == -1) {
                printf("���ȳ�ʼ�����У�");
                break;
            }
            printf("��ѡ����Ҫ�洢�����ݣ�a-int b-char c-float:");
            scanf_s("%c", &datatype[j]);
            scanf_s("%c", &datatype[j]);
            if (datatype[j] != 'a' && datatype[j] != 'b' && datatype[j] != 'c') {
                printf("�밴�ո�ʽ���룡\n");
                break;
            }
            getdata(&data, datatype[j]);
            EnLQueue(&l, data);
            j++;
            printf("��ӳɹ���\n");
            break;
        case 3:
            if (l.length == -1) {
                printf("���ȳ�ʼ�����У�");
                break;
            }
            else if (l.length == 0) {
                printf("�ӿգ��޷����ӣ�");
                break;
            }
            DeLQueue(&l);
            printf("���ӳɹ���");
            c++;
            break;
        case 4:
            if (l.length == -1) {
                printf("���ȳ�ʼ�����У�");
                break;
            }
            else if (l.length == 0) {
                printf("�ӿգ�");
                break;
            }
            k = c;
            Node* temp = l.front; // ����ʱָ�뱣����е�ͷָ��

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
                printf("���ȳ�ʼ�����У�");
                break;
            }
            printf("���нڵ����Ϊ��%d", l.length);
            printf("\n");
            break;
        case 6:
            if (l.length == -1) {
                printf("���ȳ�ʼ�����У�");
                break;
            }
            else if (l.length == 0) {
                printf("�ӿգ�");
                break;
            }
            printf("��ͷԪ��Ϊ��");
            printdata(l.front->data, c);
            printf("\n");
            break;
        case 7:
            if (l.length == -1) {
                printf("���ȳ�ʼ�����У�");
                break;
            }
            ClearLQueue(&l);
            j = c = 1;
            printf("����գ�");
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