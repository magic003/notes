#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int max(int x, int y) {
    return x < y ? y : x;
}

void printPartition(int arr[], int** d, int n, int k) {
    if (k == 0) return;

    int last = d[n][k];
    printPartition(arr, d, last, k-1);

    printf("{");
    int i;
    for (i=last; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("}");
}

void partition(int arr[], int n, int k) {
    int i,j,h;
    int* p = (int*) malloc((n+1) * sizeof(int));
    p[0] = 0;
    for (i=1; i <= n; i++) {
        p[i] = p[i-1] + arr[i-1];
    }

    int** m = (int**) malloc((n+1) * sizeof(int*));
    for (i=0; i <= n; i++) {
        m[i] = (int*) malloc((k+1) * sizeof(int));
    }
    for (i=1; i <= k; i++) {
        m[0][i] = 0;
    }
    for (i=0; i <= n; i++) {
        m[i][1] = p[i];
    }

    int** d = (int**) malloc((n+1) * sizeof(int*));
    for (i=0; i<=n; i++) {
        d[i] = (int*) malloc((k+1) * sizeof(int));
    }

    for (i=1; i <= n; i++) {
        for (j=2; j <= k; j++) {
            int minSum = INT_MAX;
            for (h=0; h<i;h++) {
                int currentSum = max(m[h][j-1], p[i] - p[h]);
                if (minSum > currentSum) {
                    minSum = currentSum;
                    d[i][j] = h;
                }
            }
            m[i][j] = minSum;
        }
    }

    printf("Minimum sum: %d\n", m[n][k]);
    printf("Partition: ");
    printPartition(arr, d, n, k);
    printf("\n");

}

int main(int argc, char* argv[]) {
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    partition(arr, 9, 3);

    return 0;
}
