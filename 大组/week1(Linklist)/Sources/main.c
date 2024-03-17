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
    printf("          *        1.初始化链表           *             *          2.插入新节点         *\n");
    printf("          *        3.反转链表             *             *          4.输出链表           *\n");
    printf("          *        5.中间链表             * 11.退出系统 *          6.判断是否成环       *\n");
    printf("          *        7.删除节点             *             *          8.奇偶反转           *\n");
    printf("          *        9.查询链表             *             *          10.构造循环链表      *\n");
    printf("          *********************************             *********************************\n");
    printf("请输入对应数字(0-10):");
    scanf("%d", &a);
    switch (a)
    {
        case 1:
            printf("创建几个节点(不超过20):");
            scanf("%d", &len);
            while(len<1||len>20)
            {
                printf("输入不规范,请重新输入");
                scanf("%d", &len);
            }
            InitList(&L);
            printf("请输入第1个节点的数据:");
            scanf("%d", &(L->data));
            temp = L;
            for (i = 2; i <= len;i++)
            {
                p = (LinkedList)malloc(sizeof(struct LNode));
                printf("请输入第%d个节点的数据:",i);
                scanf("%d", &(p->data));
                p->next = NULL;
                temp->next = p;
                temp = temp->next;
            }
            printf("链表初始化成功\n");
            TraverseList(L, Listprint);
            printf("NULL");
            system("pause");
            break;
        case 2:
            printf("请输入要插入在第几个节点之后:");
            scanf("%d", &n);
            printf("\n");
            while(n<1||n>len)
            {
                printf("输入不规范,请重新输入");
                scanf("%d", &n);
            }  
            p = (LinkedList)malloc(sizeof(struct LNode));
            printf("请输入要插入的数据:");
            scanf("%d", &(p->data));
            q = L;
            for (i = 1; i < n;i++)
            {
                q = q->next;
            }
            InsertList(q, p);
            printf("插入后的链表为：");
            TraverseList(L, Listprint);
            printf("NULL");
            system("pause");
            break;
        case 3:
            if(L==NULL)
                printf("请先初始化链表");
            ReverseList(&L);
            printf("链表反转成功！");
            system("pause");
            break;
        case 4:
             if(L==NULL)
                printf("请先初始化链表");
            TraverseList(L, Listprint);
            printf("NULL");
            system("pause");
            break;    
        case 5:
            if(L==NULL)
                printf("请先初始化链表");
            p=FindMidNode(&L);
            printf("中间链表数据为%d",p->data);
            system("pause");
            break;
        case 6:
            if(L==NULL)
                printf("请先初始化链表");
            else if(flag) printf("链表已成环!");
           else printf("链表未成环!");
            system("pause");
            break;
        case 7:
            if(L==NULL)
                printf("请先初始化链表");
            printf("请输入要删除的节点在第几个节点之后:");
            scanf("%d", &n);
            while(n<0||n>len-1)
            {
                printf("\n输入不规范,请重新输入");
                scanf("%d", &n);
            }  
            q = L;
            for (i = 0; i < n;i++)
            {
                q = q->next;
            }
            DeleteList(q,&data);
            printf("节点删除成功！");
            system("pause");
            break;
        case 8:
            if(L==NULL)
                printf("请先初始化链表");
            ReverseEvenList(&L);
            printf("链表奇偶反转成功！");
            system("pause");
            break;
        case 9:
            if(L==NULL)
                printf("请先初始化链表");
            printf("请输入要查找的数据:");
            scanf("%d", &data);
            if(SearchList(L, data))
                printf("存在此数据!");
            printf("不存在此数据!");
            system("pause");
            break;
        case 10:
            if(flag==1)
                printf("链表已成环");
            else if(L==NULL)
                printf("请先初始化链表");
            else
            {
            p = L;
            while (p->next)
            {
                p = p->next;
            }
            p->next = L;
            flag = 1;
            printf("链表成环成功!");
            }
            system("pause");
            break;
            case 11:
            if(L==NULL)
                printf("已退出系统!");
            else
            {
                DestroyList(&L);
                printf("链表删除完成!\n已退出系统!");
            }
            system("pause");
            exit(0);
            break;
            default: printf("请重新输入!");
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
   free(p->next);//鐩存帴鐢╢ree锛坬锛変笉琛?
    return SUCCESS;
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))//visit涓鸿嚜瀹氫箟鍑芥暟
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
        return ERROR;//浼犲叆绌鸿〃鐩存帴杩斿洖
    while(p!=NULL)
    {
        if(p->data==e)
            return SUCCESS;//鑻ユ壘鍒癳鍒欒繑鍥瀞uccess
        p = p->next;
    }//閬嶅巻瀹岄摼琛ㄥ悗浠嶆湭鎵惧埌锛岃繑鍥瀍rror
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

/*void ReverseEvenList(LinkedList *L) //浼犲叆澶磋妭鐐归粯璁や负绌?
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
	LNode *pre, *cur, *Next;		//瀹氫箟鍓嶄腑鍚庢寚閽堬紝鐢ㄩ�斿拰鍙嶈浆鐩镐技
	pre = *L;
	*L = pre->next;
	while(pre && pre->next){
		cur = pre->next;
		Next = cur->next;
		if(cur->next && cur->next->next){			//濡傛灉cur->next涓嶅瓨鍦?锛岀粨鐐逛釜鏁颁负鍋舵??
			pre->next = cur->next->next;			//濡傛灉cur->next->next涓嶅瓨鍦?锛岀粨鐐逛釜鏁颁负濂囨??
		}else{										//濡傛灉閮藉瓨鍦?锛岄亶鍘嗘湭缁撴??
			pre->next = cur->next;
		}
		cur->next = pre;							//灏嗗伓鏁扮粨鐐瑰弽杞?
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