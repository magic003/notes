#include <stdio.h>
#include <stdlib.h>

void printPath(char* p, char* t, int** m, int i, int j) {
    if (i == 0 && j == 0) {
        return;
    } else if (i==0) {
        printPath(p,t,m,i,j-1);
        printf("%c ", 'I');
        return;
    } else if (j==0) {
        printPath(p,t,m,i-1,j);
        printf("%c ", 'D');
        return;
    }

    if (p[i-1] == t[j-1] && m[i][j] == m[i-1][j-1]) {
        printPath(p,t,m,i-1,j-1);
        printf("%c ", 'M');
    } else if (m[i][j] == m[i-1][j-1] + 1) {
        printPath(p,t,m,i-1,j-1);
        printf("%c ", 'S');
    } else if (m[i][j] == m[i][j-1]+1) {
        printPath(p,t,m,i,j-1);
        printf("%c ", 'I');
    } else if (m[i][j] == m[i-1][j] + 1) {
        printPath(p,t,m,i-1,j);
        printf("%c ", 'D');
    }

}

void editDistance(char* p, char* t, int m, int n) {
    int** ms = (int**) malloc((m+1) * sizeof(int*));
    int i,j;
    for (i=0; i<=m; i++) {
        ms[i] = (int*) malloc((n+1) * sizeof(int));
    }

    for (i=0;i<=m;i++) {
        ms[i][0] = i;
    }

    for (i=0;i<=n;i++) {
        ms[0][i] = i;
    }

    for (i=1; i<=m; i++) {
        for (j=1; j<=n; j++) {
            int match = ms[i-1][j-1] + ((p[i-1] == t[j-1]) ? 0 : 1);
            int insert = ms[i][j-1] + 1;
            int delete = ms[i-1][j] + 1;

            int cost = match;
            if (cost > insert) {
                cost = insert;
            }

            if (cost > delete) {
                cost = delete;
            }

            ms[i][j] = cost;
        }
    }

    printf("Edit distance: %d\n", ms[m][n]);
    printf("Path: ");
    printPath(p, t, ms, m, n);
    printf("\n");
}

int main(int argc, char* argv[]) {
    editDistance("thou-shalt-not", "you-should-not", 14, 14);

    return 0;
}
