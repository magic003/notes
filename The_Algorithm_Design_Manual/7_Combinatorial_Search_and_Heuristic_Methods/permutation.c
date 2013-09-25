#include <stdio.h>
#include <stdlib.h>

void printSolution(int* a, int k) {
    printf("{ ");
    int i;
    for ( i = 1; i <= k; i++) {
        printf("%d ", a[i]);
    }
    printf("}\n");
}

int candidates(int* insolution, int n, int c[]) {
    int i;
    int ncandidates = 0;
    for (i=1; i <= n; i++) {
        if (!insolution[i]) {
            c[ncandidates++] = i;
        }
    }

    return ncandidates;
}

void backtrace(int* a, int k, int n, int* insolution) {
    if ( k == n) { // is a solution
        printSolution(a, k);
    } else {
        k += 1;
        int* c = (int*) malloc((n+1) * sizeof(int));
        int ncandidates = candidates(insolution, n, c);
        int i;
        for (i=0; i < ncandidates; i++) {
            a[k] = c[i];
            insolution[c[i]] = 1;
            backtrace(a,k,n,insolution);
            insolution[c[i]] = 0;
        }
    }
}

void permutation(int n) {
    int* a = (int*) malloc((n+1) * sizeof(int)); // solution vector

    int* insolution = (int*) malloc((n+1) * sizeof(int));
    int i;
    for (i=0; i <= n; i++) {
        insolution[i] = 0;
    }

    backtrace(a, 0, n, insolution);
}

int main(int argc, char* argv[]) {
    permutation(4);
    return 0;
}
