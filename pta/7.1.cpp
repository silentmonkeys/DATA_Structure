#include <iostream>
#define MAXQSIZE 1000
using namespace std;

typedef int QElemType;

typedef struct
{
    QElemType *base;
    int front;
    int rear;
} SqQueue;

// 初始化
void InitQueue(SqQueue &Q)
{
    Q.base = new QElemType[MAXQSIZE];
    if (!Q.base)
        return;
    Q.front = Q.rear = 0;
}
// 入队
void EnQueue(SqQueue &Q, QElemType e)
{
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
}
// 出队
bool DeQueue(SqQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return false;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return true;
}
// 循环队列长度
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

int main()
{
    SqQueue A, B;
    InitQueue(A);
    InitQueue(B);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num % 2 == 1)
            EnQueue(A, num);
        else
            EnQueue(B, num);
    }
    int count = 0;
    QElemType e;

    while (QueueLength(A)>0&& QueueLength(B)>0)
    {
        if (DeQueue(A, e))
        {
            if (count != 0)
                cout << " ";
            cout << e;
            count++;
        }
        if (DeQueue(A, e))
        {
            if (count != 0)
                cout << " ";
            cout << e;
            count++;
        }
        if (DeQueue(B, e))
        {
            if (count != 0)
                cout << " ";
            cout << e;
            count++;
        }
    }
    while (QueueLength(A) > 0)
    {
        if (DeQueue(A, e))
        {
            if (count != 0)
                cout << " ";
            cout << e;
            count++;
        }
    }
    while (QueueLength(B) > 0)
    {
        if (DeQueue(B, e)){
            if (count != 0)
                cout << " ";
            cout << e;
            count++;
        }
            
    }
}