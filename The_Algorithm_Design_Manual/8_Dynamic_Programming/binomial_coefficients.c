#include <stdio.h>
#include <stdlib.h>

int binomial_coefficient(int n, int k) {
    int** m = (int**) malloc((n+1) * sizeof(int*));
    int i,j;
    for (i=0; i <= n; i++) {
        m[i] = (int*) malloc((n+1) * sizeof(int));
        for (j=0; j <= n; j++) {
            m[i][j] = 0;
        }
        m[i][0] = 1;
        m[i][i] = 1;
    }

    for (i=1; i <= n; i++) {
        for (j=1; j < i; j++) {
            m[i][j] = m[i-1][j] + m[i-1][j-1];
        }
    }

    return m[n][k];
}

int main(int argc, char* argv) {
    printf("(%d %d) = %d\n", 5, 3, binomial_coefficient(5, 3));

    return 0;
}
