#include <stdio.h>

int fibonacci(int n) {
    int x1 = 0;
    int x2 = 1;

    if (n == 0) return x1;

    int i;
    for (i=1; i < n; i++) {
        int p = x1;
        x1 = x2;
        x2 = p + x2;
    }

    return x2;
}

int main(int argc, char* argv[]) {
    printf("The %dth fibonacci is: %d\n", 5, fibonacci(5));

    return 0;
}
