/***********************************************************/
/* File: selection_sort.c                                  */
/* Selection sort.                                         */
/* Author: Minjie Zha                                      */
/***********************************************************/

#include <stdio.h>

void selectionSort(int* arr, int size) {
    int i;
    for(i=0; i<size; i++) {
        int min = i;
        int j;
        for(j=i+1; j<size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

int main(int argc, char* argv[]) {
    #define SIZE 7
    int arr[SIZE] = {2,3,1,10,8,7,9};
    selectionSort(arr, SIZE);

    int i;
    for(i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
