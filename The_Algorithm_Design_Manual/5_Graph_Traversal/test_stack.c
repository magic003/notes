#include <stdio.h>
#include "stack.h"

int main(int argc, char* argv[]) {
    Stack* s = newStack(10);

    int i;
    for (i=1; i<=5; i++) {
        push(s, i);
    }

    for (i=1; i<=5; i++) {
        printf("%d ", pop(s));
    }
    printf("\n");

    printf("Empty: %d\n", emptyStack(s));

    return 0;
}
