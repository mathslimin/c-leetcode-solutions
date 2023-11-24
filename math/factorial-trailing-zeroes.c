#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int trailingZeroes(int n)
{
    int ret = 0;
    while (n) {
        ret += n / 5;
        n /= 5;
    }

    return ret;
}

int main() {
    int num = 38;
    printf("%d", trailingZeroes(num)); 
    return 0;
}