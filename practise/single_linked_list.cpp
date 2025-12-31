#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList p;
// 初始化
void InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
}
// 取值
ElemType GetElem(LinkList L, int i)
{
    p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return 0;
    return p->data;
}
// 查找
LinkList LocateElem(LinkList L, ElemType e)
{
    p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}
// 头插法
void LinkListCreateH(LinkList &L, int n)
{
    L = new LNode;
    L->next = NULL;
    for (int i = 0; i < n; ++i)
    {
        p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}
// 尾插法
void LinkListCreateR(LinkList &L, int n)
{
    LinkList r;
    L = new LNode;
    L->next = NULL;
    r = L;
    for (int i = 0; i < n; ++i)
    {
        p = new LNode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

// 输出所有的数据
void Print(LinkList L)
{

    p = L->next;
    while (p != NULL)
    {
        cout << p->data << "\n";
        p = p->next;
    }
}

int main()
{
    LinkList test;
    LinkListCreateR(test, 5);
    Print(test);
    cout << endl;
    cout << LocateElem(test, 4) << endl;
    cout << GetElem(test, 3);
}
