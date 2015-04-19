public class Spiral615 {
    public int[] order(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length != matrix.length) {
            throw new IllegalArgumentException();
        }

        int n = matrix.length;
        int round = (matrix.length+1) / 2;
        int[] res = new int[n*n];
        int index = 0;
        for (int i = 0; i < round; i++) {
            // get top row
            for (int j = i; j < n - i; j++) {
                res[index++] = matrix[i][j];
            }

            // get right column
            for (int j = i+1; j < n - i; j++) {
                res[index++] = matrix[j][n-1-i];
            }

            // get bottom row
            for (int j = n - 1 - i - 1; j >= i; j--) {
                res[index++] = matrix[n - 1 - i][j];
            }

            // get left colum
            for (int j = n - 1 - i - 1; j > i; j--) {
                res[index++] = matrix[j][i];
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Spiral615 spiral = new Spiral615();
        int[][] matrix = new int[][] {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
        int[] res = spiral.order(matrix);
        for (int i = 0; i < res.length; i++) {
            System.out.print(res[i] + " ");
        }
        System.out.println();

        matrix = new int[][] {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
        res = spiral.order(matrix);
        for (int i = 0; i < res.length; i++) {
            System.out.print(res[i] + " ");
        }
        System.out.println();
    }
}
