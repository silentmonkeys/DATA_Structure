#include <iostream>

using namespace std;

#define MVNum 100
#define MAXSIZE 100

typedef struct
{
    int x;
    int y;
} Corr;

typedef Corr SElemType;

typedef struct
{
    int arcs[MVNum][MVNum];
    int visited[MVNum][MVNum] = {0};
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
            G.arcs[i][j] = 0;

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
//判空
bool Empty(SqStack S)
{
    if (S.top == S.base)
        return true;
    return false;
}

// 深度优先
void DFS(Graph G)
{
    SqStack S;
    InitStack(S);
    SElemType e;

    

}