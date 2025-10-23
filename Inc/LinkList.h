#ifndef __LINKLIST_H

#define __LINKLIST_H

#define ElemType int

#include <iostream>

typedef struct LNode
{
    /* data */
    ElemType data;
    LNode * next;
}LNode,*LinkList;

bool InitList(LinkList &L);
bool ListInsert(LinkList &L,int i,ElemType e);
bool ListDelete(LinkList &L,int i,ElemType &e);
LNode* GetElem(LinkList L,int i);
LNode* LocateElem(LinkList L,ElemType e);
int Length(LinkList L);
bool IsEmpty(LinkList L){ return (L->next == NULL); }
void PrintfList(LinkList L);

bool InsertNextNode(LNode* p,ElemType e);
bool InsertPriorNode(LNode* p,ElemType e);
bool DeleteNode(LNode *p);

LinkList ListTailInsert(LinkList &L);
LinkList ListHeadInsert(LinkList &L);

void ReverseList(LinkList &L);

void test02(void);

#endif
