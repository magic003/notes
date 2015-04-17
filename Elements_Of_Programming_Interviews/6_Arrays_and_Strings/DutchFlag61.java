public class DutchFlag61 {
    public void arrange(int[] arr, int t) {
        if (arr == null || arr.length < 2) return;

        swap(arr, t, 0);

        int i = 1, j = arr.length -1 ;
        int eqStart = -1, eqEnd = -1;

        while (i < j) {
            while (i < j && arr[i] <= arr[0]) {
                if (arr[i] == arr[0] && eqStart == -1) {
                    eqStart = i;
                } else if (arr[i] < arr[0] && eqStart != -1) {
                    swap(arr, i, eqStart);
                    eqStart++;
                }
                i++;
            }

            while (i < j && arr[j] >= arr[0]) {
                if (arr[j] == arr[0] && eqEnd == -1) {
                    eqEnd = j;
                } else if (arr[j] > arr[0] && eqEnd != -1) {
                    swap(arr, j, eqEnd);
                    eqEnd--;
                }
                j--;
            }

            if (i < j) {
                swap(arr, i, j);
            }
        }

        if (eqStart == -1) {
            swap(arr, 0, j);
        } else {
            swap(arr, 0, eqStart-1);
        }
    }

    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static void main(String[] args) {
        DutchFlag61 dutchFlag = new DutchFlag61();
        int[] arr = new int[] {5, 4, 6, 7, 0, 7, 10};
        dutchFlag.arrange(arr, 3);

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
