#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int mySqrt(int x) {
    long start,end,mid;

    start = 0;
    end = x;

    while(start <= end){
        mid = (start + end) / 2;
        if(mid * mid <= x && (mid + 1) * (mid+1) > x)
            break;
        else if(mid * mid > x)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return mid;
}

int main() {
    int x = 10;
    int result = mySqrt(x);
    printf("%d", result);
    return 0;
}