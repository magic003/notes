#include <stdio.h>
#include <stdlib.h>

void printSelections(int** parent, int* values, int* weights, int n, int w) {
    if (parent[n-1][w] != -1) {
       if (parent[n-1][w] != w) { // n-1 is selected
            printSelections(parent, values, weights, n-1, w-weights[n-1]);
            printf("($%d, %d kg) ", values[n-1], weights[n-1]);
       } else {
            printSelections(parent, values, weights, n-1, w);
       }
    }
}

void knapsack01(int* values, int* weights, int n, int w) {
    int** m = (int**) malloc(n * sizeof(int*));
    int** parent = (int**) malloc(n * sizeof(int*));
    int i,j;
    for (i=0; i<n; i++) {
        m[i] = (int*) malloc((w+1) * sizeof(int));
        parent[i] = (int*) malloc((w+1) * sizeof(int));
    }
    for (i=0; i<n; i++) {
        m[i][0] = 0;
        parent[i][0] = -1;
    }

    for (i=0; i<n; i++) {
        for (j=1; j<=w; j++) {
            if (weights[i] > j) {
                if (i == 0) {
                    m[i][j] = 0;
                    parent[i][j] = -1;
                } else {
                    m[i][j] = m[i-1][j];
                    parent[i][j] = j;
                }
            } else {
                if (i == 0) {
                    m[i][j] = values[i];
                    parent[i][j] = -1;
                } else {
                    int v1 = m[i-1][j-weights[i]] + values[i];
                    int v2 = m[i-1][j];
                    if (v1 >= v2) {
                        m[i][j] = v1;
                        parent[i][j] = j-weights[i];
                    } else {
                        m[i][j] = v2;
                        parent[i][j] = j;
                    }
                }
            }
        }
    }

    printf("Maximum value: %d\n", m[n-1][w]);
    printSelections(parent, values, weights, n, w);
    printf("\n");
}

void printItems(int* items, int* values, int* weights, int n, int w) {
    if (items[w] != -1) {
        printItems(items, values, weights, n, w - weights[items[w]]);
        printf("($%d, %dkg) ", values[items[w]], weights[items[w]]);
    }
}

void knapsackUnbounded(int* values, int* weights, int n, int w) {
    int* m = (int*) malloc((w+1) * sizeof(int));
    int* items = (int*) malloc((w+1) * sizeof(int));
    m[0] = 0;
    items[0] = -1;

    int i,j;
    for (i=1; i<=w; i++) {
        int max = 0;
        int item = -1;
        for (j=0; j<n; j++) {
            if (weights[j] <= i) {
                int v = m[i-weights[j]] + values[j];
                if (max < v) {
                    max = v;
                    item = j;
                }
            }
        }
        m[i] = max;
        items[i] = item;
    }

    printf("Maximum value: %d\n", m[w]);
    printItems(items, values, weights, n, w);
    printf("\n");
}

int main(int argc, char* argv[]) {
    int values[5] = {4, 2, 10, 1, 2};
    int weights[5] = {12, 1, 4, 1, 2};

    printf("0/1 Knapsack\n");
    knapsack01(values, weights, 5, 15);
    printf("\n");

    printf("Unbounded Knapsack\n");
    knapsackUnbounded(values, weights, 5, 15);
    printf("\n");

    return 0;
}
