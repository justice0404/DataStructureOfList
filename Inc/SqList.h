#ifndef __SQLIST_H

#define __SQLIST_H

#define MaxSize 100
#define ElemType int

class SqList
{
private:
    /* data */
    int length;             //指向当前长度，也就是最后一个元素的下一位
    ElemType data[MaxSize];
public:
    SqList(/* args */);
    ~SqList();

    //基本操作
    bool InitList(void);
    bool ListInsert(int i,ElemType e);
    bool ListDelete(int i,ElemType &e);
    ElemType GetElem(int i);
    int LocateElem(ElemType e);
    bool IsEmpty(void){ return length==0;}
    int GetLength(void) { return length; }
    void PrintList(void);
};

//测试函数
void test01(void);

#endif
