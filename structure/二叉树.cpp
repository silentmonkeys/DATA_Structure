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
/*先序：根左右
中序：左根右
后序：左右根*/
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
// 复制二叉树
void Copy(BiTree T, BiTree &NewT)
{
    if (T == NULL)
    {
        NewT = NULL;
        return;
    }
    else
    {
        NewT = new BiTNode;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild, NewT->rchild);
    }
}
//计算二叉树的深度
int Depth(BiTree T){
    int m,n;
    if(T==NULL)
        return 0;
    else{
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        if(m>n)
            return (m + 1);
        else
            return (n + 1);
    }
}
//统计二叉树的节点个数
int NodeCount(BiTree T){
    if(T==NULL)
        return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild)+1;
}

int main(){
    BiTree T;
    CreateBiTree(T);
    InOrderTraverse(T);
}