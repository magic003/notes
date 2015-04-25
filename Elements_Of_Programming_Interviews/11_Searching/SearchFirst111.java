public class SearchFirst111 {
    public int search(int[] arr, int k) {
        if (arr == null || arr.length == 0) return -1;

        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {
            int middle = low + (high-low)/2;
            if (arr[middle] > k) {
                high = middle-1;
            } else if (arr[middle] < k) {
                low = middle+1;
            } else {
                if (low == high) {
                    return low;
                } else {
                    high = middle;
                }
            }
        }
        
        return -1;
    }

    public static void main(String[] args) {
        SearchFirst111 search = new SearchFirst111();
        int[] arr = new int[] {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        System.out.println("2: " + search.search(arr, 2));
        System.out.println("108: " + search.search(arr, 108));
        System.out.println("285: " + search.search(arr, 285));
        System.out.println("400: " + search.search(arr, 400));
    }
}
