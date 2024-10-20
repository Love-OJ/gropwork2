#include "Stack.h"

// ��ʼ��ջ
void initStack(Stack* s) {
    s->top = -1;  // ջ��ָ���ʼ��Ϊ-1����ʾջΪ��
}

// ��ջ����
void push(Stack* s, const Point& p) {
    if (s->top < MAX_SIZE - 1) {  // ���ջ�Ƿ���
        s->data[++(s->top)] = p;  // ջ��ָ���1����ֵ
    }
}

// ��ȡջ��Ԫ��
Point top(const Stack* s) {
    return s->data[s->top];  // ����ջ��Ԫ��
}

// ��ջ����
void pop(Stack* s) {
    if (s->top >= 0) {  // ���ջ�Ƿ��
        s->top--;  // ջ��ָ���1
    }
}

// �ж�ջ�Ƿ�Ϊ��
bool isEmpty(const Stack* s) {
    return s->top == -1;  // ջ��ָ��Ϊ-1ʱ��ջΪ��
}
