#ifndef STACK_H
#define STACK_H

typedef struct {
    int *arr;
    int top;
    int capacity;
    int size;
} Stack;

Stack* newStack(int capacity);

void push(Stack* s, int x);

int pop(Stack* s);

int emptyStack(Stack* s);

void deleteStack(Stack* s);

#endif
