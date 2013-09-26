#include <stdlib.h>
#include <stdio.h>

void printPath(int arr[], int precedence[], int size, int end) {
    if (end != -1) {
        printPath(arr, precedence, size, precedence[end]);
        printf("%d ", arr[end]);
    }
}

void lis(int arr[], int size) {
    int* l = (int*) malloc(size * sizeof(int));
    int* precedence = (int*) malloc(size * sizeof(int));

    l[0] = 1;
    precedence[0] = -1;
    int i,j;
    int max = 0;
    int end = -1;
    for (i=0; i < size; i++) {
        int maxlen = 1;
        int p = -1;
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && (l[j]+1) > maxlen) {
                maxlen++;
                p = j;
            }
        }

        l[i] = maxlen;
        precedence[i] = p;

        if (maxlen > max) {
            max = maxlen;
            end = i;
        }
    }

    printf("Length: %d\n", max);

    printf("Sequence: ");
    printPath(arr, precedence, size, end);

    printf("\n");
}

int main(int argc, char* argv[]) {
    int arr[] = {2,4,3,5,1,7,6,9,8};
    lis(arr, 9);

    return 0;
}
