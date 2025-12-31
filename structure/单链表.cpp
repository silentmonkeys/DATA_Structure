#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList p,s;
// 初始化
void InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
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
//查找
LinkList LocateElem(LinkList L, ElemType e)
{
    p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}
//插入
void ListInsert(LinkList &L,int i,ElemType e)
{
    p = L;
    int j = 0;
    while(p&&(j<i-1)){
        p = p->next;
        ++j;
    }
    if(!p||j>i-1)
        return; 
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
}
//删除
void ListDelete(LinkList &L,int i)
{
    p = L;
    int j = 0;
    while((p->next)&&(j<i-1)){
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        return;
    s = p->next;
    p->next = s->next;
    delete s;
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
int main(){
    LinkList test;
    LinkListCreateR(test, 5);
    Print(test);
    ListInsert(test, 2, 9);
    Print(test);
    cout << endl;
    cout << LocateElem(test, 4) << endl;
}