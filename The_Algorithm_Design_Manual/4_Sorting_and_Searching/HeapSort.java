public class HeapSort {
    public void sort(int[] arr) {
        heapify(arr);

        for(int len=arr.length; len > 1; ) {
            int max = arr[0];
            arr[0] = arr[len-1];
            arr[len-1] = max;
            siftDown(arr, 0, --len);
        }
    }

    private void heapify(int[] arr) {
        for (int i=(arr.length-2)/2; i>=0; i--) {
            siftDown(arr, i, arr.length);
        }
    }

    private void siftDown(int[] arr, int start, int end) {
        int root = start;

        while (2*root+1 < end) {
            int left = 2*root + 1;
            int right = 2*root + 2;
            int sift = left;
            if (right < end && arr[left] < arr[right]) {
                sift = right;
            }

            if (arr[root] < arr[sift]) {
                int tmp = arr[sift];
                arr[sift] = arr[root];
                arr[root] = tmp;
                root = sift;
            } else {
                break;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[] {2, 3, 5, 4, 1, 10, 9};

        HeapSort hs = new HeapSort();
        hs.sort(arr);

        for(int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
