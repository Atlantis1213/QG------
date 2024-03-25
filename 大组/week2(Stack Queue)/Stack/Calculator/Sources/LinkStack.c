#include "LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>
//链栈


//初始化栈
Status initLStack(LinkStack *s){
    if(s->count!=-1)
        return ERROR;//如果已经初始化过则返回error
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
    if(s->count<1)
        return SUCCESS;
    return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(!s->count)
        return ERROR;//如果是空栈返回error
    *e = s->top->data;
    return SUCCESS;
}

//清空栈
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

//销毁栈
Status destroyLStack(LinkStack *s){
    if(!isEmptyLStack(s))
        clearLStack(s);
    return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
    if(!s)
        return ERROR;
    *length = s->count;
    return SUCCESS;
}

//入栈
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

//出栈
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


