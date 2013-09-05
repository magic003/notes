/**************************************************************/
/* File: merge_sort.c                                         */
/* Merge sort.                                                */
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int low, int middle, int high) {
    int len1 = middle - low + 1;
    int* arr1 = malloc(len1 * sizeof(int));
    int len2 = high - middle;
    int* arr2 = malloc(len2 * sizeof(int));

    int p;
    for (p=0; p<len1; p++) {
        arr1[p] = arr[low+p];
    }

    int q;
    for (q=0; q<len2; q++) {
        arr2[q] = arr[middle+q+1];
    }

    int i=low;
    p = q = 0;
    while (p < len1 && q < len2) {
        if (arr1[p] <= arr2[q]) {
            arr[i] = arr1[p];
            p++;
        } else {
            arr[i] = arr2[q];
            q++;
        }
        i++;
    }

    while (p < len1) arr[i++] = arr1[p++];
    while (q < len2) arr[i++] = arr2[q++];

    free(arr1);
    free(arr2);
}

void mergeSort(int* arr, int low, int high) {

    if (low < high) {
        int middle = (low + high) / 2;
        mergeSort(arr, low, middle);
        mergeSort(arr, middle+1, high);
        merge(arr, low, middle, high);
    }
}

int main(int argc, char* argv[]) {
    #define SIZE 7
    int arr[SIZE] = { 2,3,1,9,8,4,2 };
    mergeSort(arr, 0, SIZE-1);

    int i;
    for (i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
