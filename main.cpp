#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node{  //申明
            ElemType data;
            struct Node *next;
            }LNode,*LinkList;
typedef struct DNode{
        ElemType data;
        struct DNode *prior;
        struct DNode *next;
        }DLNode,*DLinkList;
/*void CreateList(LinkList &L,int n)//单链表的创建
{
    LinkList p;
    int i;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next=L->next;
        L->next=p;
    }
}*/
/*void PrintfList(LinkList L)//打印单向循环链表
{
    LinkList p;
    p=L->next;
    while(p)
    {

        printf("%d ",p->data);
        p=p->next;
    }
}*/
/*void D_Z(LinkList &L)//单链表的倒置
{
    LinkList p,q;
    p=L->next;
    L->next=NULL;
    while(p)
    {
        q=p; p=p->next;
       q->next=L->next;
         L->next=q;

    }
}*/
void ClearList(LinkList &L)//单链表的删除
{
    LinkList p,q;
    L->next=p;
    while(p)
    {
        q=p->next;
        free(p);//释放当前节点
        p=q;
    }
}
/*void XunHun(LinkList &L,int n,LinkList &last)//创建单向循环链表，带头节点
{
    LinkList p,r;
    int i;
    L=(LinkList)malloc(sizeof(LNode));
    r=L;
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        r->next=p;
        r=p;
    }
    r->next=L;//超级链接 成环！！！
    last=r;
}*/
void  D_D(LinkList &LA,LinkList &LB,LinkList &last1,LinkList &last2)//两单向循环链表的合并
{
    LinkList p,q;
    p=last1->next;
    last1->next=last2->next->next;
    q=last2->next;
    last2->next=p;
}
void PrintfList(LinkList L)//输出循环链表
{
    LinkList P;
    P=L->next;
    while(P!=L)
    {
        printf("%d ",P->data);
        P=P->next;
    }
}
void CreateList(DLinkList &L,int n)//创建双向链表
{
    DLinkList p,r;
 int i;
    L=(DLinkList)malloc(sizeof(DLNode));
    r=L;
    for(i=0;i<n;i++)
    {
        p=(DLinkList)malloc(sizeof(DLNode));
        scanf("%d",&p->data);
        r->next=p;
        p->prior=r;
        r=p;
    }
    r->next=L;
    L->prior=r;
}
void DPrintfList(DLinkList L)//打印双向链表
{
    DLinkList p;
    p=L->next;
    while(p!=L)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void DInsetList(DLinkList &L,int i,ElemType e)//在第i个位置处插入e元素
{
    DLinkList p,q,s;
    int j=1;
    p=L;
    for(;j<i;j++)
    {
        p=p->next;
    }
    s=(DLinkList)malloc(sizeof(DLinkList));
    s->data=e;
    s->prior=p;
    s->next=p->next;
    p->next->prior=s;
    p->next=s;
}


int main()
{
    DLinkList LA,LB,last1,last2;
    int n1=3,n2=3,e;
   CreateList(LA,n1);
   scanf("%d",&e);
   DInsetList(LA,n2,e);
    DPrintfList(LA);

    return 0;
}

