#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n <= 1) return 0;

    double t = n * 1.0;
    double x = sqrt(t);
    int i;
    for (i=2; i <= x; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char* argv[]) {
    int i;
    for (i=1; i<30; i++) {
        printf("Is %d prime? %d\n", i, isPrime(i));
    }

    return 0;
}
