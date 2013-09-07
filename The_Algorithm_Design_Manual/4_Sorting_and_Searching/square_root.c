#include <stdio.h>

double squareRoot(int num) {   
    double l = 1;
    double r = num;

    while (1) {       
        double middle = (l + r) / 2.0;
        double diff = (middle*middle) - num;

        if (diff >= 1) {
            r = middle;
        } else if (diff <= -1) {
            l = middle;
        } else {
            return middle;
        }
    }
}

int main(int argc, char* argv[]) {
    int i;
    for(i=1;i<11;i++) {
        printf("Square root of %d: %f\n", i, squareRoot(i));
    }

    return 0;
}

