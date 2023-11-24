#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countPrimes(int n)
{
    int ret = 0;
    int i, j;
    int* prime;
    prime = (int*)malloc(sizeof(int) * n);
    memset(prime, 0, sizeof(int) * n);

    for (i = 2; i < n; ++i) {
        if (prime[i])
            continue;
        ret++;
        for (j = 2 * i; j < n; j += i)
            prime[j] = 1;
    }

    free(prime);
    return ret;
}

int main() {
    int n = 10;
    int count = countPrimes(n);
    printf("%d", count); // 输出4
    return 0;
}
