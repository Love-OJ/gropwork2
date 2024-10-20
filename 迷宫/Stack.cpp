#include "Stack.h"

// 初始化栈
void initStack(Stack* s) {
    s->top = -1;  // 栈顶指针初始化为-1，表示栈为空
}

// 入栈操作
void push(Stack* s, const Point& p) {
    if (s->top < MAX_SIZE - 1) {  // 检查栈是否满
        s->data[++(s->top)] = p;  // 栈顶指针加1并赋值
    }
}

// 获取栈顶元素
Point top(const Stack* s) {
    return s->data[s->top];  // 返回栈顶元素
}

// 出栈操作
void pop(Stack* s) {
    if (s->top >= 0) {  // 检查栈是否空
        s->top--;  // 栈顶指针减1
    }
}

// 判断栈是否为空
bool isEmpty(const Stack* s) {
    return s->top == -1;  // 栈顶指针为-1时，栈为空
}
