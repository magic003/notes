import java.util.*;

public class Primes511 {
    public List<Integer> primes(int n) {
        int size = (n - 1) >> 1;
        boolean[] isPrime = new boolean[size];

        for (int i = 0; i < size; i++) {
            isPrime[i] = true;
        }

        List<Integer> primes = new ArrayList<Integer>();
        primes.add(2);

        for (int i = 0; i < size; i++) {
            if (isPrime[i]) {
                int p = 2*i + 3;
                primes.add(p);

                for (int j = 2*i*i + 6*i + 3; j < size; j += p) {
                    isPrime[j] = false;
                }
            }
        }

        return primes;
    }

    public static void main(String[] args) {
        Primes511 primes = new Primes511();
        System.out.print("2: ");
        List<Integer> res = primes.primes(2);
        for (Integer p : res) {
            System.out.print(p + " ");
        }
        System.out.println();

        System.out.print("20: ");
        res = primes.primes(20);
        for (Integer p : res) {
            System.out.print(p + " ");
        }
        System.out.println();
    }
}
