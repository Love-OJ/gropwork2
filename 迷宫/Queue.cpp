#include "Queue.h"

// ��ʼ������
void initQueue(Queue* q) {
    q->front = 0;  // ��ͷָ���ʼ��Ϊ0
    q->rear = 0;   // ��βָ���ʼ��Ϊ0
}

// ��Ӳ���
void enqueue(Queue* q, const Point& p) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE != q->front) {  // �������Ƿ���
        q->data[q->rear] = p;  // �ڶ�β����Ԫ��
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;  // ���¶�βָ��
    }
}

// ���Ӳ���
Point dequeue(Queue* q) {
    Point p = {-1, -1};  // Ĭ�Ϸ���ֵ
    if (q->front != q->rear) {  // �������Ƿ��
        p = q->data[q->front];  // ȡ����ͷԪ��
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;  // ���¶�ͷָ��
    }
    return p;  // ���س��ӵ�Ԫ��
}

// �ж϶����Ƿ�Ϊ��
bool isQueueEmpty(const Queue* q) {
    return q->front == q->rear;  // ��ͷָ����ڶ�βָ��ʱ������Ϊ��
}
