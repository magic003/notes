#include <stdio.h>
#include <stdlib.h>

int** matrixMultiplication(int** a,  int** b, int x, int y, int z) {
    int** result = (int**) malloc(x * sizeof(int*));
    int i,j,h;
    for (i=0; i<x; i++) {
        result[i] = (int*) malloc(z * sizeof(int));
    }

    for (i=0; i<x; i++) {
        for (j=0; j<z; j++) {
            result[i][j] = 0;
            for (h=0; h<y; h++) {
                result[i][j] += a[i][h] * b[h][j];
            }
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    int x=4, y=3, z = 2;
    int** a = (int**) malloc(x * sizeof(int*));
    int r1[] = {4, 3, 3};
    int r2[] = {1, 9, 8};
    int r3[] = {2, 4, 0};
    int r4[] = {5, 7, 6};
    a[0] = r1;
    a[1] = r2;
    a[2] = r3;
    a[3] = r4;

    int** b = (int**) malloc(y * sizeof(int*));
    int b1[] = {4, 9};
    int b2[] = {7, 2};
    int b3[] = {2, 1};
    b[0] = b1;
    b[1] = b2;
    b[2] = b3;

    int** result = matrixMultiplication(a,b,x,y,z);

    printf("Result: \n");
    int i,j;
    for (i=0; i<x; i++) {
        for (j=0; j<z; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
