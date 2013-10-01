#include <stdio.h>

int partition(int arr[], int start, int end) {
    if (start == end) {
        return start;
    } else {
        int pivot = end;
        int i;
        int next = start;
        for (i=start; i < end; i++) {
            if (arr[i] <= arr[pivot]) {
                int tmp = arr[next];
                arr[next++] = arr[i];
                arr[i] = tmp;
            }
        }

        int tmp = arr[next];
        arr[next] = arr[pivot];
        arr[pivot] = tmp;

        return next;
    }
}

int kth(int arr[], int start, int end, int k) {
    int pivot = partition(arr, start, end);

    int rank = pivot - start + 1;
    if (rank == k) {
        return arr[pivot];
    } else if (rank < k) {
        return kth(arr, pivot+1, end, k-rank);
    } else {
        return kth(arr, start, pivot-1, k);
    }
}

int main(int argc, char* argv[]) {
    int arr[10] = { 4, 8, 5, 7, 3, 2, 4, 9, 0, 0 };
    printf("The %dth element is %d\n", 5, kth(arr,0,9,5));
    printf("The %dth element is %d\n", 8, kth(arr,0,9,8));

    return 0;
}
