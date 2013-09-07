#include <stdio.h>

int binarySearch(int* arr, int low, int high, int key) {
    if (low > high) return -1;

    int middle = (low + high) / 2;

    if (arr[middle] == key) {
        if (arr[middle-1] < key) {
            return middle;
        } else {
            return binarySearch(arr, low, middle-1, key);
        }
    } else {
        return binarySearch(arr, middle+1, high, key);
    }
}

int oneSide(int* arr, int key) {
    int interval = 1;

    while (arr[interval] != key) {
        interval *= 2;
    }

    return binarySearch(arr, interval/2 + 1, interval, key);
}

int main(int argc, char* argv[]) {
    int arr[10] = {0,0,0,1,1,1,1,1,1,1};

    int i;
    for(i=0;i<10;i++) {
        printf("%d ", arr[i]);
    }
    printf(": %d\n", oneSide(arr, 1));

    return 0;
}
