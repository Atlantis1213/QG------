#include "LQueue.h" 
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
    Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
    Node *p = Q->front;
    while(p){
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
    if(Q->length==0)
        return TRUE;
    else
        return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(IsEmptyLQueue(Q))
        return FALSE;//空队列返回错误
    *(void **)e = Q->front->data;//将队列的头结点的数据指针赋值给函数e所指向的内存地址
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (Q->length==0) {
        Q->front = Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    
    Q->length++;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if (IsEmptyLQueue(Q)) {
        return FALSE;
    }
    
    Node *temp = Q->front;
    Q->front = Q->front->next;
    free(temp);
    
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    
    Q->length--;
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
    Node *temp, *p;
    p = Q->front;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    Q->front = Q->rear = NULL;
    Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    if (IsEmptyLQueue(Q)) {
    return FALSE;
    }
    Node *p;
    p = Q->front;
    while (p != NULL) {
        foo(p->data);
        p = p->next;
    }
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){

}


