public class Swap52 {
    public long swapBit(long num, int i, int j) {
        if (i < 0 || i > 63 || j < 0 || j > 63) throw new IllegalArgumentException();

        if (((num >> i) & 1) != ((num >> j) & 1)) {
            return num ^ (1 << i) ^ (1 << j);
        }

        return num;
    }

    public static void main(String[] args) {
        Swap52 swap = new Swap52();
        System.out.println("2: " + swap.swapBit(2L, 0, 1));
        System.out.println("3: " + swap.swapBit(3L, 0, 1));
    }
}
