#include <iostream>
#define MAXTSIZE 100
using namespace std;

typedef char TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// 中序遍历
void InOrderTraverse(BiTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}
// 先序创建
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
// 交换
void change(BiTree &LT, BiTree &RT)
{
    BiTree temp = LT;
    LT = RT;
    RT = temp;
}
void switchLR(BiTree T)
{
    if (T)
    {
        change(T->lchild, T->rchild);
        switchLR(T->lchild);
        switchLR(T->rchild);
    }
}
int main()
{
    BiTree T;
    CreateBiTree(T);
    InOrderTraverse(T);
    cout << endl;
    switchLR(T);
    InOrderTraverse(T);
}