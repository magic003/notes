#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int* arr;
    int head;
    int tail;
    int size;
} Queue;

Queue* newQueue(int size);

void enqueue(Queue* q, int x);

int dequeue(Queue* q);

int emptyQueue(Queue* q);

void deleteQueue(Queue* q);

#endif
