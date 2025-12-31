#include <iostream>
#include<cstring>

using namespace std;

#define MaxInt 32767
#define MVNum 100

typedef char VerTexType;
typedef int ArcType;

typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;
// 查找顶点在顶点数组中的索引
int LocateVex(AMGraph &G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}
// 创建无向网
void CreateUDN(AMGraph &G)
{
    VerTexType v1, v2;
    ArcType w;

    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; ++i)
        cin >> G.vexs[i];
    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = MaxInt;

    for (int k = 0; k < G.arcnum; ++k)
    {

        cin >> v1 >> v2 >> w;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
}

// 测试输出邻接矩阵
void PrintAMGraph(AMGraph &G)
{
    cout << "邻接矩阵：" << endl;
    cout << "   "; 
    for (int i = 0; i < G.vexnum; ++i)
    {
        printf("%4d", G.vexs[i]);
    }
    cout << endl;

    for (int i = 0; i < G.vexnum; ++i)
    {
        cout << G.vexs[i] << " "; 
        for (int j = 0; j < G.vexnum; ++j)
        {
            if (G.arcs[i][j] == MaxInt)
                printf("%4d", "∞");
            else
                printf("%4d", G.arcs[i][j]);
        }
        cout << endl;
    }
}
// 度
void Cal_degree(AMGraph G)
{
    int vex_degree[G.vexnum] = {0};

    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            if (G.arcs[i][j] == 1)
                vex_degree[i]++;

    for (int i = 0; i < G.vexnum - 1; ++i)
        cout << vex_degree[i] << " ";
    cout << vex_degree[G.vexnum - 1];
}


int main()
{
    AMGraph G;
    cout << "请输入顶点数和边数：" << endl;
    CreateUDN(G);
    PrintAMGraph(G);
    return 0;
}
