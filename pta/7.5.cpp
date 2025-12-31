#include <iostream>
using namespace std;

typedef int SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

// 初始化
void InitStack(SqStack &S,int MAXSIZE)
{
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
        return;
    S.top = S.base;
    S.stacksize = MAXSIZE;
}
// 入栈
bool Push(SqStack &S, SElemType e)
{
    if (S.top - S.base == S.stacksize)
        return false;
    *S.top++ = e;
    return true;
}
//判空
bool Empty(SqStack S)
{
    if (S.top == S.base)
        return true;
    return false;
}

// 出栈
bool Pop(SqStack &S)
{
    if (S.top == S.base)
        return false;
    --S.top;
    return true;
}
// 重置
void Restar(SqStack &S){
    S.top = S.base;
}

int main(){
    int m, n;
    char ch;
    cin >> n >> m;
    cin.ignore();
    SqStack S;
    InitStack(S, m);
    for (int i = 0; i < n;i++){
        Restar(S);
        bool state = true;
        while(cin.get(ch)&&ch!='\n'){
            if(ch=='S'){
                state = Push(S, 1);
                if (!state)
                    continue;
            }
            else if(ch=='X'){
                state = Pop(S);
                if (!state)
                    continue;
            }
            if(state==false){
                break;
            }
        }
        if(state&&Empty(S)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}