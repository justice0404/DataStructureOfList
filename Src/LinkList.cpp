#include <iostream>
#include "LinkList.h"

using namespace std;

//初始化一个带头结点的单链表
bool InitList(LinkList &L)
{
    //分配一个地址给头结点
    L = (LNode*)malloc(sizeof(LNode));
    if(L == NULL) return false;
    //头结点指向NULL
    L->next = NULL;
    return true;
}

//在链表L的第i个位置插入元素e
bool ListInsert(LinkList &L,int i,ElemType e)
{
    if(i<1)
    {
        cout << "Invalid position input!" << endl;
        return false;
    }

   
    /*这里的指针移动最好画出来
    *   p一开始和L一样指向头节点,j=0；假设在第三个节点插入，当j自增到2之后，下个迭代将会停止。
    *   L -> 头 -> 1 -> 2 -> 3 -> 4 -> NULL
    *       j=0   j=1  j=2
    */
    LNode *p;   //指示当前扫描的节点
    p = L;      //将p指向头结点
    int j=0;    //指示当前为第几个节点
    while (p!=NULL && j<i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL)
    {
        cout << "Invalid position input!" << endl;
        return false;
    }
    
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;  //先连
    p->next = s;        //后断

    return true;
}

//在链表L的第i个位置删除节点，并用e返回
bool ListDelete(LinkList &L,int i,ElemType &e)
{
    if(i<1)
    {
        cout << "Invalid position input!" << endl;
        return false;
    }

    LNode* p = (LNode*)malloc(sizeof(LNode));
    p = L;
    int j = 0;
    while(p != NULL && j<i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL)
    {
        cout << "Invalid position input!" << endl;
        return false;
    }
    if(p->next == NULL)    //要删除的节点不存在
    {
        cout << "Invalid position input!" << endl;
        return false;
    }

    LNode * q = p->next;
    e = q->data;
    p->next = q->next;  //断开
    free(q);

    return true;
}

//在指定节点后插入，存在问题，只是一个简单示例，用来删除中间节点
bool InsertNextNode(LNode* p,ElemType e)
{
    if(p == NULL)
    {
        cout << "Invalid position input!" << endl;
        return false;
    }

    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

//在指定节点前插入
bool InsertPriorNode(LNode* p,ElemType e)
{
    if(p == NULL)
    {
        cout << "Invalid position input!" << endl;
        return false;
    }
    //交换数据域
    LNode* q = (LNode*)malloc(sizeof(LNode));
    q->next = p->next;
    p->next = q;

    q->data = p->data;
    p->data = e;

    return true;
}

//删除指定节点
bool DeleteNode(LNode *p)
{
    if(p == NULL)
    {
        cout << "Invalid position input!" << endl;
        return false;
    }
    LNode* q = p->next;
    p->next = q->next;
    free(q);

    return true;
}

//获取第i个节点
LNode* GetElem(LinkList L,int i)
{
    if(i < 0)
    {
        cout << "Invalid position input!" << endl;
        return NULL;
    }

    LNode* p = (LNode*)malloc(sizeof(LNode));
    int j = 0;
    p = L;
    while (p!=NULL && j<i)
    {
        /* code */
        p = p->next;
        j++;
    }
    
    return p;
}

//获取数据域为e的节点
LNode* LocateElem(LinkList L,ElemType e)
{
    LNode* p = L->next;
    while (p != NULL || p->data != e)
    {
        p = p->next;
    }
    return p;
}

//获取表长
int Length(LinkList L)
{
    int len = 0;
    LNode* p = L;
    while(p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}