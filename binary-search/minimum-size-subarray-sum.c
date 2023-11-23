#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int minSubArrayLen(int s, int* nums, int numsSize) {
    int ret = INT_MAX;
    int sum,cur;
    int i;

    sum = 0;
    cur = 0;
    for(i = 0; i < numsSize; ++i){
        cur++;
        sum += nums[i];
        while(sum >= s){
            ret = cur < ret ? cur : ret;
            sum -= nums[i - cur + 1];
            cur--;
        }
    }

    return ret == INT_MAX ? 0 : ret;
}

int main() {
    int s = 7;
    int nums[] = {2, 3, 1, 2, 4, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = minSubArrayLen(s, nums, numsSize);
    printf("%d", res);
    return 0;
}