#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int maxSubArray(int* nums, int numsSize) {
    int i;
    int ret = nums[0];
    int cur = 0;

    for(i = 0; i < numsSize; ++i){
        cur += nums[i];
        ret = cur > ret ? cur : ret;
        cur = cur > 0 ? cur : 0;
    }

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
