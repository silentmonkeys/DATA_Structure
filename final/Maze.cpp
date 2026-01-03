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
} Corr;

typedef Corr SElemType;

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
typedef struct
{
    SElemType *base;
    int front;
    int rear;
} SqQueue;


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
}

typedef struct
{
    SElemType *base;
    int front;
    int rear;
} SqQueue;

// 初始化
void InitQueue(SqQueue &Q)
{
    Q.base = new SElemType[MAXSIZE];
    if (!Q.base)
        return;
    Q.front = Q.rear = 0;
}

// 入队
void EnQueue(SqQueue &Q, SElemType e)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        return;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
}
// 出队
void DeQueue(SqQueue &Q, SElemType &e)
{
    if (Q.rear == Q.front)
        return;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
}
// 广度优先
void BFS(Graph &G)
{

}
int main()
{
    Graph G;
    CreateUDN(G);
    DFS(G);
}