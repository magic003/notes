public class BinarySearch {
    public static int binarySearch(int[] arr, int key) {
        if (arr == null) return -1;

        int low = 0;
        int high = arr.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] arr = new int[]{1, 2, 3, 4, 5};
        
        System.out.print("Array: ");
        for (int v : arr) {
            System.out.print(v + ", ");
        }
        System.out.println();

        System.out.printf("Search %d: %d\n", 5, binarySearch(arr, 5));
        System.out.printf("Search %d: %d\n", 9, binarySearch(arr, 9));
    }
}
