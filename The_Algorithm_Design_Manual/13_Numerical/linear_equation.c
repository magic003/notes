#include <stdio.h>
#include <stdlib.h>

// gaussian elimination
void ge(double** a, double* b, int m, int n, double* result) {
    int i,j,h;
    for (i=0; i < n; i++) {
        int max = i;
        for (j=i+1; j<m; j++) {
            if (a[j][i] > a[max][i]) {
                max = j;
            }
        }

        // swap rows
        if (max != i) {
            double* tmp = a[i];
            a[i] = a[max];
            a[max] = tmp;

            double t = b[i];
            b[i] = b[max];
            b[max] = t;
        }

        for (j=i+1; j<m; j++) {
            double co = a[i][i] / a[j][i];

            for (h=i; h<n; h++) {
                a[j][h] = a[j][h] * co - a[i][h];
            }
            b[j] = b[j] * co - b[i];
        }
    }

    for (i=n-1; i>=0; i--) {
        double r = b[i];
        for (j=i+1; j<n; j++) {
            r -= result[j] * a[i][j];
        }
        result[i] = r / a[i][i];
    }
}

int main(int argc, char* argv[]) {
    double** a = (double**) malloc(4 * sizeof(double*));
    int i;
    for (i=0; i<4;i++) {
        a[i] = (double*) malloc(4 * sizeof(double));
    }

    a[0][0] = 3;
    a[0][1] = 5;
    a[0][2] = 1;
    a[0][3] = 2;

    a[1][0] = 4;
    a[1][1] = 6;
    a[1][2] = 2;
    a[1][3] = 1;
    
    a[2][0] = 2;
    a[2][1] = 4;
    a[2][2] = 10;
    a[2][3] = 5;

    a[3][0] = 6;
    a[3][1] = 7;
    a[3][2] = 9;
    a[3][3] = 4;

    double b[4] = {24, 26, 60, 63};

    double result[4];
    ge(a, b, 4, 4, result);

    printf("Result: ");
    for (i=0; i<4; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}
