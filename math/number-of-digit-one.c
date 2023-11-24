#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int countDigitOne(int n)
{
    int ret = 0;
    long m;

    for (m = 1; m <= n; m *= 10) {
        long a = n / m;
        long b = n % m;
        ret += (a + 8) / 10 * m;
        if (a % 10 == 1)
            ret += (b + 1);
    }

    return ret;
}

int main() {
    int n1 = 13;
    int n2 = 0;
    int res1 = countDigitOne(n1);
    int res2 = countDigitOne(n2);
    printf("res1 = %d", res1); // 6
    printf("res2 = %d", res2); // 0
    return 0;
}