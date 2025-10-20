#include <iostream>
#include "SqList.h"
using namespace std;

SqList::SqList(/* args */)
{
}

SqList::~SqList()
{
}

//初始化顺序表
bool SqList::InitList(void)
{
    length = 0;
    cout << "SqList initialization successful!" << endl;
    return true;
}

//在第i位元素前插入e
bool SqList::ListInsert(int i,ElemType e)
{
    //判断输入的位序i是否有效
    if(i < 1 || i > length +1)
    {
        cout << "Invalid position input!" << endl;
        return false;
    }
    //存储空间满则不能插入
    if(length >= MaxSize)
    {
        cout << "Sequential list is full!"  << endl;
        return false;
    }
    //将第i个元素及其以后的元素都后移
    for(int j=length;j>=i;j--)
    {
        data[j] = data[j - 1];
    }

    data[i-1] = e;  //放入e
    length++;       //增加长度

    return true;
}

/*  for循环的思维模式
*   明确循环的目的，将第几位下标移动到第几位下标
*   先确定递推式--data[j-1] = data[j];
*   再确定起始条件 -- j=i
*   最后确定终止条件 -- j<length
*   再最后检查，加上j++/j--
*/

//移除第i位元素
bool SqList::ListDelete(int i,ElemType &e)
{
    if(i<1 || i>length+1)
    {
        cout << "Invalid position input!" << endl;
        return false;
    }
    if(length < 0)
    {
        cout << "Sequential list is full!"  << endl;
        return false;
    }

    e = data[i-1];
    
    //将第i位元素之后的元素往前面移动
    for(int j=i;j<length;j++)
    {
        data[j-1] = data[j];
    }
    length--;
    return true;
}

//按位查找，获取第i位元素的存储内容
ElemType SqList::GetElem(int i)
{
    if(i<1 || i>length+1)
    {
        cout << "Invalid position input!" << endl;
        return false;
    }

    return data[i-1];
}

//按值查找，返回e所在的位序
int SqList::LocateElem(ElemType e)
{
    for(int i=0;i<length;i++)
    {
        if(data[i] == e)
        {
            return i+1;
        }
    }

    return 0;
}

//打印顺序表
void SqList::PrintList(void)
{
    if(IsEmpty())
    {
        cout << "Sequential list is empty!" << endl;
        return;
    }

    cout << "Sequential list elements: ";
    for(int i=0;i<length;i++)
    {
        cout << data[i] << " ";
    }
    cout <<  "(Length: " << length << ")" << endl;
}

//测试顺序表函数
void test01(void)
{
    cout << "---- Starting sequential list test function test01() ----" << endl;

    SqList L;
    ElemType e;

    L.InitList();
    L.PrintList();

    cout << "\n=== Insert operation test ===" << endl;
    for(int i=1;i<5;i++)
    {
        L.ListInsert(i,i*10);
    }
    L.PrintList();

    L.ListInsert(3,99);
    L.PrintList();

    cout << "\n=== Search operation test ===" << endl;
    L.LocateElem(30);
    L.LocateElem(100);

    e = L.GetElem(4);
    cout << "Successfully retrieved element: " << e << endl;

    cout << "\n=== Delete operation test ===" << endl;
    if (L.ListDelete(2, e)) {
        cout << "Deleted element is: " << e << endl;
    }
    L.PrintList();

    cout << "\n--- Boundary test ---" << endl;
    L.ListInsert(0, 100);    // 位置0不合法
    L.ListInsert(10, 100);   // 越界插入
    L.ListDelete(10, e);     // 越界删除
    
    cout << "=== Sequential list test function test01() completed ===" << endl << endl;
}
