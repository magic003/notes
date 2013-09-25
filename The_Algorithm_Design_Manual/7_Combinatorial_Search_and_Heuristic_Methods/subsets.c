#include <stdio.h>
#include <stdlib.h>

void printSolution(int* a, int k) {
    printf("{ ");
    int i;
    for (i=0; i <= k; i++) {
        if (a[i]) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

void backtrace(int* a, int k, int n) {

    if (k == n) { // is a solution
        printSolution(a, k);
    } else {
        k += 1;
        int c[2] = { 0, 1 };

        int i;
        for (i=0; i < 2; i++) {
            a[k] = c[i];
            backtrace(a, k, n);
        }
    }
}

void subsets(int n) {
    int* a = (int*) malloc((n+1) * sizeof(int)); // solution vector
    int i;
    for (i=0; i<=n; i++) {
        a[i] = 0;
    }

    backtrace(a,0,n);    
}

int main(int argc, char* argv[]) {
    subsets(4);
    return 0;
}
