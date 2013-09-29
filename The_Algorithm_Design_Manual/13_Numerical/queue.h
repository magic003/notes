#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int* arr;
    int head;
    int tail;
    int capacity;
    int size;
} Queue;

Queue* newQueue(int capacity);

void enqueue(Queue* q, int x);

int dequeue(Queue* q);

int emptyQueue(Queue* q);

void deleteQueue(Queue* q);

#endif
