public class BigInteger69 {
    public String multiple(String s1, String s2) {
        if (s1 == null || s2 == null || s1.length() == 0 || s2.length() == 0) throw new IllegalArgumentException();

        boolean isNeg = false;
        if (s1.charAt(0) == '-') {
            isNeg = !isNeg;
            s1 = s1.substring(1);
        }
        if (s2.charAt(0) == '-') {
            isNeg = !isNeg;
            s2 = s2.substring(1);
        }

        if (s1.equals("0") || s2.equals("0")) {
            return "0";
        }

        int len1 = s1.length();
        int len2 = s2.length();
        int[] result = new int[len1+len2];

        int currPos = len1 + len2 - 1;
        for (int i = len2-1; i >= 0; i--) {
            currPos = len1+i;
            int carry = 0;
            int digit2 = getDigit(s2, i);
            for (int j = len1-1; j >= 0; j--) {
                int v = getDigit(s1, j) * digit2 + result[currPos] + carry;
                result[currPos] = v % 10;
                carry = v / 10;
                currPos--;
            }

            if (carry > 0) {
                result[currPos] = carry;
                currPos--;
            }
        }

        StringBuilder sb = new StringBuilder();
        if (isNeg) {
            sb.append('-');
        }
        for (int i = currPos+1; i < result.length; i++) {
            sb.append(result[i]);
        }
        return sb.toString();
    }

    private int getDigit(String s, int i) {
        char ch = s.charAt(i);
        if (ch >= '0' && ch <= '9') {
            return ch - '0';
        }
        
        throw new IllegalArgumentException();
    }

    public static void main(String[] args) {
        BigInteger69 bigInteger = new BigInteger69();
        System.out.println("99 * 99 = " + bigInteger.multiple("99", "99"));
        System.out.println("-99 * 99 = " + bigInteger.multiple("-99", "99"));
        System.out.println("-99 * -99 = " + bigInteger.multiple("-99", "-99"));
        System.out.println("123 * 45 = " + bigInteger.multiple("123", "45"));
        System.out.println("0 * 10 = " + bigInteger.multiple("0", "10"));
        System.out.println("10 * 0 = " + bigInteger.multiple("10", "0"));
    }
}
