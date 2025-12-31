#include <iostream>

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
    VerTexType v[3];

    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; ++i)
        cin >> G.vexs[i];
    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = 0;

    for (int k = 0; k < G.arcnum; ++k)
    {

        for (int m = 0; m < 2; ++m)
            cin >> v[m];
        int i = LocateVex(G, v[0]);
        int j = LocateVex(G, v[1]);
        G.arcs[i][j] = 1;
        G.arcs[j][i] = G.arcs[i][j];
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

    for (int i = 0; i < G.vexnum-1;++i)
        cout << vex_degree[i]<<" ";
    cout << vex_degree[G.vexnum - 1];
}

int main(){
    AMGraph G;
    CreateUDN(G);
    Cal_degree(G);
}
