#include "LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int performOperation(int oper, int data1, int data2) {
    switch (oper) {
        case 0:
            return data1 + data2;
        case 1:
            return data1 - data2;
        case 2:
            return data1 * data2;
        case 3:
            return data1 / data2;
        default:
            printf("����");
            return 0;
    }
}

int transfer(char i){
    if (i=='+')
        return 0;
    else if (i=='-')
        return 1;
    else if (i=='*')
    return 2;
    else if (i=='/')
        return 3;
    return -1;
}

int precedence(char oper) {//���ȼ��Ƚ�
    if (oper == '+' || oper == '-'||oper == 1 ||oper == 0 ) {
        return 1;
    } else if (oper == '*' || oper == '/'||oper == 2 ||oper == 3) {
        return 2;
    } else {
        return 0;
    }
}

int main()
{
    LinkStack oper,num;//oper��0-+��1--��2-*��3-/��4-����5-��
    LinkStackPtr p;
    oper.count = -1;//����countΪ-1ʱջδ����ʼ��
    num.count = -1;//����countΪ-1ʱջδ����ʼ��
    initLStack(&oper);
    initLStack(&num);
    int a=0,data,data1,data2,oper1,i=0;
    unsigned char flag_data;
    char expression[500];
    printf("����������������ʽ��");
    scanf("%s", expression);
    i = 0;
    while(expression[i]!='\0'){//�����ж�
        if((expression[i]<48||expression[i]>57)&&expression[i]!='+'&&expression[i]!='-'&&expression[i]!='*'&&expression[i]!='/'&&expression[i]!='('&&expression[i]!=')')
        {
            printf("���ݴ���");
            system("pause");
            return 0;
        }
        i++;
    }
    i = 0;
    while(expression[i]!='\0'){
        if(isdigit(expression[i])){
            data = 0;
            while (isdigit(expression[i])){
            data = data * 10 + (expression[i] - '0'); // ��charתΪ����
            i++;
            }
            pushLStack(&num, data);
        }
        else if(expression[i] == '('){
            pushLStack(&oper, 4);
            i++;
        }
        else if (expression[i] == ')') {
            while (!isEmptyLStack(&oper) && oper.top->data != 4) {//�����ջ��Ϊ���Ҳ���������
                popLStack(&num, &data2);
                popLStack(&num, &data1);;
                popLStack(&oper, &oper1);
                int result = performOperation(oper1, data1, data2);
                pushLStack(&num, result);//�������ջ
            }
            if (!isEmptyLStack(&oper) && oper.top->data==4) {
                popLStack(&oper, &data);
            }
            i++;
        }
        else if(expression[i]== '+' ||expression[i]== '-' ||expression[i]== '*' ||expression[i]== '/' ){
            while (!isEmptyLStack(&oper) && precedence(expression[i]) <= precedence((char)oper.top->data)) {//���ȼ�С��վ�ڣ�ȫ����ջ
                popLStack(&num, &data2);
                popLStack(&num, &data1);;
                popLStack(&oper, &oper1);
                int result = performOperation(oper1, data1, data2);
                pushLStack(&num, result);//�������ջ
            }
            pushLStack(&oper, transfer(expression[i]));//����ջ
            i++;
        }
        else
          i++;
    }
         while (!isEmptyLStack(&oper)) {
                popLStack(&num, &data2);
                popLStack(&num, &data1);
                popLStack(&oper, &oper1);
                int result = performOperation(oper1, data1, data2);
                pushLStack(&num, result);//�������ջ
        }
        printf("���Ϊ��%d\n", num.top->data);
        system("pause");
        return 0;
}