
//队列在bfs的时候使用
#include "Queue.h"

// 初始化队列
void initQueue(Queue* q) {
    q->front = 0;  // 队头指针初始化为0
    q->rear = 0;   // 队尾指针初始化为0
}

// 入队操作
void enqueue(Queue* q, const Point& p) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE != q->front) {  // 检查队列是否满
        q->data[q->rear] = p;  // 在队尾插入元素
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;  // 更新队尾指针
    }
}

// 出队操作
Point dequeue(Queue* q) {
    Point p = {-1, -1};  // 默认返回值
    if (q->front != q->rear) {  // 检查队列是否空
        p = q->data[q->front];  // 取出队头元素
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;  // 更新队头指针
    }
    return p;  // 返回出队的元素
}

// 判断队列是否为空
bool isQueueEmpty(const Queue* q) {
    return q->front == q->rear;  // 队头指针等于队尾指针时，队列为空
}
