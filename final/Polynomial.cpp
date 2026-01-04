#include <iostream>

using namespace std;
typedef struct
{
    int ratio;
    int index;
} Data;

typedef Data ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
}

void Creat(LinkList &L, ElemType e)
{
    LinkList r = new LNode;

    r->data.index = e.index;
    r->data.ratio = e.ratio;
    r->next = NULL;

    if (L->next == NULL)
    {
        L->next = r;
        return;
    }
    LinkList p = L;
    while (p->next != NULL && p->next->data.index > e.index)
    {
        p = p->next;
    }

    r->next = p->next;
    p->next = r;
}

void Add(LinkList l1, LinkList l2, LinkList &l3)
{
    LinkList p = l1->next;
    LinkList q = l2->next;
    ElemType e;

    while (p || q)
    {
        if (p && q)
        {
            if (p->data.index == q->data.index)
            {
                e.ratio = p->data.ratio + q->data.ratio;
                e.index = p->data.index;
                Creat(l3, e);
                p = p->next;
                q = q->next;
            }
            else if (p->data.index > q->data.index)
            {
                e.index = p->data.index;
                e.ratio = p->data.ratio;
                Creat(l3, e);
                p = p->next;
            }
            else if (p->data.index < q->data.index)
            {
                e.index = q->data.index;
                e.ratio = q->data.ratio;
                Creat(l3, e);
                q = q->next;
            }
        }

        else if (p != NULL)
        {
            e.ratio = p->data.ratio;
            e.index = p->data.index;
            Creat(l3, e);
            p = p->next;
        }
        else
        {
            e.ratio = q->data.ratio;
            e.index = q->data.index;
            Creat(l3, e);
            q = q->next;
        }
    }
}

void Minus(LinkList l1, LinkList l2, LinkList &l3)
{
    LinkList p = l1->next;
    LinkList q = l2->next;
    ElemType e;

    while (p || q)
    {
        if (p && q)
        {
            if (p->data.index == q->data.index)
            {
                e.ratio = p->data.ratio - q->data.ratio;
                e.index = p->data.index;
                if(e.ratio!=0)
                    Creat(l3, e);
                p = p->next;
                q = q->next;
            }
            else if (p->data.index > q->data.index)
            {
                e.index = p->data.index;
                e.ratio = p->data.ratio;
                Creat(l3, e);
                p = p->next;
            }
            else if (p->data.index < q->data.index)
            {
                e.index = q->data.index;
                e.ratio = q->data.ratio;
                Creat(l3, e);
                q = q->next;
            }
        }

        else if (p != NULL)
        {
            e.ratio = p->data.ratio;
            e.index = p->data.index;
            Creat(l3, e);
            p = p->next;
        }
        else
        {
            e.ratio = 0-q->data.ratio;
            e.index = q->data.index;
            Creat(l3, e);
            q = q->next;
        }
    }
}
void Print(LinkList L)
{
    LinkList p = L->next;
    bool first = true;

    while (p)
    {
        if (!first && p->data.ratio > 0)
            cout << "+";

        cout << p->data.ratio << "x^" << p->data.index;
        first = false;
        p = p->next;
    }
    cout << endl;
}

void Input(LinkList &L)
{
    ElemType e;
    while (true)
    {
        cin >> e.ratio;
        if (e.ratio == 0)
        {
            cout << "当前多项式输入完成！" << endl;
            Print(L);
            break;
        }
        cin >> e.index;
        Creat(L, e);
    }
}
int main()
{
    LinkList L1, L2, L3;
    InitList(L1);
    InitList(L2);
    
    cout << "开始输入多项式(每项输入 系数 指数，输入系数=0结束输入)" << endl;
    cout << "多项式1:";
    Input(L1);
    cout << "多项式2:";
    Input(L2);

    cout << "计算结果" << endl;
    InitList(L3);
    Add(L1, L2, L3);
    cout << "L1+L2=";
    Print(L3);

    InitList(L3);
    Minus(L1, L2, L3);
    cout << "L1-L2=";
    Print(L3);
}