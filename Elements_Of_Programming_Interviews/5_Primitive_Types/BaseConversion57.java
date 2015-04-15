public class BaseConversion57 {
    public String convert(String s, int b1, int b2) {
        if (s == null || s.length() == 0 || b1 < 2 || b1 > 16 || b2 < 2 || b2 > 16) {
            throw new IllegalArgumentException();
        }

        boolean isNeg = false;
        if (s.charAt(0) == '-') {
            isNeg = true;
            s = s.substring(1);
        }

        int num = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            num *= b1;
            num += charToInt(s.charAt(i));
        }

        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            sb.insert(0, intToChar(num % b2));
            num /= b2;
        }

        if (isNeg) {
            sb.insert(0, '-');
        }

        return sb.toString();

    }

    private int charToInt(char ch) {
        if (ch >= '0' && ch <= '9') {
            return ch - '0';
        }

        return 10 + ch - 'A';
    }

    private char intToChar(int i) {
        if (i >= 0 && i <= 9) {
            return (char)('0' + i);
        }

        return (char)('A' + (i - 10));
    }

    public static void main(String[] args) {
        BaseConversion57 conversion = new BaseConversion57();
        System.out.println("110: " + conversion.convert("110", 2, 10));
        System.out.println("8: " + conversion.convert("8", 10, 2));
        System.out.println("5: " + conversion.convert("5", 10, 10));
        System.out.println("-110: " + conversion.convert("-110", 2, 10));
    }
}
