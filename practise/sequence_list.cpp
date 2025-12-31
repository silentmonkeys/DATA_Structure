#include <iostream>

using namespace std;

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
} Sqlist;

// 初始化
void InitList(Sqlist &L)
{
    L.elem = new ElemType[MAXQSIZE];
    L.length = 0;
}
// 插入
void ListInsert(Sqlist &L, int i, ElemType e)
{
    if (L.length == MAXQSIZE)
        return;
    for (int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];
    L.elem[i - 1] = e;
    ++L.length;
}
// 取值
ElemType GetElem(Sqlist L, int i)
{
    if (i < 1 || i > L.length)
        return 0;
    return L.elem[i - 1];
}
// 查找
int LocateElem(Sqlist L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e)
            return i + 1;
    return 0;
}
// 删除
void ListDelete(Sqlist &L, int i)
{
    if (i < 1 || i > L.length)
        return;
    for (int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];
    --L.length;
}
// 输出顺序表所有数据
void Print(Sqlist &L)
{
    for (int j = 0; j < L.length; j++)
        cout << L.elem[j] << " ";
}

int main()
{
    Sqlist test;
    InitList(test);
    ListInsert(test, 1, 10);
    ListInsert(test, 2, 5);
    ListInsert(test, 3, 20);

    Print(test);
    cout << LocateElem(test, 20) << " ";
    ListDelete(test, 2);
    Print(test);
}