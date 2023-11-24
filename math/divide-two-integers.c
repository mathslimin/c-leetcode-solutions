#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long a = labs(dividend);
    long b = labs(divisor);
    bool is_neg = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0));
    int ret = 0;
    while (a >= b) {
        int tmp = 0;
        while (a >= (b << tmp))
            tmp++;
        a -= (b << (tmp - 1));
        ret += (1 << (tmp - 1));
    }

    return is_neg ? -ret : ret;
}

int main() {
    int a = 10;
    int b = 3;
    int c = divide(a, b);
    printf("%d / %d = %d", a, b, c);
    return 0;
}