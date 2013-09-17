#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* newStack(int capacity) {
    Stack* s = (Stack*) malloc(sizeof(Stack));

    s->arr = (int*) malloc(capacity * sizeof(int));
    s->top = -1;
    s->capacity = capacity;
    s->size = 0;

    return s;
}

void push(Stack* s, int x) {
    if (s->size == s->capacity) {
        printf("Stack is full.\n");
    } else {
        (s->top)++;
        s->arr[s->top] = x;
        (s->size)++;
    }
}

int pop(Stack* s) {
    if (s->size == 0) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        (s->size--);
        return s->arr[(s->top)--];
    }
}

int emptyStack(Stack* s) {
    return s->size == 0;
}

void deleteStack(Stack* s) {
    if (s->arr != NULL) {
        free(s->arr);
    }

    free(s);
}
