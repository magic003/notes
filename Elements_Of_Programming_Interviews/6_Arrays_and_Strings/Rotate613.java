public class Rotate613 {
    public void rotate(int[] arr, int k) {
        if (arr == null || k < 0) throw new IllegalArgumentException();
        
        int n = arr.length;
        if (n <= 1) return;
        
        k %= n;
        reverse(arr, 0, n-1);
        reverse(arr, 0, k-1);
        reverse(arr, k, n-1);
    }

    private void reverse(int[] arr, int i, int j) {
        for (; i < j; i++, j--) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    public static void main(String[] args) {
        Rotate613 rotate = new Rotate613();
        int[] arr = new int[] {1, 2, 3, 4, 5};
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println(" >> " + 7);
        rotate.rotate(arr, 7);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
