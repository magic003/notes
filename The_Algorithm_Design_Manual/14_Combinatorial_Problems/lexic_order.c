/*
 * It generates a permutation in lexicographic order.
 */

#include <stdio.h>

int getk(int* arr, int size) {
    int k = -1;
    int i;
    for(i=0; i<size-1; i++) {
        if (arr[i] < arr[i+1]) {
            k = i;
        }
    }

    return k;
}

int getl(int* arr, int size, int k) {
    int l = -1;

    int i;
    for(i=0;i<size;i++) {
        if (arr[i] > arr[k]) {
            l = i;
        }
    }

    return l;
}

void reverse(int* arr, int start, int end) {
    while (start < end) {
        int tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
}

void printArray(int* arr, int size) {
    int i;
    printf("[ ");
    for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void lexicOrder(int* arr, int size) {
    int k = getk(arr,size);
    int l;

    while (k != -1) {
        l = getl(arr,size,k);
        // swap l and k
        int tmp = arr[l];
        arr[l] = arr[k];
        arr[k] = tmp;

        reverse(arr, k+1, size-1);

        printArray(arr, size);

        k = getk(arr,size);
    }
}

int main(int argc, char* argv[]) {
    int arr[4] = {1,2,3,4};

    lexicOrder(arr, 4);

    return 0;
}
