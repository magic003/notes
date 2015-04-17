public class LongestIncreasing66 {
    private static class Pair {
        private int i;
        private int j;

        public Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }

        public String toString() {
            return "[" + i + ".." + j + "]";
        }
    }

    public Pair longest(int[] arr) {
        if (arr == null || arr.length == 0) throw new IllegalArgumentException();

        int resI = 0;
        int resJ = 0;
        int maxLen = 1;

        int currStart = 0;
        int i = 1;
        while (i < arr.length) {
            if (arr[i] > arr[i-1]) {
                i++;
            } else {
                if ((i-currStart) > maxLen) {
                    maxLen = i - currStart;
                    resI = currStart;
                    resJ = i-1;
                }

                int j;
                for (j = i + maxLen; j < arr.length && j > i; j--) {
                    if (arr[j] <= arr[j-1]) {
                        break;
                    }
                }
                currStart = j;
                i += maxLen + 1;
            }
        }

        if (i - currStart > maxLen) {
            maxLen = i - currStart;
            resI = currStart;
            resJ = i - 1;
        }
        
        return new Pair(resI, resJ);
    }

    public static void main(String[] args) {
        LongestIncreasing66 solution = new LongestIncreasing66();
        int[] arr = new int[] {3, 1, 2, 1, 5, 7, 9, 8 , 10};
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        System.out.println(solution.longest(arr));
    }
}
