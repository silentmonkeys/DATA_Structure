#include <iostream>
#include <cstring>
using namespace std;

typedef struct
{
    char num[4];
    char name[10];
    double price;
    int count;
    double sale;
} Data;

typedef Data ElemType;

typedef struct
{
    ElemType *elem;
    int length;
} Sqlist;

void InitList(Sqlist &L)
{
    L.elem = new ElemType[101];
    if (!L.elem)
        return;
    L.length = 0;
}

// 插入
void ListInsert(Sqlist &L, int i, ElemType e)
{
    if (L.length == 101)
        return;
    for (int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];
    L.elem[i] = e;
    ++L.length;
}

// 编号(直接插入)
void Sort_num(Sqlist &L)
{
    int i, j;
    for (i = 2; i < L.length; ++i)
    {
        if (strcmp(L.elem[i].num, L.elem[i - 1].num) < 0)
        {
            L.elem[0] = L.elem[i];
            L.elem[i] = L.elem[i - 1];
            for (j = i - 2; strcmp(L.elem[0].num, L.elem[j].num) < 0; --j)
            {
                L.elem[j + 1] = L.elem[j];
            }
            L.elem[j + 1] = L.elem[0];
        }
    }
}

// 名称(冒泡)
void Sort_name(Sqlist &L)
{
    int m = L.length - 1;
    bool flag = true;
    while ((m > 0) && flag)
    {
        flag = false;
        for (int j = 1; j <= m; j++)
        {
            if (strcmp(L.elem[j].name, L.elem[j + 1].name) > 0)
            {
                flag = true;
                L.elem[0] = L.elem[j];
                L.elem[j] = L.elem[j + 1];
                L.elem[j + 1] = L.elem[0];
            }
            --m;
        }
    }
}

// 单价(简单选择)
void Sort_price(Sqlist &L)
{
    for (int i = 1; i < L.length; ++i)
    {
        int k = i;
        for (int j = i + 1; j < L.length; ++j)
            if (L.elem[j].price < L.elem[k].price)
                k = j;
        if (k != i)
        {
            L.elem[0] = L.elem[i];
            L.elem[i] = L.elem[k];
            L.elem[k] = L.elem[0];
        }
    }
}

// 销售量(快速排序)
int Partition(Sqlist &L, int low, int high)
{
    L.elem[0] = L.elem[low];
    int pivotkry = L.elem[low].count;
    while (low < high)
    {
        while (low < high && L.elem[high].count >= pivotkry)
            --high;
        L.elem[low] = L.elem[high];
        while (low < high && L.elem[low].count <= pivotkry)
            ++low;
        L.elem[high] = L.elem[low];
    }
    L.elem[low] = L.elem[0];
    return low;
}
void QSort(Sqlist &L, int low, int high)
{
    if (low < high)
    {
        int pivotloc = Partition(L, low, high);
        QSort(L, low, pivotloc - 1);
        QSort(L, pivotloc + 1, high);
    }
}
void Sort_count(Sqlist &L)
{
    QSort(L, 1, L.length);
}

// 销售额(归并排序)
void Merge(ElemType R[], ElemType T[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (R[i].sale <= R[j].sale)
            T[k++] = R[i++];
        else
            T[k++] = R[j++];
    }
    while (i <= mid)
        T[k++] = R[i++];
    while (j <= high)
        T[k++] = R[j++];
}
void MSort(ElemType R[], ElemType T[], int low, int high)
{
    if (low == high)
    {
        T[low] = R[low];
    }
    else
    {
        int mid = (low + high) / 2;
        ElemType *S = new ElemType[101];
        MSort(R, S, low, mid);
        MSort(R, S, mid + 1, high);
        Merge(S, T, low, mid, high);
    }
}
void Sort_sale(Sqlist &L)
{
    MSort(L.elem, L.elem, 1, L.length);
}
// 输出
void Print(Sqlist L)
{
    cout << "=========================================" << endl;
    cout << "编号    名称    单价    销售量    销售额" << endl;
    for (int j = 1; j <= L.length; j++)
        printf("%4s %4s %4f %4d %4f\n", L.elem[j].num, L.elem[j].name, L.elem[j].price, L.elem[j].count, L.elem[j].sale);
    cout << "=========================================" << endl;
}
int main()
{
    Sqlist L;
    ElemType e;
    InitList(L);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> e.num >> e.name >> e.price >> e.count;
        e.sale = e.price * e.count;
        ListInsert(L, i, e);
    }
    cout << "原始数据：" << endl;
    Print(L);
    cout << "编号(直接插入排序)" << endl;
    Sort_num(L);
    Print(L);
    cout << "名称(冒泡排序)" << endl;
    Sort_name(L);
    Print(L);
    cout << "单价(简单选择排序)" << endl;
    Sort_price(L);
    Print(L);
    cout << "销售量(快速排序)" << endl;
    Sort_count(L);
    Print(L);
    cout << "销售额(归并排序)" << endl;
    Sort_sale(L);
    Print(L);

    return 0;
}