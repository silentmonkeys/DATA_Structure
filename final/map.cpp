#include <iostream>
#include <cstring>

using namespace std;

#define MaxInt 32767
#define MVNum 100

typedef struct
{
    char name[20];
    char Code_name[20];
    char introduction[20];
    int id;
} Data;

typedef Data VerTexType;
typedef int ArcType;

typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;

// 创建图的邻接矩阵无向网
void CreateUDN(AMGraph &G)
{
    ArcType w;

    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; ++i)
    {
        cin >> G.vexs[i].name >> G.vexs[i].Code_name >> G.vexs[i].introduction;
        G.vexs[i].id = i + 1;
    }

    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = MaxInt;

    for (int k = 0; k < G.arcnum; ++k)
    {
        int i, j;
        cin >> i >> j >> w;
        G.arcs[i - 1][j - 1] = w;
        G.arcs[j - 1][i - 1] = w;
    }
}

// 查询信息
void Search(AMGraph G, char name[])
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (strcmp(G.vexs[i].name, name) == 0)
        {
            cout << "景点id: " << G.vexs[i].id << " 景点名称：" << G.vexs[i].name << " 代号：" << G.vexs[i].Code_name << " 介绍：" << G.vexs[i].introduction << endl;
        }
    }
    return;
}
// 路径查询（最短路径）
void Search_min(AMGraph G, char str1[], char str2[])
{
    int s = -1, t = -1;
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (strcmp(G.vexs[i].name, str1) == 0)
            s = i;
        if (strcmp(G.vexs[i].name, str2) == 0)
            t = i;
    }
    if (s == -1 || t == -1)
    {
        cout << "未找到起点或终点";
        return;
    }

    int n = G.vexnum;
    int dist[MVNum];
    bool visited[MVNum];
    int prev[MVNum];

    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
        prev[i] = -1;
        if (G.arcs[s][i] < MaxInt)
            dist[i] = G.arcs[s][i];
        else
            dist[i] = MaxInt;
    }
    dist[s] = 0;
    visited[s] = true;

    for (int cnt = 1; cnt < n; ++cnt)
    {
        int u = -1;
        int minDist = MaxInt;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1)
            break;
        visited[u] = true;
        for (int v = 0; v < n; ++v)
        {
            if (!visited[v] && G.arcs[u][v] < MaxInt && dist[u] + G.arcs[u][v] < dist[v])
            {
                dist[v] = dist[u] + G.arcs[u][v];
                prev[v] = u;
            }
        }
    }

    if (dist[t] == MaxInt)
    {
        cout << "无可达路径";
        return;
    }

    int path[MVNum];
    int plen = 0;
    for (int p = t; p != -1; p = prev[p])
        path[plen++] = p;

    cout << "最短路径: ";
    cout << str1 << " -> ";
    for (int i = plen - 1; i >= 0; --i)
    {
        int idx = path[i];
        cout << G.vexs[idx].name;
        if (i > 0)
            cout << " -> ";
    }
    cout << endl
         << "距离: " << dist[t];
}
// 修改
void Modify(AMGraph &G, int id, char name[], char Code_name[], char introduction[])
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.vexs[i].id == id)
        {
            strcpy(G.vexs[i].name, name);
            strcpy(G.vexs[i].Code_name, Code_name);
            strcpy(G.vexs[i].introduction, introduction);
        }
    }
    return;
}

int main()
{
    AMGraph G;
    CreateUDN(G);

    char op_con[20], str1[20], str2[20], str3[20];
    int op_n, op;
    cin >> op;
    for (int i = 0; i < op; i++)
    {
        cin >> op_con;
        if (strcmp(op_con, "Query") == 0)
        {
            cin >> op_n;
            if (op_n == 1)
            {
                cin >> str1;
                Search(G, str1);
            }
            else if (op_n == 2)
            {
                cin >> str1 >> str2;
                Search_min(G, str1, str2);
            }
        }
        else if (strcmp(op_con, "Modify") == 0)
        {
            cin >> op_n >> str1 >> str2 >> str3;
            Modify(G, op_n, str1, str2, str3);
        }
    }
}