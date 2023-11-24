#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    int is_neg = 0;
    if (n < 0) {
        n = -n;
        is_neg = 1;
    }

    double df = myPow(x, n / 2);
    df *= df;
    if (n % 2 == 1)
        df *= x;

    return is_neg ? 1 / df : df;
}

int main() {
    double x = 2.0;
    int n = 10;
    double result = myPow(x, n);
    printf("%lf", result);
    return 0;
}