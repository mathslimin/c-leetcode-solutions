#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int mySqrt(int x)
{
    long start, end, mid;
    start = 0;
    end = x;
    mid = 0;

    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == x || (mid * mid < x && (mid + 1) * (mid + 1) > x))
            break;
        if (mid * mid < x)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return mid;
}

int main() {
    int x = 10;
    int result = mySqrt(x);
    printf("%d", result);
    return 0;
}