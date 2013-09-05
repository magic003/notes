public class InsertionSort {
    public static void sort(int[] arr) {
        for (int i=1; i<arr.length; i++) {
            int j = i;
            while (j>0 && arr[j] < arr[j-1]) {
                int tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
                j--;
            }
        }
    }

    public static void main(String args[]) {
        int[] arr = new int[] { 2,3,1,9,8,4,2 };
        InsertionSort.sort(arr);

        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
