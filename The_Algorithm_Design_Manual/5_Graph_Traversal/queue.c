#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* newQueue(int capacity) {
    Queue* q = (Queue*) malloc(sizeof(Queue));

    if (q != NULL) {
        q->arr = (int*) malloc(capacity * sizeof(int));
        q->head = -1;
        q->tail = 0;
        q->capacity = capacity;
        q->size = 0;
    }

    return q;
}

void enqueue(Queue* q, int x) {
    
    if (q->size == q->capacity) {
        printf("Failed to add %d because queue is full.\n", x);
    } else {
        if (q->head == -1) {
            q->head = 0;
        }
        q->arr[q->tail] = x;
        q->tail = (q->tail + 1) % q->capacity;
        (q->size)++;
    }
}

int dequeue(Queue* q) {
    if (emptyQueue(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        int result = q->arr[q->head];
        q->head = (q->head + 1) % q->capacity;
        (q->size)--;
        return result;
    }
}

int emptyQueue(Queue* q) {
    return q->size == 0;
}   

void deleteQueue(Queue* q) {
    if (q != NULL) {
        if (q->arr != NULL) {
            free(q->arr);
        }
        free(q);
    }
}

