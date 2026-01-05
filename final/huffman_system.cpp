#include <iostream>
#include <cstring>
using namespace std;

typedef struct HTNode
{
    int weight;
    char ch;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

// 统计字符串的出现频率
void countFre(char content[], int fre[], char ch[])
{
    int ch_index = 0;

    for (int i = 0; i < 256; i++)
    {
        fre[i] = 0;
        ch[i] = 0;
    }

    int c_len = strlen(content);
    for (int i = 0; i < c_len; i++)
    {
        char c_char = content[i];
        int found = -1;
        // 在ch中查找字符
        for (int j = 0; j < ch_index; j++)
        {
            if (ch[j] == c_char)
            {
                found = j;
                break;
            }
        }

        if (found != -1)
        {
            fre[found]++;
        }
        else
        {
            ch[ch_index] = c_char;
            fre[ch_index] = 1;
            ch_index++;
        }
    }
    ch[ch_index] = '\0';
}

// 查找两个权值最小的下标
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
void CreateHuffmanTree(HuffmanTree &HT, int fre[], char ch[])
{
    int n = strlen(ch);
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
        HT[i].weight = fre[i - 1];
        HT[i].ch = ch[i - 1];
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

    HT[0].weight = HT[m].weight;
    HT[0].lchild = HT[m].lchild;
    HT[0].rchild = HT[m].rchild;
}
// 哈夫曼编码
void CreateHuffmanCode(HuffmanTree HT, char **&HC, char ch[])
{
    int n = strlen(ch);
    HC = new char *[n + 1];
    char *cd = new char[n];
    cd[n - 1] = '\0';
    for (int i = 1; i <= n; ++i)
    {
        int start = n - 1;
        int c = i;
        int f = HT[i].parent;

        while (f != 0)
        {
            --start;
            if (HT[f].lchild == c)
            {
                cd[start] = '0';
            }
            else
            {
                cd[start] = '1';
            }
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n - start];
        strcpy(HC[i], &cd[start]);
    }
    delete[] cd;
}

// 编码
void Coding(HuffmanTree HT, char **HC, char content[], char code[])
{
    code[0] = '\0';
    int len = strlen(content);
    for (int i = 1; i <= len; ++i)
    {
        for (int j = 1; j <= len; ++j)
        {
            if (content[i - 1] == HT[j].ch)
            {
                strcat(code, HC[j]);
                break;
            }
        }
    }
}

// 译码
void Decoding(HuffmanTree HT, char code[])
{
    int temp = 0;

    int code_len = strlen(code);
    for (int i = 0; i < code_len; ++i)
    {
        if (code[i] == '0')
            temp = HT[temp].lchild;

        else if (code[i] == '1')
            temp = HT[temp].rchild;

        if (HT[temp].lchild == 0 && HT[temp].rchild == 0)
        {
            cout << HT[temp].ch;
            temp = 0;
        }
    }
    cout << endl;
}
int main()
{
    char content[1024];
    char **HC;
    HuffmanTree HT;
    char code[2048];
    int fre[256];
    char ch[256];
    cout << "待编码的文本:";
    cin >> content;

    countFre(content, fre, ch);
    CreateHuffmanTree(HT, fre, ch);
    CreateHuffmanCode(HT, HC, ch);
    Coding(HT, HC, content, code);
    cout << "编码结果:" << code << endl;
    cout << "译码结果:";
    Decoding(HT, code);

    return 0;
}