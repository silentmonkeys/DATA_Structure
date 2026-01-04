#include <iostream>
#include <cstring>

using namespace std;

#define MVNum 100
#define MAXSIZE 100

typedef struct
{
    int x;
    int y;
    char d[10];
} Data;

typedef Data SElemType;

typedef struct
{
    int arcs[MVNum][MVNum];
    bool visited[MVNum][MVNum];
    int m, n;
} Graph;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

// 构建迷宫
void CreateUDN(Graph &G)
{
    cin >> G.m >> G.n;

    for (int i = 0; i < G.m; ++i)
        for (int j = 0; j < G.n; ++j)
        {
            G.arcs[i][j] = 0;
        }

    for (int i = 0; i < G.m; ++i)
        for (int j = 0; j < G.n; ++j)
            cin >> G.arcs[i][j];
}

// 初始化
void InitStack(SqStack &S)
{
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
        return;
    S.top = S.base;
    S.stacksize = MAXSIZE;
}
// 入栈
void Push(SqStack &S, SElemType e)
{
    if (S.top - S.base == S.stacksize)
        return;
    *S.top++ = e;
}
// 出栈
void Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base)
        return;
    e = *--S.top;
}
// 判空
bool Empty(SqStack S)
{
    if (S.top == S.base)
        return true;
    return false;
}
// 取栈顶
void GetTop(SqStack S, SElemType &e)
{
    if (S.top == S.base)
        return;
    e = *(S.top - 1);
}

// 深度优先
void DFS(Graph &G)
{

    for (int i = 0; i < G.m; ++i)
        for (int j = 0; j < G.n; ++j)
            G.visited[i][j] = false;

    SqStack S;
    InitStack(S);

    SElemType temp = {0, 0, ""};

    Push(S, temp);
    G.visited[0][0] = true;

    bool found = false;
    while (!Empty(S) && !found)
    {
        SElemType next;
        GetTop(S, temp);

        if (temp.x == G.m - 1 && temp.y == G.n - 1)
        {
            found = true;
            break;
        }

        bool nextNode = false;
        if (temp.y - 1 >= 0 && G.arcs[temp.x][temp.y - 1] == 0 && !G.visited[temp.x][temp.y - 1])
        {
            Pop(S, temp);
            strcpy(temp.d, "LEFT");
            Push(S, temp);
            next = {temp.x, temp.y - 1, ""};
            G.visited[next.x][next.y] = true;
            Push(S, next);
            nextNode = true;
            continue;
        }
        else if (temp.y + 1 < G.n && G.arcs[temp.x][temp.y + 1] == 0 && !G.visited[temp.x][temp.y + 1])
        {
            Pop(S, temp);
            strcpy(temp.d, "RIGHT");
            Push(S, temp);
            next = {temp.x, temp.y + 1, ""};
            G.visited[next.x][next.y] = true;
            Push(S, next);
            nextNode = true;
            continue;
        }
        else if (temp.x + 1 < G.m && G.arcs[temp.x + 1][temp.y] == 0 && !G.visited[temp.x + 1][temp.y])
        {
            Pop(S, temp);
            strcpy(temp.d, "DOWN");
            Push(S, temp);
            next = {temp.x + 1, temp.y, ""};
            G.visited[next.x][next.y] = true;
            Push(S, next);
            nextNode = true;
            continue;
        }
        else if (temp.x - 1 >= 0 && G.arcs[temp.x - 1][temp.y] == 0 && !G.visited[temp.x - 1][temp.y])
        {
            Pop(S, temp);
            strcpy(temp.d, "UP");
            Push(S, temp);
            next = {temp.x - 1, temp.y, ""};
            G.visited[next.x][next.y] = true;
            Push(S, next);
            nextNode = true;
            continue;
        }

        if (!nextNode)
        {
            Pop(S, temp);
        }
    }

    if (found)
    {
        SqStack St;
        InitStack(St);

        while (!Empty(S))
        {
            Pop(S, temp);
            Push(St, temp);
        }

        while (!Empty(St))
        {
            Pop(St, temp);
            printf("(%d %d %s)", temp.x, temp.y, temp.d);
        }
    }
    else
    {
        cout << "没有找到路径" << endl;
    }
}

typedef Data QElemType;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQune;

// 初始化
void InitQuenue(LinkQune &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
}

// 入队
void EnQueue(LinkQune &Q, QElemType e)
{
    QueuePtr p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

// 出队
void DeQueue(LinkQune &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
}
// 队长
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

// 广度优先
void BFS(Graph &G)
{
    int px[MAXSIZE][MAXSIZE];
    int py[MAXSIZE][MAXSIZE];

    for (int i = 0; i < G.m; ++i)
        for (int j = 0; j < G.n; ++j)
        {
            G.visited[i][j] = false;
            px[i][j] = -1;
            py[i][j] = -1;
        }

    LinkQune Q;
    InitQuenue(Q);

    SElemType temp;
    temp = {0, 0, ""};
    EnQueue(Q, temp);
    G.visited[0][0] = true;

    bool found = false;
    while (QueueLen(Q) > 0)
    {
        SElemType next;
        DeQueue(Q, temp);

        if (temp.x == G.m - 1 && temp.y == G.n - 1)
        {
            found = true;
            break;
        }

        if (temp.y - 1 >= 0 && G.arcs[temp.x][temp.y - 1] == 0 && !G.visited[temp.x][temp.y - 1])
        {

            next = {temp.x, temp.y - 1, ""};
            G.visited[next.x][next.y] = true;
            px[next.x][next.y] = temp.x;
            py[next.x][next.y] = temp.y;
            EnQueue(Q, next);
        }
        if (temp.y + 1 < G.n && G.arcs[temp.x][temp.y + 1] == 0 && !G.visited[temp.x][temp.y + 1])
        {
            next = {temp.x, temp.y + 1, ""};
            G.visited[next.x][next.y] = true;
            px[next.x][next.y] = temp.x;
            py[next.x][next.y] = temp.y;
            EnQueue(Q, next);
        }
        if (temp.x + 1 < G.m && G.arcs[temp.x + 1][temp.y] == 0 && !G.visited[temp.x + 1][temp.y])
        {
            next = {temp.x + 1, temp.y, ""};
            G.visited[next.x][next.y] = true;
            px[next.x][next.y] = temp.x;
            py[next.x][next.y] = temp.y;
            EnQueue(Q, next);
        }
        if (temp.x - 1 >= 0 && G.arcs[temp.x - 1][temp.y] == 0 && !G.visited[temp.x - 1][temp.y])
        {
            next = {temp.x - 1, temp.y, ""};
            G.visited[next.x][next.y] = true;
            px[next.x][next.y] = temp.x;
            py[next.x][next.y] = temp.y;
            EnQueue(Q, next);
        }
    }

    if (found)
    {
        int x = G.m - 1;
        int y = G.n - 1;

        SqStack S;
        InitStack(S);
        while (x >= 0 && y >= 0)
        {
            int nx = px[x][y];
            int ny = py[x][y];

            if (nx < 0 && ny < 0)
            {
                break;
            }

            if (nx - x == -1 && ny - y == 0)
            {
                temp = {nx, ny, "DOWN"};
                Push(S, temp);
            }
            if (nx - x == 1 && ny - y == 0)
            {
                temp = {nx, ny, "UP"};
                Push(S, temp);
            }
            if (nx - x == 0 && ny - y == 1)
            {
                temp = {nx, ny, "LEFT"};
                Push(S, temp);
            }
            if (nx - x == 0 && ny - y == -1)
            {
                temp = {nx, ny, "RIGHT"};
                Push(S, temp);
            }

            x = nx;
            y = ny;
        }

        while (!Empty(S))
        {
            Pop(S, temp);
            printf("(%d %d %s)", temp.x, temp.y, temp.d);
        }
        printf("(%d %d )", G.m-1,G.n-1);
    }
}

int main()
{
    Graph G;
    CreateUDN(G);
    cout << "深度遍历" << endl;
    DFS(G);
    cout << endl;
    cout << "广度遍历" << endl;
    BFS(G);
}