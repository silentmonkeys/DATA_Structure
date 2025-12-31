#include <iostream>

using namespace std;

// 定义元素的数据类型
typedef int ElemType; // 可以根据需要改为其他类型，如float, char等

// 定义顺序表结构
typedef struct
{
    ElemType *elem; // 指向存储元素的数组
    int length;     // 当前顺序表的长度
    int capacity;   // 顺序表的容量（最大可存储元素数量）
} SqList;

// 插入元素（保持升序）
bool Insert(SqList &L, ElemType e)
{
    if (L.length >= L.capacity)
    {
        return false; // 表已满
    }

    // 找到插入位置
    int i = L.length - 1;
    while (i >= 0 && L.elem[i] > e)
    {
        L.elem[i + 1] = L.elem[i]; // 元素后移
        i--;
    }

    L.elem[i + 1] = e; // 插入元素
    L.length++;        // 长度加1
    return true;
}

// 输出顺序表
void PrintList(const SqList &L)
{
    if (L.length == 0)
    {
        return;
    }

    for (int i = 0; i < L.length-1; i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("%d", L.elem[L.length - 1]);
}

void InitList(SqList &L, int cap) // cap为初始容量
{
    L.capacity = cap;           // 设置容量
    L.length = 0;               // 初始长度为0
    L.elem = new ElemType[cap]; // 分配内存
}

int main()
{
    int n, temp;
    SqList list;
    cin >> n;
    InitList(list, n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        Insert(list, temp);
    }
    PrintList(list);
}
