#include <stdio.h>

int binarySearch(int* arr, int key, int low, int high) {
    if (low > high) return -1;

    int middle = (low + high) / 2;

    if (arr[middle] == key) return middle;

    if (arr[middle] < key) {
        return binarySearch(arr, key, middle+1, high);
    } else {
        return binarySearch(arr, key, low, middle-1);
    }
}

int main(int argc, char* argv[]) {
    #define SIZE 5
    int arr[SIZE] = {1,2,3,4,5};

    int i;
    for(i=0;i<SIZE;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Search %d: %d\n", 5, binarySearch(arr, 5, 0, SIZE-1));
    printf("Search %d: %d\n", 9, binarySearch(arr, 9, 0, SIZE-1));

    return 0;
}
