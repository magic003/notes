public class BucketSort {
    public static void sort(int[] arr, int max) {
        int[] bucket = new int[max+1];

        for (int v : arr) {
            bucket[v]++;
        }

        int index = 0;
        for (int i = 0; i < bucket.length; i++) {
            for (int j = 0; j < bucket[i]; j++) {
                arr[index++] = i;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[]{2,3,1,9,8,4,2};

        sort(arr, 10);

        for (int v : arr) {
            System.out.print(v + " ");
        }
        System.out.println();
    }
}
