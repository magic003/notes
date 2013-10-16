#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* grayCode(int n) {
    int * subset = (int*) malloc(sizeof(int) * (1 << n));
    subset[0] = 0;
    subset[1] = 1;
    int i;
    for (i=1; i<=n; i++) {
        int j;
        int last = 1 << i;
        for (j=0; j<last; j++) {
            subset[last+j] = subset[last-1-j];
        }

        for (j=last; j<2*last; j++) {
            subset[j] = (1 << i) | subset[j];
        }
    }

    return subset;
}

void printSubset(char* set, int gc) {
    int i = 0;
    printf("{ ");
    while (gc != 0) {
        if (gc & 1) {
           printf("%c ", set[i]); 
        }

        gc = gc >> 1;
        i++;
    }

    printf("}\n");
}

int intToGrayCode(int n) {
    return (n >> 1) ^ n;
}

int main(int argc, char* argv[]) {
    char set[4] = {'a', 'b', 'c', 'd'};
    int* subset = grayCode(4);
    int i;
    for (i=0; i < 1 << 4; i++) {
        printSubset(set, subset[i]);
    }

    printf("---\n");
    for (i=0; i < 1 << 4; i++) {
        printSubset(set, intToGrayCode(i));
    }

    return 0;
}
