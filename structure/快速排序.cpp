#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;
// 打乱整型数组
void shuffleIntArray(int *arr, int size)
{
    if (arr == NULL || size <= 1)
    {
        return;
    }
    for (int i = size - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// 打印数组
void printIntArray(const int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 冒泡排序
void Bubblesort(int *arr, int size)
{
    int m = size - 1, t;
    bool flag = true;
    while ((m > 0) && (flag == true))
    {
        flag = false;
        for (int i = 0; i < m; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                flag = true;
                t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                count++;
            }
        }
        m--;
    }
}

// 快速排序
int partition(int *arr, int low, int high)
{
    int temp = arr[low];
    int pivotkey = arr[low];
    while (low < high)
    {
        while (low < high && arr[high] >= pivotkey)
            --high;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivotkey)
            ++low;
        arr[high] = arr[low];
        count += 2;
    }
    arr[low] = temp;
    return low;
}
void Qsort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivotloc = partition(arr, low, high);
        Qsort(arr, low, pivotloc - 1);
        Qsort(arr, pivotloc + 1, high);
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    int arr[] = {5,4,1,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("原数组：");
    printIntArray(arr, size);

    // shuffleIntArray(arr, size);
    // printf("打乱后：");
    // printIntArray(arr, size);

    Bubblesort(arr, size);
    // Qsort(arr, 0, size-1);
    printf("排序后：");
    printIntArray(arr, size);
    printf("%d", count);

    return 0;
}