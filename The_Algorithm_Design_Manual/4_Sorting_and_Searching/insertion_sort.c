/************************************************************/
/* File: insertion_sort.c                                   */
/* Insertion sort.                                          */
/************************************************************/

#include <stdio.h>

void insertionSort(int* arr, int size) {
    int i;
    for (i=2; i<size; i++) {
        int j=i;
        while (j>0 && arr[j] < arr[j-1]) {
            int tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            j--;
        }
    }
}

int main(int argc, char* argv[]) {
    #define SIZE 7

    int arr[SIZE] = {2, 3, 1, 10, 8, 7, 9};
    insertionSort(arr, SIZE);

    int i;
    for (i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
