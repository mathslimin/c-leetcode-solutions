#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isPowerOfTwo(int n)
{
    return n > 0 && ((n & (n - 1)) == 0);
}


int main() {
    int n = 16;
    bool result = isPowerOfTwo(n);
    printf("%d", result);
    return 0;
}