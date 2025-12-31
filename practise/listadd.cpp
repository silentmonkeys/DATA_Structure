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

// 初始化顺序表
void InitListFromArray(SqList &L, ElemType arr[], int n)
{
    // 初始化容量
    L.capacity = n;
    L.length = 0;
    L.elem = new ElemType[n];
    if (!L.elem)
    {
        // 处理内存分配失败
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        Insert(L, arr[i]); // 插入元素并保持有序
    }
}

// 输出顺序表
void PrintList(const SqList &L)
{
    if (L.length == 0)
    {
        printf("顺序表为空!\n");
        return;
    }

    printf("顺序表元素: [");
    for (int i = 0; i < L.length; i++)
    {
        printf("%d", L.elem[i]); // 假设ElemType是int类型
        if (i < L.length - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
    printf("长度: %d, 容量: %d\n", L.length, L.capacity);
}

// 主要功能
// void Merge_Sq(SqList A, SqList B, SqList &C)
// {

//     // 将两个有序顺序表A和B合成一个有序顺序表C
//     C.length = A.length + B.length;
//     // 设C的表长
//     C.elem = new ElemType[C.length];
//     // 为C动态分配存储空间
//     if (!C.elem)
//     {
//         cerr << "Overflow!" << endl;
//         return;
//     }

//     // 存储分配失败
//     int i = 0;
//     int j = 0;
//     int k = 0;

//     while ((i < A.length) && (j < B.length))
//         if (A.elem[i] <= B.elem[j])
//         {
//             C.elem[k] = A.elem[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             C.elem[k] = B.elem[j];
//             j++;
//             k++;
//         }
//     while (i < A.length)
//     {
//         C.elem[k] = A.elem[i];
//         i++;
//         k++;
//     }
//     while (j < B.length)
//     {
//         C.elem[k] = B.elem[j];
//         j++;
//         k++;
//     }
// }

void Merge_Sq(SqList &A, SqList &B, SqList &C)
{
    // 顺序表C的长度
    // C的表长
    C.length = A.length + B.length;
    // 为C动态分配存储空间
    C.elem = new ElemType[C.length];

    ElemType *pA = A.elem;                // 指向A表当前元素
    ElemType *pB = B.elem;                // 指向B表当前元素
    ElemType *pC = C.elem;                // 指向C表当前插入位置
    ElemType *pA_end = A.elem + A.length; // A表结束位置（最后一个元素的下一个位置）
    ElemType *pB_end = B.elem + B.length; // B表结束位置

    // 数据插入
    while (pA < pA_end && pB < pB_end)
    {
        if (*pA < *pB)
        {
            *pC++ = *pA++; // A中的元素放入C
        }
        else
        {
            *pC++ = *pB++; // B中的元素放入C
        }
    }

    // A,B长度不同，需要处理剩余的元素
    // 处理A
    while (pA < pA_end)
    {
        *pC++ = *pA++;
    }
    // 处理B
    while (pB < pB_end)
    {
        *pC++ = *pB++;
    }
}

int main()
{
    SqList LA, LB, LC;
    int arrA[] = {6, 7, 10, 21};
    int arrB[] = {3, 11, 13, 15, 23, 25, 27};

    int n1 = sizeof(arrA) / sizeof(arrA[0]);
    int n2 = sizeof(arrB) / sizeof(arrB[0]);

    InitListFromArray(LA, arrA, n1);
    InitListFromArray(LB, arrB, n2);

    Merge_Sq(LA, LB, LC);
    
    PrintList(LC);
}
