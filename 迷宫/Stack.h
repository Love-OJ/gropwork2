#ifndef STACK_H
#define STACK_H

#include "Point.h"

const int MAX_SIZE = 100;

struct Stack {
    Point data[MAX_SIZE];
    int top;
};

void initStack(Stack* s);
void push(Stack* s, const Point& p);
Point top(const Stack* s);
void pop(Stack* s);
bool isEmpty(const Stack* s);

#endif // STACK_H
