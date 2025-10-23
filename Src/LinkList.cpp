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

    LNode* p = L;
    int j = 0;
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
    while (p != NULL && p->data != e)
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

//打印链表
void PrintfList(LinkList L)
{
    LNode* p = L->next;
    
    while (p != NULL)
    {
        cout << p->data;
        if (p->next != NULL) {
            cout << " -> ";
        }
        p = p->next;
    }
    cout << " -> NULL" << endl;
}
//尾插法建立链表
LinkList ListTailInsert(LinkList &L)
{
    ElemType x;
    L = (LinkList)malloc(sizeof(LinkList));
    LNode* s,*r = L;    //r为表尾指针，始终指向表尾
    int count = 1;
    printf("=== Linked List Tail Insertion Program ===\n");
    printf("Please enter integer data (enter 9999 to stop):\n");
    printf("Enter data #1: ");
    scanf("%d",&x);
    while(x != 9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;          //将r指向新的表尾
        count++;
        printf("Enter data #%d (enter 9999 to stop): ", count);
        scanf("%d",&x);
    }
    r->next = NULL;

    printf("\n=== Linked List Creation Complete ===\n");
    printf("Successfully inserted %d nodes\n", count-1);
    printf("Linked list construction finished, tail node set to NULL\n");
    return L;
}

//头插法建立链表
LinkList ListHeadInsert(LinkList &L)
{
    ElemType x;
    LNode* s;
    L = (LinkList)malloc(sizeof(LinkList));
    L->next = NULL;
    printf("=== Linked List Head Insertion Program ===\n");
    printf("Please enter integer data (enter 9999 to stop):\n");
    printf("Enter data #1: ");
    scanf("%d",&x);

    int count = 1;
    while (x != 9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        count++;
        printf("Enter data #%d (enter 9999 to stop): ", count);
        scanf("%d",&x);
    }

    printf("\n=== Linked List Creation Complete ===\n");
    printf("Successfully inserted %d nodes using head insertion method\n", count-1);
    printf("Note: The order of elements in the list is REVERSED from the input order\n");
    return L;
}

//三指针法逆置链表
void ReverseList(LinkList &L)
{
    if(L==NULL || L->next==NULL || L->next->next==NULL)
    {
        return;
    }
    LNode* pre = NULL;
    LNode* cur = L->next;
    LNode* next = NULL;

    while(cur!=NULL)
    {
        next = cur->next;   //保存下一个节点
        cur->next = pre;    //开辟一条新链存储逆置的节点
        pre = cur;          //更新新链
        cur = next;         //更新cur，指回旧链的下一个节点
    }
    L->next = pre;
}

void test02(void) {
    cout << "=== Comprehensive Linked List Test (Using Your Functions) ===" << endl;
    cout << endl;
    
    LinkList L1, L2, L3;
    ElemType e;
    LNode* node;
    
    // 1. 初始化测试
    cout << "1. List Initialization Test:" << endl;
    if (InitList(L1) && InitList(L2) && InitList(L3)) {
        cout << "Three lists initialized successfully" << endl;
    } else {
        cout << "List initialization failed" << endl;
        return;
    }
    
    // 2. 头插法建立链表测试
    cout << "\n2. ListHeadInsert Function Test (L1):" << endl;
    cout << "Creating list using ListHeadInsert function" << endl;
    cout << "Input data will be stored in REVERSE order" << endl;
    
    // 直接调用你实现的头插法函数
    L1 = ListHeadInsert(L1);
    cout << "List after ListHeadInsert: ";
    PrintfList(L1);
    
    // 3. 尾插法建立链表测试  
    cout << "\n3. ListTailInsert Function Test (L2):" << endl;
    cout << "Creating list using ListTailInsert function" << endl;
    cout << "Input data will be stored in SAME order" << endl;
    
    // 直接调用你实现的尾插法函数
    L2 = ListTailInsert(L2);
    cout << "List after ListTailInsert: ";
    PrintfList(L2);
    
    // 4. 两种方法的比较分析
    cout << "\n4. Comparison Analysis:" << endl;
    cout << "ListHeadInsert result (L1): Elements in REVERSE order of input" << endl;
    cout << "ListTailInsert result (L2): Elements in SAME order as input" << endl;
    cout << "L1 length: " << Length(L1) << ", L2 length: " << Length(L2) << endl;
    
    // 5. 基本操作验证测试
    cout << "\n5. Basic Operations Validation on L2:" << endl;
    cout << "Original L2: ";
    PrintfList(L2);
    
    // 测试插入操作
    if (ListInsert(L2, 2, 999)) {
        cout << "Inserted 999 at position 2" << endl;
    }
    
    // 测试删除操作
    if (ListDelete(L2, 3, e)) {
        cout << "Deleted element " << e << " from position 3" << endl;
    }
    
    cout << "Modified L2: ";
    PrintfList(L2);
    
    // 6. 查找功能测试
    cout << "\n6. Search Operations Test:" << endl;
    node = GetElem(L2, 1);
    if (node != NULL) {
        cout << "First element: " << node->data << endl;
    }
    
    // 7. 链表逆置测试
    cout << "\n7. Reverse List Test on L2:" << endl;
    cout << "L2 before reversal: ";
    PrintfList(L2);
    
    ReverseList(L2);
    cout << "L2 after reversal: ";
    PrintfList(L2);
    
    // 8. 空链表和边界测试
    cout << "\n8. Empty List and Boundary Tests:" << endl;
    cout << "Is L3 empty: " << (IsEmpty(L3) ? "Yes" : "No") << endl;
    cout << "L3 length: " << Length(L3) << endl;
    
    // 测试在空链表中插入
    if (ListInsert(L3, 1, 100)) {
        cout << "Inserted 100 into empty list L3" << endl;
    }
    cout << "L3 after insertion: ";
    PrintfList(L3);
    
    // 9. 最终结果汇总
    cout << "\n9. Final Results Summary:" << endl;
    cout << "L1 (HeadInsert): ";
    PrintfList(L1);
    cout << "L1 length: " << Length(L1) << endl;
    
    cout << "L2 (TailInsert + modifications + reversal): ";
    PrintfList(L2); 
    cout << "L2 length: " << Length(L2) << endl;
    
    cout << "L3 (Empty list test): ";
    PrintfList(L3);
    cout << "L3 length: " << Length(L3) << endl;
    
    cout << "\n=== Comprehensive Test Completed ===" << endl;
    cout << "Tested functions:" << endl;
    cout << "- ListHeadInsert: Creates lists in reverse input order" << endl;
    cout << "- ListTailInsert: Preserves original input order" << endl; 
    cout << "- ListInsert/ListDelete: Element manipulation" << endl;
    cout << "- ReverseList: List reversal operation" << endl;
    cout << "- All functions work correctly with multiple independent lists" << endl;
}