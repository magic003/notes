public class MergeSort {
    
    public static void sort(int[] arr, int low, int high) {
        if (low < high) {
            int middle = (low + high) / 2;
            sort(arr, low, middle);
            sort(arr, middle+1, high);
            merge(arr, low, middle, high);
        }
    }

    private static void merge(int[] arr, int low, int middle, int high) {
        int len1 = middle - low + 1;
        int[] arr1 = new int[len1];
        int len2 = high - middle;
        int[] arr2 = new int[len2];

        for (int i=0;i<len1;i++) {
            arr1[i] = arr[low+i];
        }
        for (int i=0;i<len2;i++) {
            arr2[i] = arr[middle+1+i];
        }

        int i, p, q;
        for (i=low,p=0,q=0;p<len1 && q<len2;i++) {
            if (arr1[p] <= arr2[q]) {
                arr[i] = arr1[p++];
            } else {
                arr[i] = arr2[q++];
            }
        }

        while (p<len1) arr[i++] = arr1[p++];
        while (q<len2) arr[i++] = arr2[q++];
    }

    public static void main(String[] args) {
        int[] arr = new int[] { 2,3,1,9,8,4,2 };
        MergeSort.sort(arr, 0, arr.length-1);

        for (int i=0;i<arr.length;i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
