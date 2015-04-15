public class Parity51 {
    public boolean parity(long num) {

        boolean result = false;
        while (num != 0) {
            result = !result;
            num &= (num-1);
        }

        return result;
    }

    public static void main(String[] args) {
        Parity51 parity = new Parity51();
        System.out.println("0: " + parity.parity(0L));
        System.out.println("1: " + parity.parity(1L));
        System.out.println("2: " + parity.parity(2L));
        System.out.println("6: " + parity.parity(6L));
        System.out.println("7: " + parity.parity(7L));
    }
}
