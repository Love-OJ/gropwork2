#ifndef QUEUE_H
#define QUEUE_H

#include "Point.h"

const int MAX_QUEUE_SIZE = 100;

struct Queue {
    Point data[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

void initQueue(Queue* q);
void enqueue(Queue* q, const Point& p);
Point dequeue(Queue* q);
bool isQueueEmpty(const Queue* q);

#endif // QUEUE_H
