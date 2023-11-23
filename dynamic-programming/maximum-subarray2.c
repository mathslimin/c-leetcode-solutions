#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define max_2(x, y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x > _y ? _x : _y; \
})

int maxSubArray(int* nums, int numsSize) {
    int *sum;
    int i,ret;

    sum = (int *)malloc(sizeof(int) * numsSize);
    sum[0] = nums[0];
    for(i = 1; i < numsSize; ++i)
        sum[i] = max_2(nums[i], nums[i] + sum[i-1]);

    ret = INT_MIN;
    for(i = 0; i < numsSize; ++i)
        ret = max_2(sum[i], ret);

    free(sum);
    return ret;
}

int main()
{
    int cards[] = {1, 2, 8, 9};
    int cnt = 3;
    int cardsSize = sizeof(cards) / sizeof(int);
    int ret = maxSubArray(cards, cnt);
    printf("ret:%d\n", ret);
    return 0;
}