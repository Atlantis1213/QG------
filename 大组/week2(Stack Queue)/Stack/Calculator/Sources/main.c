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
            printf("错误");
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

int precedence(char oper) {//优先级比较
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
    LinkStack oper,num;//oper中0-+，1--，2-*，3-/，4-（，5-）
    LinkStackPtr p;
    oper.count = -1;//设置count为-1时栈未被初始化
    num.count = -1;//设置count为-1时栈未被初始化
    initLStack(&oper);
    initLStack(&num);
    int a=0,data,data1,data2,oper1,i=0;
    unsigned char flag_data;
    char expression[500];
    printf("请输入四则运算表达式：");
    scanf("%s", expression);
    i = 0;
    while(expression[i]!='\0'){//数据判断
        if((expression[i]<48||expression[i]>57)&&expression[i]!='+'&&expression[i]!='-'&&expression[i]!='*'&&expression[i]!='/'&&expression[i]!='('&&expression[i]!=')')
        {
            printf("数据错误！");
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
            data = data * 10 + (expression[i] - '0'); // 将char转为整形
            i++;
            }
            pushLStack(&num, data);
        }
        else if(expression[i] == '('){
            pushLStack(&oper, 4);
            i++;
        }
        else if (expression[i] == ')') {
            while (!isEmptyLStack(&oper) && oper.top->data != 4) {//运算符栈不为空且不是左括号
                popLStack(&num, &data2);
                popLStack(&num, &data1);;
                popLStack(&oper, &oper1);
                int result = performOperation(oper1, data1, data2);
                pushLStack(&num, result);//将结果入栈
            }
            if (!isEmptyLStack(&oper) && oper.top->data==4) {
                popLStack(&oper, &data);
            }
            i++;
        }
        else if(expression[i]== '+' ||expression[i]== '-' ||expression[i]== '*' ||expression[i]== '/' ){
            while (!isEmptyLStack(&oper) && precedence(expression[i]) <= precedence((char)oper.top->data)) {//优先级小于站内，全部出栈
                popLStack(&num, &data2);
                popLStack(&num, &data1);;
                popLStack(&oper, &oper1);
                int result = performOperation(oper1, data1, data2);
                pushLStack(&num, result);//将结果入栈
            }
            pushLStack(&oper, transfer(expression[i]));//再入栈
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
                pushLStack(&num, result);//将结果入栈
        }
        printf("结果为：%d\n", num.top->data);
        system("pause");
        return 0;
}