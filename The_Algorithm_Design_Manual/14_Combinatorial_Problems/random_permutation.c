/*
 * It implements the modern "Fisher-Yates shuffle" algorithm to generate a random permutation.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomPermutation(int* arr, int size) {
    int i;

    srand(time(NULL));
    for (i=size-1; i>0; i--) {
        int di = rand() % i;
        int tmp = arr[di];
        arr[di] = arr[i];
        arr[i] = tmp;
    }
}

void printArray(int* arr, int size) {
    int i;
    printf("[ ");
    for (i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main(int argc, char* argv[]) {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    randomPermutation(arr,10);
    printArray(arr,10);

    return 0;
}
