public class BubbleSort {
    public static void sort(int[] arr) {
        for (int i = arr.length - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[j+1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[]{2,3,1,9,8,4,2};
        BubbleSort.sort(arr);

        for (int v : arr) {
            System.out.print(v + " ");
        }
        System.out.println();
    }
}
