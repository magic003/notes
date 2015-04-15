public class ClosestWeight54 {
    public long closest(long num) {
        for (int i = 0; i < 63; i++) {
            if ((((num >> i) & 1) ^ ((num >> i+1) & 1)) == 1) {
                return num ^ (1 << i) ^ (1 << i+1);
            }
        }

        throw new IllegalArgumentException();
    }

    public static void main(String[] args) {
        ClosestWeight54 weight = new ClosestWeight54();
        System.out.println("7: " + weight.closest(7L));
        System.out.println("6: " + weight.closest(6L));
    }
}
