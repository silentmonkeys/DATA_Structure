#include <iostream>
#define MAXQSIZE 100
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
// 循环队列长度
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
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
void DeQueue(SqQueue &Q, QElemType &e)
{
    if (Q.rear == Q.front)
        return;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
}
// 取队头元素
QElemType GetHead(SqQueue Q)
{
    if (Q.front != Q.rear)
        return Q.base[Q.front];
}
// 判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
    return Q.front == Q.rear;
}