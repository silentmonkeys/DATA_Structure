#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
typedef int ElemType, Status;

// 定义单链表结构
typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;

LinkList p;

// 单链表初始化
Status InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    return OK;
}

// 尾插法创建单链表
void CreateList_T(LinkList &L, int n)
{
    LNode *tail = L;
    for (int i = 0; i < n; i++)
    {
        LNode *p = new LNode;
        cin >> p->data;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}

void PrintList(LinkList &L)
{
    if (L->next == NULL)
    { // 链表为空
        return;
    }

    LNode *p = L->next;  // 指向第一个有效节点
    bool isFirst = true; // 标记是否为第一个元素

    while (p != NULL)
    {
        if (isFirst)
        {
            cout << p->data;
            isFirst = false;
        }
        else
        {
            cout << " " << p->data;
        }
        p = p->next;
    }
}
int main()
{
    LinkList list;
    InitList(list);
    int n;
    cin >> n;

    CreateList_T(list, n);

    PrintList(list);
}