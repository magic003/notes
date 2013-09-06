public class Quicksort {
    public static void sort(int[] arr, int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            sort(arr, low, pivot-1);
            sort(arr, pivot+1, high);
        }
    }

    private static int partition(int[] arr, int low, int high) {
        int pivot = high;
        int firsthigh = low;

        for(int i=low;i<high;i++) {
            if (arr[i] <= arr[pivot]) {
                swap(arr,i,firsthigh);
                firsthigh++;
            }
        }

        swap(arr,firsthigh,pivot);

        return firsthigh;
    }

    private static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static void main(String[] args) {
        int[] arr = new int[] { 2,3,1,9,8,4,2 };
        Quicksort.sort(arr, 0, arr.length-1);

        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
