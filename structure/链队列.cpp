#include <iostream>

using namespace std;

typedef int QElemType;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQune;

// 初始化
void InitQuenue(LinkQune &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
}

// 入队
void EnQueue(LinkQune &Q, QElemType e)
{
    QueuePtr p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

//出队
void DeQueue(LinkQune &Q,QElemType &e){
    if(Q.front==Q.rear)
        return;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(Q.rear==p)
        Q.rear = Q.front;
    delete p;
}

//取队头
QElemType GetHead(LinkQune Q){
    if(Q.front!=Q.rear){
        return Q.front->next->data;
    }
}

//获取队列长度
int QueueLen(LinkQune Q)
{
    int len = 0;
    QueuePtr p = Q.front->next;
    while (p) 
    {
        ++len;
        p = p->next;
    }
    return len;
}