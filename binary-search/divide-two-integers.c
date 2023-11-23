#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int divide(int dividend, int divisor) {
    long ldd = labs(dividend);
    long lds = labs(divisor);
    int ret = 0;
    int is_neg = 0;

    if(divisor == -1 && dividend == INT_MIN)
        return INT_MAX;

    if((dividend > 0 && divisor < 0) ||
        (dividend < 0 && divisor > 0))
        is_neg = 1;

    while(ldd >= lds){
        int tmp = 0;
        while(ldd >= (lds << tmp))
            tmp++;
        ldd -= (lds << (tmp - 1));
        ret += (1 << (tmp - 1));
    }

    return is_neg ? -ret : ret;
}

int main() {
    int a = 10;
    int b = 3;
    int c = divide(a, b);
    printf("%d / %d = %d", a, b, c);
    return 0;
}