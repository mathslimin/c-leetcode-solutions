#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int countPrimes(int n)
{
    int* arr;
    int count = 0;
    int i, j;

    arr = malloc(sizeof(int) * n);
    memset(arr, 0, sizeof(int) * n);
    for (i = 2; i < n; ++i) {
        if (arr[i])
            continue;
        ++count;
        for (j = i * 2; j < n; j += i)
            arr[j] = 1;
    }

    free(arr);
    return count;
}

int main() {
    int n = 10;
    int count = countPrimes(n);
    printf("%d", count); // 输出4
    return 0;
}
