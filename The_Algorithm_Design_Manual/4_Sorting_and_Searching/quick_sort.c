/****************************************************************/
/* File: quick_sort.c                                           */
/* Quick sort.                                                  */
/****************************************************************/

#include <stdio.h>

void swap(int* arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int* arr, int low, int high) {
    int pivot = high;

    int firsthigh = low;
    int i;

    for (i=low;i<high;i++) {
        if (arr[i] <= arr[pivot]) {
            swap(arr,i,firsthigh);
            firsthigh++;
        }
    }

    swap(arr,firsthigh,pivot);

    return firsthigh;

}

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }
}

int main(int argc, char* argv[]) {
    #define SIZE 7 
    int arr[SIZE] = { 2,3,1,9,8,4,2 };
    quicksort(arr, 0, SIZE-1);

    int i;
    for (i=0;i<SIZE;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
