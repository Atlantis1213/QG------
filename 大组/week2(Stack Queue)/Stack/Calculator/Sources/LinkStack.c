#include "LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>
//��ջ


//��ʼ��ջ
Status initLStack(LinkStack *s){
    if(s->count!=-1)
        return ERROR;//����Ѿ���ʼ�����򷵻�error
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
    if(s->count<1)
        return SUCCESS;
    return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(!s->count)
        return ERROR;//����ǿ�ջ����error
    *e = s->top->data;
    return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
    LinkStackPtr p, q;
    if(!s)
        return ERROR;
    p = s->top;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    s->count = 0;
    s->top = NULL;
    return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s){
    if(!isEmptyLStack(s))
        clearLStack(s);
    return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
    if(!s)
        return ERROR;
    *length = s->count;
    return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
    LinkStackPtr a;
    if(s->count==-1)
        return ERROR;
    a = (LinkStackPtr)malloc(sizeof(StackNode));
    a->data = data;
    a->next = s->top;
    s->top = a;
    s->count++;
    return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
    if(s->count<1)
        return ERROR;
    LinkStackPtr p;
    p = s->top;
    *data = s->top->data;
    s->top = s->top->next;
    s->count--;
    free(p);
    return SUCCESS;
}


