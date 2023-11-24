#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int reverse(int x)
{
    int rx = 0;
    int ret = 0;
    while (x) {
        ret = rx * 10 + x % 10;
        if (ret / 10 != rx) {
            ret = 0;
            break;
        }
        rx = ret;
        x /= 10;
    }

    return ret;
}

int main() {
    int x = 123;
    printf("%d", reverse(x));

    x = -123;
    printf("%d", reverse(x));

    x = 120;
    printf("%d", reverse(x));

    x = 0;
    printf("%d", reverse(x));

    x = INT_MAX;
    printf("%d", reverse(x));

    x = INT_MIN;
    printf("%d", reverse(x));

    return 0;
}