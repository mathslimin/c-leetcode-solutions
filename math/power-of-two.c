#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isPowerOfTwo(int n)
{
    int ret = 0;
    while (n > 0) {
        ret += n & 0x1;
        n >>= 1;
    }

    return ret == 1;
}

int main() {
    int n = 16;
    bool result = isPowerOfTwo(n);
    printf("%d", result);
    return 0;
}