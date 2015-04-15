public class Gcd510 {
    public int gcd(int x, int y) {
        if (x == 0) {
            return y;
        } else if (y == 0) {
            return x;
        } else if (isEven(x) && isEven(y)) {
            return gcd(x >> 1, y >> 1) << 1;
        } else if (isEven(x) && !isEven(y)) {
            return gcd(x >> 1, y);
        } else if (!isEven(x) && isEven(y)) {
            return gcd(x, y >> 1);
        } else if ( x <= y) {
            return gcd(x, y-x);
        } else {
            return gcd(y, x-y);
        }
    }

    private boolean isEven(int x) {
        return (x & 1 ) == 0;
    }

    public static void main(String[] args) {
        Gcd510 gcd = new Gcd510();
        System.out.println("0,2: " + gcd.gcd(0,2));
        System.out.println("5,0: " + gcd.gcd(5,0));
        System.out.println("4,2: " + gcd.gcd(4,2));
        System.out.println("12,9: " + gcd.gcd(12,9));
        System.out.println("9,12: " + gcd.gcd(9,12));
        System.out.println("9,15: " + gcd.gcd(9,15));
        System.out.println("15,9: " + gcd.gcd(15,9));
    }
}
