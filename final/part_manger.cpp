#include <iostream>
#include <cstring>
using namespace std;

// 栈存储的数据
typedef struct
{
    char id[10];
    int t;
} Edata;

typedef Edata ElemType;

// 顺序栈
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

// 链队
typedef struct QNode
{
    char id[10];
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQune;

// 初始化栈,队列
void InitStack(SqStack &S, int MAXSIZE)
{
    S.base = new ElemType[MAXSIZE];
    if (!S.base)
        return;
    S.top = S.base;
    S.stacksize = MAXSIZE;
}
void InitQueue(LinkQune &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
}

// 入出栈
void Push(SqStack &S, ElemType e)
{
    if (S.top - S.base == S.stacksize)
        return;
    *S.top++ = e;
}
void Pop(SqStack &S, ElemType &e)
{
    if (S.top == S.base)
        return;
    e = *--S.top;
}
// 入出队
void EnQueue(LinkQune &Q, ElemType e)
{
    QueuePtr p = new QNode;
    strcpy(p->id, e.id);
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}
void DeQueue(LinkQune &Q, ElemType &e)
{
    if (Q.front == Q.rear)
        return;
    QueuePtr p = Q.front->next;
    strcpy(e.id, p->id);
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
}

// 查询车辆在栈的位置
int Search_S(SqStack S, ElemType e)
{
    ElemType *p;
    p = S.base;
    while (p < S.top)
    {
        if (strcmp(p->id, e.id) == 0)
        {
            return p - S.base + 1;
        }
        p++;
    }
    return -1;
}
// 查询车辆在队列的位置并出队
void Search_DQ(LinkQune &Q, ElemType e)
{
    QueuePtr pre = Q.front;
    QueuePtr p = Q.front->next;
    while (p)
    {
        if (strcmp(p->id, e.id) == 0)
        {
            pre->next = p->next;
            if (Q.rear == p)
            {
                Q.rear = pre;
            }
            delete p;
            return;
        }
        pre = p;
        p = p->next;
    }
}

//   队列长度
int QueueLen(LinkQune Q)
{
    int len = 0;
    QueuePtr p = Q.front->next;
    while (p)
    {
        ++len;
        p = p->next;
    }
    return len;
}

// 到达
void arrive(SqStack &S, LinkQune &Q, ElemType e)
{
    if (S.top - S.base != S.stacksize)
    {
        Push(S, e);
        cout << "Stack " << S.top - S.base << endl;
    }
    else
    {
        EnQueue(Q, e);
        int len = QueueLen(Q);
        cout << "Queue " << len << endl;
    }
}
// 离开
void leave(SqStack &S, LinkQune &Q, ElemType e, int leave_time)
{
    int e_sp = Search_S(S, e);
    ElemType temp, stemp;
    SqStack ST;
    InitStack(ST, 100);
    if (e_sp >= 0) // 在栈里
    {
        // 移出车辆
        while (S.top > S.base + e_sp)
        {
            Pop(S, temp);
            Push(ST, temp);
            cout << "汽车id:" << temp.id << " out" << endl;
        }
        Pop(S, stemp);
        // 移回车辆
        while (ST.top > ST.base)
        {
            Pop(ST, temp);
            Push(S, temp);
            cout << "汽车id:" << temp.id << " in" << endl;
        }
        if (S.top - S.base != S.stacksize)
        {
            int Q_len = QueueLen(Q);
            if (Q_len > 0)
            {
                DeQueue(Q, temp);
                temp.t = leave_time; // 队列车进入栈的时间
                Push(S, temp);
                cout << "汽车id:" << temp.id << " in" << endl;
            } // 判断队列是否为空才能压入
        }
        cout << "车辆停留的时间：" << leave_time - stemp.t << endl;
    }
    else // 在队列里
    {
        Search_DQ(Q, e);
        cout << "0" << endl;
    }
}

int main()
{
    SqStack S;
    LinkQune Q;
    ElemType e;
    int n, q;
    char op[20];

    cin >> n;
    InitStack(S, n);
    InitQueue(Q);

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> op;
        if (strcmp(op, "arrive") == 0)
        {
            cin >> e.id >> e.t;
            arrive(S, Q, e);
        }
        else if (strcmp(op, "leave") == 0)
        {
            cin >> e.id >> e.t;
            leave(S, Q, e, e.t);
        }
    }
}