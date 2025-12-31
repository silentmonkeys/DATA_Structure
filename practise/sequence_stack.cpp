#include <iostream>
#define MAXSiZE 100
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
    S.base = new SElemType[MAXSiZE];
    S.top = S.base;
    S.stacksize = MAXSiZE;
}

// 入栈
void Push(SqStack &S, SElemType e)
{
    if (S.top - S.base == S.stacksize)
        return;
    *S.top++ = e;
}
//出栈
void Pop(SqStack &S,SElemType &e)
{
    if(S.top==S.base)
        return;
    e = *--S.top;
}
//取栈顶元素
SElemType Gettop(SqStack S){
    if(S.top!=S.base)
        return *(S.top - 1);
}

int main(){
    SqStack test;
    InitStack(test);
    Push(test, 12);
    Push(test, 14);
    Push(test, 16);
    Push(test, 11);

    std::cout << Gettop(test);
}