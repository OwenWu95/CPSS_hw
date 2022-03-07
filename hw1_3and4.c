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
    for (int x = 1; ; x++) if (a * x % n == 1) return x;
}


#define SECRET 3200
#define N 3

int main(int argc, char *argv[])
{
    // parameter validation
    int mi[N] = {11, 13, 29};

    for (int i = 1; i < N; i++)
        if (Euclidean_Algorithm_2(mi[i], mi[i - 1]) == 0) {
            fprintf(stderr, "error! sequence gcd != 1\n");
            return 0;
        }

    // compute SECRET shares
    printf("the answer for homework 1-3 is ...\n");
    printf("\t# set SECRET = %d\n", SECRET);
    int si[N];
    for (int i = 0; i < N; i++) {
        si[i] = SECRET % mi[i];
        printf("\tm%d = %d, share%d = %d\n", i, mi[i], i, si[i]);
    }

    // compute SECRET
    printf("\nthe answer for homework 1-4 is ...\n");
    printf("\t# x ≡ ai (mod mi)\n");
    int M = 1;
    for (int i = 0; i < N; i++) {
        M *= mi[i];
        printf("\tx ≡ %d (mod %d)\n", si[i], mi[i]);
    }

    printf("\n\t# M = m1 * m2 * m3 ... * mn\n");
    printf("\tM = %d\n\n", M);

    printf("\t# Mi = M / mi, ti * Mi ≡ 1 (mod mi)\n");
    int Mi[N];
    int ti[N];
    for (int i = 0; i < N; i++) {
        Mi[i] = M / mi[i];
        ti[i] = multiplicative_inverse(Mi[i], mi[i]);
        printf("\tM%d = %d, t%d = %d\n", i, Mi[i], i, ti[i]);
    }

    printf("\n\t# x = (Sigma i = 1 to n do ai * ti * Mi) mod M\n");
    int res = 0;
    for (int i = 0; i < N; i++) res += si[i] * ti[i] * Mi[i];

    // result
    // printf("res=%d\n", res);
    printf("\tSECRET = %d\n", res % M);

	return 0;
}