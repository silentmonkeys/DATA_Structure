#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList p;

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
// 删除有序链表区间
void Delete(LinkList &L, int min, int max)
{
    if (L == NULL)
        return;
    LinkList current = L->next;
    LinkList prev = L;
    LinkList temp;
    while (current != NULL)
    {
        if (current->data < min)
        {
            prev = current;
            current = current->next;
        }
        else if (current->data > max)
        {
            break;
        }
        else
        {
            temp = current;
            current = current->next;
            prev->next = current;
            delete temp;
        }
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
    Delete(test, 2, 4);
    Print(test);
}