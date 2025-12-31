#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct
{
    ElemType *elem; 
    int length;
    int capacity;
} SqList;

// 插入元素（升序）
bool Insert(SqList &L, ElemType e)
{
    if (L.length >= L.capacity)
    {
        return false;
    }
    int i = L.length - 1;
    while (i >= 0 && L.elem[i] > e)
    {
        L.elem[i + 1] = L.elem[i];
        i--;
    }

    L.elem[i + 1] = e; 
    L.length++;       
    return true;
}

// 初始化
void InitList(SqList &L, int n)
{
    L.capacity = n;
    L.length = 0;
    L.elem = new ElemType[n];
    if (!L.elem)
    {
        exit(1);
    }
}

// 输出顺序表
void PrintList(const SqList &L)
{
    if (L.length == 0)
    {
        return;
    }

    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.elem[i]);

    }
}
//合并
void Merge_Sq(SqList &A, SqList &B, SqList &C)
{
    C.length = A.length + B.length;
    C.elem = new ElemType[C.length];

    ElemType *pA = A.elem;               
    ElemType *pB = B.elem;         
    ElemType *pC = C.elem;                
    ElemType *pA_end = A.elem + A.length; 
    ElemType *pB_end = B.elem + B.length;

    while (pA < pA_end && pB < pB_end)
    {
        if (*pA < *pB)
        {
            *pC++ = *pA++;
        }
        else
        {
            *pC++ = *pB++; 
        }
    }

    while (pA < pA_end)
    {
        *pC++ = *pA++;
    }
    while (pB < pB_end)
    {
        *pC++ = *pB++;
    }
}

int main()
{
    SqList LA, LB, LC;
    int m, n,LA_elem,LB_elem;

    cin >> m;
    InitList(LA, m);
    for (int i = 0; i < m;i++){
        cin >> LA_elem;
        Insert(LA, LA_elem);
    }
    cin >> n;
    InitList(LB, n);
    for (int i = 0; i < n; i++)
    {
        cin >> LB_elem;
        Insert(LB, LB_elem);
    }

    Merge_Sq(LA, LB, LC);

    PrintList(LC);
}
