public class Multiple513 {
    public int multiple(int x, int y) {
        int sum = 0;
        int scaledX = x;

        while (y > 0) {
            if ((y & 1) != 0) {
                sum = add(sum, scaledX);
            }

            y >>= 1;
            scaledX <<= 1;
        }

        return sum;
    }

    private int add(int x, int y) {
        int sum = 0;
        int k = 1;
        int carry = 0;
        
        while (k > 0) {
            int xk = x & k;
            int yk = y & k;
            int nextCarry = (xk & yk) > 0 || (xk & carry) > 0 || (yk & carry) > 0 ? 1 : 0;
            sum = sum ^ xk ^ yk ^ carry;
            carry = nextCarry << 1;
            k <<= 1;
        }

        return sum;
    }

    public static void main(String[] args) {
        Multiple513 multiple = new Multiple513();
        System.out.println("3*4 = " + multiple.multiple(3,4));
        System.out.println("0*4 = " + multiple.multiple(0,4));
        System.out.println("3*0 = " + multiple.multiple(3,0));
    }
}
