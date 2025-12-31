#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList p, s;
// 初始化
void InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
}
// 尾插法
void LinkListCreateR(LinkList &L, int &count)
{
    LinkList r;
    L = new LNode;
    L->next = NULL;
    r = L;
    int temp;
    while (cin >> temp)
    {
        if (temp >= 0)
        {
            p = new LNode;
            p->data = temp;
            p->next = NULL;
            r->next = p;
            r = p;
            count++;
        }
        else
            break;
    }
}
// 取值
void GetElem(LinkList L, int i, ElemType &e)
{
    p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return;
    e = p->data;
}

int main()
{
    int K;
    int count = 1;
    ElemType e;
    cin >> K;
    LinkList L;
    LinkListCreateR(L, count);
    if (count > K)
    {
        GetElem(L, count - K, e);
        cout << e;
    }
    else
        cout << "NULL";
}