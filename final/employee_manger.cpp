#include <iostream>
#include <cstring>

using namespace std;

typedef struct LNode
{
    int id;
    char name[20];
    char tel[20];
    char email[20];
    struct LNode *next;
} LNode, *LinkList;

// 初始化
void InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
}
// 输出单个员工信息
void Print_single(LinkList p)
{
    cout << "==============================" << endl;
    cout << "编号     名称     电话     邮箱" << endl;
    printf("%5d,%5s,%5s,%5s\n", p->id, p->name, p->tel, p->email);
    cout << "==============================" << endl;
}

// 查询地址
LinkList LocateElem(LinkList L, char name[])
{
    LinkList p = L->next;
    while (p && strcmp(p->name, name) != 0)
    {
        p = p->next;
    }

    return p;
}

// 查询
void Query(LinkList L, char name[])
{

    LinkList p = LocateElem(L, name);
    if (p)
        Print_single(p);
    else
        cout << "NOT FOUND!" << endl;
}
// 修改
void Modify(LinkList &L, char name[], char atteibute[], char message[])
{
    LinkList p = LocateElem(L, name);

    if (strcmp("姓名", atteibute) == 0)
    {
        strcpy(p->name, message);
    }
    else if (strcmp("电话", atteibute) == 0)
    {
        strcpy(p->tel, message);
    }
    else if (strcmp("邮箱", atteibute) == 0)
    {
        strcpy(p->email, message);
    }
}
// 添加(尾插法)
void Add(LinkList &L, int n)
{
    LinkList p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    for (int i = 0; i < n; ++i)
    {
        LinkList s = new LNode;
        scanf("%d %s %s %s", &(s->id), s->name, s->tel, s->email);
        s->next = NULL;
        p->next = s;
        p = s;
    }
}
// 删除
void Del(LinkList &L, char name[])
{
    LinkList q = L;
    LinkList p = L->next;
    while (p && strcmp(p->name, name) != 0)
    {
        q = p;
        p = p->next;
    }

    q->next = p->next;
    delete p;
}

// 打印
void Print_all(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        Print_single(p);
        p = p->next;
    }
}
int main()
{
    LinkList L;
    InitList(L);

    int m, n;

    cin >> n;
    Add(L, n);

    char op[20], name[20], atteibute[20], message[20];

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        scanf("%s", op);
        if (strcmp("查询", op) == 0)
        {
            cin >> name;
            Query(L, name);
        }
        else if (strcmp("修改", op) == 0)
        {
            cin >> name >> atteibute >> message;
            Modify(L, name, atteibute, message);
        }
        else if (strcmp("添加", op) == 0)
        {
            cin >> n;
            Add(L, n);
        }
        else if (strcmp("删除", op) == 0)
        {
            cin >> name;
            Del(L, name);
        }
        else if (strcmp("打印", op) == 0)
        {
            Print_all(L);
        }
    }

    return 0;
}