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

#define min_2(x, y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x < _y ? _x : _y; \
})

int maxProduct(int* nums, int numsSize) {
    int cur_min, cur_max;
    int prev_min, prev_max;
    int max_value;
    int i;

    cur_min = nums[0];
    cur_max = nums[0];
    max_value = nums[0];
    for(i = 1; i < numsSize; ++i){
        prev_min = cur_min;
        prev_max = cur_max;
        cur_min = nums[i];
        cur_max = nums[i];

        if(nums[i] > 0){
            cur_max = max_2(cur_max, prev_max * nums[i]);
            cur_min = min_2(cur_min, prev_min * nums[i]);
        }else{
            cur_max = max_2(cur_max, prev_min * nums[i]);
            cur_min = min_2(cur_min, prev_max * nums[i]);
        }

        max_value = max_2(max_value, cur_max);
    }

    return max_value;
}

int main()
{
    int cards[] = {1, 2, 8, 9};
    int cnt = 3;
    int cardsSize = sizeof(cards) / sizeof(int);
    int ret = maxProduct(cards, cnt);
    printf("ret:%d\n", ret);
    return 0;
}