#include <stdio.h>
#include <stdlib.h>

// get greatest common divisor
int gcd(int a, int b)
{
    static int r;
    r = b;

    // recursion
    return a % b == 0 ? r : gcd(b, a % b);
}

// implement Euclidean algorithm2
int Euclidean_Algorithm_2(int a, int b)
{
    return a % b ? gcd(a, b) : 0;
}

// compute multiplicative inverse
int multiplicative_inverse(int a, int n)
{
    for (int x = 1; ; x++)
        if (a * x % n == 1) {
            printf("\ta * x ≡ 1 (mod n)\n");
            printf("\t%d * %d ≡ 1 (mod %d)\n", a, x, n);
            return x;
        }
}

int main(int argc, char *argv[])
{
    // check input
    if (argc != 3) {
        fprintf(stderr, "error! invalid input\n");
        return -1;
    }

    int inputs[2];
    for (int i = 1; i < 3; i++) {
        if (!sscanf(argv[i], "%d", &inputs[i - 1])) {
            fprintf(stderr, "error! invalid input... -> %s\n", argv[i]);
            return -1;
        }
    }

    // input validation
    int gcd = Euclidean_Algorithm_2(inputs[0], inputs[1]);

    if (gcd != 1) {
        fprintf(stderr, "error! input value can not satisfy the homework 1-1, gcd(a, n) = 1\n");
        return -1;
    }

    // result
    printf("the answer for homework 1-1, 1-2 is ...\n");
    printf("\tgcd(%d, %d) = %d (coprime)\n\n", inputs[0], inputs[1], gcd);

    multiplicative_inverse(inputs[0], inputs[1]);

	return 0;
}