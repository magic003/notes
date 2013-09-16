#include <stdio.h>
#include "queue.h"

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
