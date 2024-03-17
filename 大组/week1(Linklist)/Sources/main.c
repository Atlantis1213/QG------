#include <stdio.h>
#include<linkedList.h>
#include<stdlib.h>

void Listprint(ElemType e);

int main()
{
    int a,n,i,data,len;
    LinkedList L,p,temp,q;
    LNode N,M,A,B;
    unsigned char flag=0;
    while(1){
    printf("          *********************************             *********************************\n");
    printf("          *        1.��ʼ������           *             *          2.�����½ڵ�         *\n");
    printf("          *        3.��ת����             *             *          4.�������           *\n");
    printf("          *        5.�м�����             * 11.�˳�ϵͳ *          6.�ж��Ƿ�ɻ�       *\n");
    printf("          *        7.ɾ���ڵ�             *             *          8.��ż��ת           *\n");
    printf("          *        9.��ѯ����             *             *          10.����ѭ������      *\n");
    printf("          *********************************             *********************************\n");
    printf("�������Ӧ����(0-10):");
    scanf("%d", &a);
    switch (a)
    {
        case 1:
            printf("���������ڵ�(������20):");
            scanf("%d", &len);
            while(len<1||len>20)
            {
                printf("���벻�淶,����������");
                scanf("%d", &len);
            }
            InitList(&L);
            printf("�������1���ڵ������:");
            scanf("%d", &(L->data));
            temp = L;
            for (i = 2; i <= len;i++)
            {
                p = (LinkedList)malloc(sizeof(struct LNode));
                printf("�������%d���ڵ������:",i);
                scanf("%d", &(p->data));
                p->next = NULL;
                temp->next = p;
                temp = temp->next;
            }
            printf("�����ʼ���ɹ�\n");
            TraverseList(L, Listprint);
            printf("NULL");
            system("pause");
            break;
        case 2:
            printf("������Ҫ�����ڵڼ����ڵ�֮��:");
            scanf("%d", &n);
            printf("\n");
            while(n<1||n>len)
            {
                printf("���벻�淶,����������");
                scanf("%d", &n);
            }  
            p = (LinkedList)malloc(sizeof(struct LNode));
            printf("������Ҫ���������:");
            scanf("%d", &(p->data));
            q = L;
            for (i = 1; i < n;i++)
            {
                q = q->next;
            }
            InsertList(q, p);
            printf("����������Ϊ��");
            TraverseList(L, Listprint);
            printf("NULL");
            system("pause");
            break;
        case 3:
            if(L==NULL)
                printf("���ȳ�ʼ������");
            ReverseList(&L);
            printf("����ת�ɹ���");
            system("pause");
            break;
        case 4:
             if(L==NULL)
                printf("���ȳ�ʼ������");
            TraverseList(L, Listprint);
            printf("NULL");
            system("pause");
            break;    
        case 5:
            if(L==NULL)
                printf("���ȳ�ʼ������");
            p=FindMidNode(&L);
            printf("�м���������Ϊ%d",p->data);
            system("pause");
            break;
        case 6:
            if(L==NULL)
                printf("���ȳ�ʼ������");
            else if(flag) printf("�����ѳɻ�!");
           else printf("����δ�ɻ�!");
            system("pause");
            break;
        case 7:
            if(L==NULL)
                printf("���ȳ�ʼ������");
            printf("������Ҫɾ���Ľڵ��ڵڼ����ڵ�֮��:");
            scanf("%d", &n);
            while(n<0||n>len-1)
            {
                printf("\n���벻�淶,����������");
                scanf("%d", &n);
            }  
            q = L;
            for (i = 0; i < n;i++)
            {
                q = q->next;
            }
            DeleteList(q,&data);
            printf("�ڵ�ɾ���ɹ���");
            system("pause");
            break;
        case 8:
            if(L==NULL)
                printf("���ȳ�ʼ������");
            ReverseEvenList(&L);
            printf("������ż��ת�ɹ���");
            system("pause");
            break;
        case 9:
            if(L==NULL)
                printf("���ȳ�ʼ������");
            printf("������Ҫ���ҵ�����:");
            scanf("%d", &data);
            if(SearchList(L, data))
                printf("���ڴ�����!");
            printf("�����ڴ�����!");
            system("pause");
            break;
        case 10:
            if(flag==1)
                printf("�����ѳɻ�");
            else if(L==NULL)
                printf("���ȳ�ʼ������");
            else
            {
            p = L;
            while (p->next)
            {
                p = p->next;
            }
            p->next = L;
            flag = 1;
            printf("����ɻ��ɹ�!");
            }
            system("pause");
            break;
            case 11:
            if(L==NULL)
                printf("���˳�ϵͳ!");
            else
            {
                DestroyList(&L);
                printf("����ɾ�����!\n���˳�ϵͳ!");
            }
            system("pause");
            exit(0);
            break;
            default: printf("����������!");
    }

    system("cls");
    }
    return 0;
}


Status InitList(LinkedList *L)
 {
    *L = (LinkedList)malloc(sizeof(struct LNode));
    if (*L == NULL) {
        return ERROR;
    }
    (*L)->next=NULL;
    return SUCCESS;
}

void DestroyList(LinkedList *L)
{
    LinkedList p = *L;
    if(p !=NULL )
    {
        p = p->next;
        free(*L);
        *L = p;
    }
}

Status InsertList(LNode *p, LNode *q)
{
    if (q==NULL||p==NULL)
        return ERROR;
    q->next = p->next;
    p->next = q;
    return SUCCESS;
}

Status DeleteList(LNode *p, ElemType *e)
{
    if(p==NULL||p->next==NULL)
        return ERROR;
    LNode* q = p->next;
    *e = q->data;
    p->next = q->next;
   free(p->next);//直接用free（q）不�?
    return SUCCESS;
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))//visit为自定义函数
{
    LinkedList p;
    p = L;
    while (p!=NULL)
    {
        visit(p->data);
        p = p->next;
    }
    return;
}

Status SearchList(LinkedList L, ElemType e)
{
    LinkedList p;
    p = L->next;
    if(L==NULL)
        return ERROR;//传入空表直接返回
    while(p!=NULL)
    {
        if(p->data==e)
            return SUCCESS;//若找到e则返回success
        p = p->next;
    }//遍历完链表后仍未找到，返回error
    return ERROR;
}

Status ReverseList(LinkedList *L)
{
    LinkedList current,prev,next;
    prev = *L;
    current = (*L)->next;
    prev->next = NULL;
    if(current==NULL||current->next==NULL)
        return ERROR;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *L = prev;
    return SUCCESS;
}

void Listprint(ElemType e)
{
    printf("%d->", e);
}

Status IsLoopList(LinkedList L)
{
    if(L==NULL||L->next==NULL)
    {
        return ERROR;
    }

    LinkedList fast, slow;
    fast = L->next->next;
    slow = L->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast==slow)
            return SUCCESS;
    }
    return ERROR;
}

/*void ReverseEvenList(LinkedList *L) //传入头节点默认为�?
{
    LinkedList cur, R1, L1;

    if ((*L)->next==NULL)
        return ;
    cur = *L;
    L1 = (*L)->next;
    R1 = (*L)->next->next;
    while (cur->next != NULL&&cur->next->next!=NULL)
    {
        cur->next = R1;
        L1->next = R1->next;
        R1->next = L1;
        cur = L1;
    }
    return ;
}*/
LNode* ReverseEvenList(LinkedList *L)
{
	LNode *pre, *cur, *Next;		//定义前中后指针，用途和反转相似
	pre = *L;
	*L = pre->next;
	while(pre && pre->next){
		cur = pre->next;
		Next = cur->next;
		if(cur->next && cur->next->next){			//如果cur->next不存�?，结点个数为偶�??
			pre->next = cur->next->next;			//如果cur->next->next不存�?，结点个数为奇�??
		}else{										//如果都存�?，遍历未结�??
			pre->next = cur->next;
		}
		cur->next = pre;							//将偶数结点反�?
		pre = Next;
	}
	return *L;
}

LNode* FindMidNode(LinkedList *L)
{
    LinkedList mid = *L;
    int cnt;
    for (cnt = 0; mid != NULL;cnt++)
    {
        mid = mid->next;
    }
    mid = *L;
    for (int i = 0; i < cnt / 2;i++)
    {
        mid = mid->next;
    }
    return mid;
}