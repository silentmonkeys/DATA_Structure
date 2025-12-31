#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList p;

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

//链表逆置(不新建链表)
void InsertList(LinkList &L){
    if(L->next==NULL||L->next->next==NULL)
        return;
    LinkList prev = NULL;
    LinkList current = L->next;
    LinkList next = NULL;
    L->next = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    L->next = prev;
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
    LinkListCreateH(test, 5);
    Print(test);
    cout << endl;
    InsertList(test);
    Print(test);
}