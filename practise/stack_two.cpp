#include <iostream>
#define MAXSIZE 100
typedef int SElemType;
typedef struct
{
    SElemType *base;
    SElemType top1;
    SElemType top2;
    int stacksize;
} DSqStack;

//  初始化
void InitStack(DSqStack &S)
{
    S.base = new SElemType[MAXQSIZE];
    S.top1 = -1;
    S.top2 = MAXQSIZE;
    S.stacksize = MAXQSIZE;
}
// 判空
int Empty1(DSqStack S)
{
    return S.top1 == -1;
}
int Empty2(DSqStack S)
{
    return S.top2 == MAXQSIZE;
}
// 判满
int Full(DSqStack S)
{
    return S.top1 + 1 == S.top2;
}
// 入栈
int Push1(DSqStack &S, SElemType e)
{
    if (Full(S))
        return 0;
    S.base[++(S.top1)] = e;
    return 1;
}
int Push2(DSqStack &S, SElemType e)
{
    if (Full(S))
        return 0;
    S.base[--(S.top2)] = e;
    return 1;
}
// 出栈
int Pop1(DSqStack &S, SElemType &e)
{
    if (Empty1(S))
        return 0;
    e = S.base[S.top1--];
    return 1;
}
int Pop2(DSqStack &S, SElemType &e)
{
    if (Empty2(S))
        return 0;
    e = S.base[S.top2++];
    return 1;
}

int main()
{
    DSqStack S;
    SElemType e; // 用于接收出栈元素

    // 初始化双栈
    InitStack(S);
    std::cout << "双栈初始化完成！" << std::endl;

    // 测试栈1入栈
    std::cout << "\n===== 测试栈1入栈 =====" << std::endl;
    for (int i = 1; i <= 5; i++)
    {
        if (Push1(S, i))
        {
            std::cout << "栈1入栈成功：" << i << "，当前栈1顶指针：" << S.top1 << std::endl;
        }
        else
        {
            std::cout << "栈1入栈失败：" << i << std::endl;
        }
    }

    // 测试栈2入栈
    std::cout << "\n===== 测试栈2入栈 =====" << std::endl;
    for (int i = 10; i <= 15; i++)
    {
        if (Push2(S, i))
        {
            std::cout << "栈2入栈成功：" << i << "，当前栈2顶指针：" << S.top2 << std::endl;
        }
        else
        {
            std::cout << "栈2入栈失败：" << i << std::endl;
        }
    }

    // 测试栈满情况
    std::cout << "\n===== 测试栈满 =====" << std::endl;
    std::cout << "当前双栈是否已满？" << (Full(S) ? "是" : "否") << std::endl;
    // 继续入栈直到栈满
    int count = 0;
    while (!Full(S))
    {
        Push1(S, 100 + count); // 往栈1继续塞元素
        count++;
    }
    std::cout << "持续入栈" << count << "个元素后，双栈已满！" << std::endl;
    std::cout << "再次尝试入栈：";
    if (Push1(S, 999))
    {
        std::cout << "入栈成功（异常）" << std::endl;
    }
    else
    {
        std::cout << "入栈失败（正常）" << std::endl;
    }

    // 测试栈1出栈
    std::cout << "\n===== 测试栈1出栈 =====" << std::endl;
    while (!Empty1(S))
    {
        if (Pop1(S, e))
        {
            std::cout << "栈1出栈成功：" << e << "，当前栈1顶指针：" << S.top1 << std::endl;
        }
        else
        {
            std::cout << "栈1出栈失败" << std::endl;
        }
    }
    // 测试栈1空栈出栈
    std::cout << "栈1已空，尝试再次出栈：";
    if (Pop1(S, e))
    {
        std::cout << "出栈成功（异常）" << std::endl;
    }
    else
    {
        std::cout << "出栈失败（正常）" << std::endl;
    }

    // 测试栈2出栈
    std::cout << "\n===== 测试栈2出栈 =====" << std::endl;
    while (!Empty2(S))
    {
        if (Pop2(S, e))
        {
            std::cout << "栈2出栈成功：" << e << "，当前栈2顶指针：" << S.top2 << std::endl;
        }
        else
        {
            std::cout << "栈2出栈失败" << std::endl;
        }
    }
    // 测试栈2空栈出栈
    std::cout << "栈2已空，尝试再次出栈：";
    if (Pop2(S, e))
    {
        std::cout << "出栈成功（异常）" << std::endl;
    }
    else
    {
        std::cout << "出栈失败（正常）" << std::endl;
    }

    // 释放内存
    delete[] S.base;
    std::cout << "\n测试结束，内存已释放！" << std::endl;

    return 0;
}