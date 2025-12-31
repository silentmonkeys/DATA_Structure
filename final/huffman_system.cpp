#include <iostream>
#include <cstring>
using namespace std;

typedef struct HTNode
{
    int weight;
    char ch;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

//统计字符串的出现频率
void countFre(char content[], int fre[])
{
    for (int i = 0; i < 256; i++)
    {
        fre[i] = 0;
    }
    int c_len = strlen(content);
    for (int i = 0; i < c_len; i++)
    {
        unsigned char curr_char = content[i];
        fre[curr_char]++;
    }
}

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
// ???¨??·ò?ü?÷
void CreateHuffmanTree(HuffmanTree &HT, int fre[])
{
    int n = sizeof(fre) / sizeof(fre[0]);
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
        if (fre[i] > 0)
        {
            HT[i].weight = fre[i];
            HT[i].ch = i;
        }
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