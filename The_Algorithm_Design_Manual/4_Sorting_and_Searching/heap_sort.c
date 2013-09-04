/**************************************************************/
/* File: heap_sort.c                                          */
/* Heap sort.                                                 */
/**************************************************************/

#include <stdio.h>

void siftDown(int* arr, int size, int i) {
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size) { // it is not the leaf node
        int sift = left;

        if (right < size && arr[left] < arr[right]) {
            sift = right;
        }

        if (arr[i] < arr[sift]) {
            int tmp = arr[i];
            arr[i] = arr[sift];
            arr[sift] = tmp;
            siftDown(arr, size, sift);
        }
    }
}

void heapify(int* arr, int size) {
    int i;
    for (i=(size-2)/2;i>=0;i--) {
        siftDown(arr, size, i);
    }
}

void heapSort(int* arr, int size) {
    heapify(arr, size);

    int n = size;
    while (n > 1) {
        int max = arr[0];
        arr[0] = arr[n-1];
        arr[n-1] = max;
        n--;
        siftDown(arr,n,0);
    }
}

int main(int argc, char* argv[]) {
    #define SIZE 7
    int arr[SIZE] = {2,3,1,10,8,7,9};
    heapSort(arr, SIZE);

    int i;
    for(i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
