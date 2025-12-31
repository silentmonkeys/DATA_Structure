#include <iostream>
#include <cstring>
#define MAXSIZE 100
using namespace std;

typedef int SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;
// 初始化
void InitStack(SqStack &S)
{
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
        return;
    S.top = S.base;
    S.stacksize = MAXSIZE;
}
// 入栈
void Push(SqStack &S, SElemType e)
{
    if (S.top - S.base == S.stacksize)
        return;
    *S.top++ = e;
}
// 出栈
void Pop(SqStack &S, SElemType &e)
{
    if (!S.base)
        return;
    e = *--S.top;
}
// 取栈顶元素
SElemType GetTop(SqStack S)
{
    if (S.top != S.base)
        return *(S.top - 1);
}
int main(){
    SqStack S;
    string line;
    InitStack(S);
    while(true){
        getline(cin, line);
        if(line==".")
            break;
        
    }
}