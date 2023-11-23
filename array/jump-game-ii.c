#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int jump(int* nums, int numsSize) {
    int ret = 0;
    int i;
    int cur_pos,max_pos;

    cur_pos = 0;
    max_pos = 0;
    for(i = 0; i < numsSize; ++i){
        if(cur_pos < i){
            ret++;
            cur_pos = max_pos;
        }
        if(nums[i] + i > max_pos)
            max_pos = nums[i] + i;
    }

    return ret;
}

int main() {
    int nums[] = {2, 3, 1, 1, 4};
    int numsSize = sizeof(nums) / sizeof(int);
    int steps = jump(nums, numsSize);
    printf("Minimum number of jumps to reach the end: %d", steps);
    return 0;
}
