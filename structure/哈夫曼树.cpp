#include <iostream>
#include<cstring>
using namespace std;

typedef struct
{
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
    int min1 = 32767, min2 = 32767;
    s1 = s2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (HT[i].parent == 0)
        {
            if (HT[i].weight < min1)
            {
                min2 = min1;
                s2 = s1;
                min1 = HT[i].weight;
                s1 = i;
            }
            else if (HT[i].weight < min2)
            {
                min2 = HT[i].weight;
                s2 = i;
            }
        }
    }
}
// 构建哈夫曼树
void CreateHuffmanTree(HuffmanTree &HT, int n)
{
    if (n <= 1)
        return;
    int m = 2 * n - 1;
    int s1, s2;
    HT = new HTNode[m + 1];
    for (int i = 0; i <= m; ++i)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> HT[i].weight;
    }
    for (int i = n + 1; i <= m; ++i)
    {
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

//构建哈夫曼编码
void CreateHuffmanCode(HuffmanTree HT, char **&HC, int n)
{
    HC = new char *[n + 1];
    char *cd = new char[n];
    cd[n - 1] = '\0';

    for (int i = 1; i <= n; ++i)
    {
        int start = n - 1;
        int cur = i;
        int par = HT[cur].parent;

        while (par != 0)
        {
            --start;
            if (HT[par].lchild == cur)
                cd[start] = '0';
            else
                cd[start] = '1';
            cur = par;
            par = HT[cur].parent;
        }
        HC[i] = new char[n - start];
        strcpy(HC[i], &cd[start]);
    }
    delete[] cd;
}

//打印
void PrintHuffmanCode(char **HC, int n)
{
    cout << "Huffman codes:\n";
    for (int i = 1; i <= n; ++i)
        cout << "char " << i << " : " << HC[i] << '\n';
}

int main()
{
    int n;
    cout << "Input n: ";
    cin >> n;

    HuffmanTree HT;
    CreateHuffmanTree(HT, n);

    char **HC;
    CreateHuffmanCode(HT, HC, n);
    PrintHuffmanCode(HC, n);

    // 释放内存
    for (int i = 1; i <= n; ++i)
        delete[] HC[i];
    delete[] HC;
    delete[] HT;
    return 0;
}