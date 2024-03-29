#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int numSquares(int n)
{
    int* arr;
    int i, j;
    int min, ret;

    arr = (int*)malloc(sizeof(int) * (n + 1));
    arr[0] = 0;
    arr[1] = 1;

    for (i = 2; i <= n; ++i) {
        min = i;
        j = 1;
        while (j * j <= i) {
            min = arr[i - j * j] + 1 < min ? arr[i - j * j] + 1 : min;
            j++;
        }
        arr[i] = min;
    }

    ret = arr[n];
    free(arr);
    return ret;
}

int main() {
    int n = 12;
    int res = numSquares(n);
    printf("%d", res); // expected output: 3
    return 0;
}