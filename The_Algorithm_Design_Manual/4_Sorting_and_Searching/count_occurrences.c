#include <stdio.h>

int highBound(int* arr, int key, int low, int high) {
    if (low > high) return low;

    int middle = (low + high) / 2;

    if (arr[middle] > key) {
        return highBound(arr, key, low, middle-1);
    } else {
        return highBound(arr, key, middle+1, high);
    }
}

int lowBound(int* arr, int key, int low, int high) {
    if (low > high) return low;

    int middle = (low + high) / 2;

    if (arr[middle] < key) {
        return lowBound(arr, key, middle+1, high);
    } else {
        return lowBound(arr, key, low, middle-1);
    }
}

int count(int* arr, int size, int key) {
    int low = lowBound(arr, key, 0, size-1);
    int high = highBound(arr, key, 0, size-1);

    return high-low;
}

int main(int argc, char* argv[]) {
    int arr1[3] = {1,2,3};
    int arr2[3] = {1,3,4};
    int arr3[5] = {1,2,2,2,3};

    printf("Count %d in arrays:\n", 2);

    int i;
    for(i=0;i<3;i++) {
        printf("%d ", arr1[i]);
    }
    printf(": %d\n", count(arr1, 3, 2));

    for(i=0;i<3;i++) {
        printf("%d ", arr2[i]);
    }
    printf(": %d\n", count(arr2, 3, 2));

    for(i=0;i<5;i++) {
        printf("%d ", arr3[i]);
    }
    printf(": %d\n", count(arr3, 5, 2));

    return 0;
}
