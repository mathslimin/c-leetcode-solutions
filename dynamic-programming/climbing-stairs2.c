#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int climbStairs(int n) {
    int d1,d2;
    int i,ret;

    d1 = 0;
    d2 = 1;
    ret = 1;
    for(i = 1; i <= n; ++i){
        ret = d1 + d2;
        d1 = d2;
        d2 = ret;
    }

    return ret;
}

int main() {
    printf("%d\n", climbStairs(1)); // 1
    printf("%d\n", climbStairs(2)); // 2
    printf("%d\n", climbStairs(3)); // 3
    printf("%d\n", climbStairs(4)); // 5
    printf("%d\n", climbStairs(5)); // 8
    return 0;
}