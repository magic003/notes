public class ReverseWords619 {
    public void reverse(StringBuilder str) {
        if (str == null || str.length() <= 1) return;

        int n = str.length();
        // reverse the characters in each word
        boolean inWord = false;
        int start = 0;
        for (int i = 0; i < n; i++) {
            char ch = str.charAt(i);
            if (!inWord && ch != ' ') {
                inWord = true;
                start = i;
            } else if (inWord && ch == ' ') {
                reverseString(str, start, i-1);
                inWord = false;
            }
        }

        if (inWord) {
            reverseString(str, start, n - 1);
        }

        // reverse the whole string
        reverseString(str, 0, n-1);
    }

    private void reverseString(StringBuilder str, int from, int to) {
        for (int i = from, j = to; i < j; i++,j--) {
            char tmp = str.charAt(i);
            str.setCharAt(i, str.charAt(j));
            str.setCharAt(j, tmp);
        }
    }

    public static void main(String[] args) {
        ReverseWords619 reverse = new ReverseWords619();
        StringBuilder str = new StringBuilder("Alice likes Bob");
        System.out.println(str + " => ");
        reverse.reverse(str);
        System.out.println(str);
    }
}
