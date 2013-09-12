#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* newQueue(int size) {
    Queue* q = (Queue*) malloc(sizeof(Queue));

    if (q != NULL) {
        q->arr = (int*) malloc(size * sizeof(int));
        q->head = -1;
        q->tail = 0;
        q->size = size;
    }

    return q;
}

void enqueue(Queue* q, int x) {
    
    if (q->tail == q->head) {
        printf("Queue is full.\n");
    } else {
        if (q->head == -1) {
            q->head = 0;
        }
        q->arr[q->tail] = x;
        q->tail = (q->tail + 1) % q->size;
    }
}

int dequeue(Queue* q) {
    if (emptyQueue(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        int result = q->arr[q->head];
        q->head = (q->head + 1) % q->size;
        return result;
    }
}

int emptyQueue(Queue* q) {
    return q->head == -1 || q->head == q->tail;
}   

void deleteQueue(Queue* q) {
    if (q != NULL) {
        if (q->arr != NULL) {
            free(q->arr);
        }
        free(q);
    }
}

int main(int argc, char* argv[]) {
    Queue* q = newQueue(5);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    printf("Empty: %d\n", emptyQueue(q));

    deleteQueue(q);

    return 0;
}
