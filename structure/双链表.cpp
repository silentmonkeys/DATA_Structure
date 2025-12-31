#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

DuLinkList p, s;
// 初始化
void InitList(DuLinkList &L)
{
    L = new DuLNode;
    L->next = NULL;
    L->prior = NULL;
}
DuLinkList GetElem_DuL(DuLinkList L, int i)
{
    p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return NULL;
    return p;
}
// 插入
void ListInsert_DuL(DuLinkList &L, int i, ElemType e)
{
    p = L;
    int j = 0;
    while (p && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        return;
    s = new DuLNode;
    s->data = e;
    s->prior = p;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    p->next = s;
}
// 删除
void ListDelete_DuL(DuLinkList &L, int i)
{
    p = L;
    int j = 0;
    while (p && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        return;
    s = p->next;
    p->next = s->next;
    if(s->next!=NULL)
        s->next->prior = p;
    delete s;
}

// 输出所有的数据
void Print(DuLinkList L)
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
    DuLinkList t;
    InitList(t);
    ListInsert_DuL(t, 1, 1);
    ListInsert_DuL(t, 2, 3);
    ListInsert_DuL(t, 3, 2);
    
    Print(t);
    ListDelete_DuL(t, 3);
    Print(t);
}