#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* countBits(int num, int* returnSize) {
    int *dp;
    int cnt;
    int i;
    int tmp;

    dp = (int *)malloc(sizeof(int) * (num + 1));
    for(i = 0; i <= num; ++i){
        cnt = 0;
        tmp = i;
        while(tmp){
            cnt += (tmp & 0x1);
            tmp >>= 1;
        }

        dp[i] = cnt;
    }

    *returnSize = num + 1;
    return dp;
}

int main() {
    int num = 5;
    int size;
    int *bits = countBits(num, &size);
    printf("Input: %dOutput: [", num);
    for (int i = 0; i < size; i++) {
        printf("%d", bits[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]");
    free(bits); // 释放数组空间
    return 0;
}