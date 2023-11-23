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
    int max_sum, cur_sum;
    int i;

    max_sum = nums[0];
    cur_sum = 0;
    for(i = 0; i < numsSize; ++i){
        cur_sum += nums[i];
        max_sum = max_2(cur_sum, max_sum);
        cur_sum = max_2(0, cur_sum);
    }

    return max_sum;
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