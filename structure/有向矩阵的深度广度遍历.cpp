#include <iostream>
#include <iomanip>

using namespace std;

#define MaxInt 32767
#define MVNum 100
#define MAXQSIZE 100

typedef char VerTexType;
typedef int ArcType;
typedef int QElemType;

typedef struct
{
    QElemType *base;
    int front;
    int rear;
} SqQueue;

typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} Graph;

// 初始化
void InitQueue(SqQueue &Q)
{
    Q.base = new QElemType[MAXQSIZE];
    if (!Q.base)
        return;
    Q.front = Q.rear = 0;
}
// 入队
void EnQueue(SqQueue &Q, QElemType e)
{
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
}
// 判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
    return Q.front == Q.rear;
}
// 出队
void DeQueue(SqQueue &Q, QElemType &e)
{
    if (Q.rear == Q.front)
        return;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
}

// 查找顶点在顶点数组中的索引
int LocateVex(Graph &G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

// 创建无向网
void CreateUDN(Graph &G)
{
    VerTexType v1, v2;
    cin >> G.vexnum >> G.arcnum;

    for (int i = 0; i < G.vexnum; ++i)
        cin >> G.vexs[i];
    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = 0;

    for (int k = 0; k < G.arcnum; ++k)
    {

        cin >> v1 >> v2;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        G.arcs[i][j] = 1;
    }
}

// 深度优先
void DFS(Graph &G, int v, bool visited[])
{
    cout << G.vexs[v] << " ";
    visited[v] = true;

    for (int i = 0; i < G.vexnum; ++i)
    {
        if (!visited[i])
        {
            DFS(G, i, visited);
        }
    }
}

void DFSTraverse(Graph &G)
{
    bool visited[MVNum] = {false};
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (!visited[i])
        {
            DFS(G, i, visited);
        }
    }
    cout << endl;
}

// 广度优先
void BFSTraverse(Graph &G)
{
    bool visited[MVNum] = {false};
    SqQueue Q;
    InitQueue(Q);
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            cout << G.vexs[i] << " ";
            EnQueue(Q, i);

            while (!QueueEmpty(Q))
            {
                int v;
                DeQueue(Q, v);
                for (int j = 0; j < G.vexnum; ++j)
                {
                    if (!visited[j])
                    {
                        visited[j] = true;
                        cout << G.vexs[j] << " ";
                        EnQueue(Q, j);
                    }
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    Graph G;
    cout << "请输入顶点数和边数：" << endl;
    CreateUDN(G);
    DFSTraverse(G);
    BFSTraverse(G);

    return 0;
}
