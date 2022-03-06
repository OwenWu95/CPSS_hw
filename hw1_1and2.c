#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    static int r;
    r = b;

    return a % b == 0 ? r : gcd(b, a % b);
}

int Euclidean_Algorithm_2(int a, int b)
{
    return a % b ? gcd(a, b) : 0;
}

int get_x_by_ax_mod_n_eq_1(int a, int n)
{
    for (int x = 1; ; x++) {
        if (a * x % n == 1) {
            printf("\ta * x ≡ 1 (mod n)\n");
            printf("\t%d * %d ≡ 1 (mod %d)\n", a, x, n);
            return x;
        }
    }
}
int main(int argc, char *argv[])
{
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

    int gcd = Euclidean_Algorithm_2(inputs[0], inputs[1]);

    if (gcd != 1) {
        fprintf(stderr, "error! input value can not satisfy the homework 1-1, gcd(a, n) = 1\n");
        return -1;
    }

    printf("the answer for homework 1-1, 1-2 is ...\n");
    printf("\tgcd(%d, %d) = %d (coprime)\n\n", inputs[0], inputs[1], gcd);
    get_x_by_ax_mod_n_eq_1(inputs[0], inputs[1]);
    
	return 0;
}