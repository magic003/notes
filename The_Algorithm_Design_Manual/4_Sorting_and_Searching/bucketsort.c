#include <stdio.h>
#include <stdlib.h>

void bucketsort(int* arr, int size, int k) {
    int* bucket = malloc((k+1)*sizeof(int));

    int i;
    for (i=0;i<k+1;i++) {
        bucket[i] = 0;
    }

    for (i=0;i<size;i++) {
        bucket[arr[i]]++;
    }

    int pos = 0;
    for (i=0;i<k+1;i++) {
        int j;
        for(j=0;j<bucket[i];j++) {
            arr[pos++] = i;
        }
    }

    free(bucket);
}

int main(int argc, char* argv[]) {
    #define SIZE 7
    int arr[SIZE] = { 2,3,1,9,8,4,2 };
    bucketsort(arr,SIZE,10);

    int i;
    for (i=0;i<SIZE;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
