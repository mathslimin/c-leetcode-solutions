#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool canJump(int* nums, int numsSize) {
    int i = 0;
    int max_jump = nums[0];

    while(max_jump < numsSize-1){
        int max = max_jump;
        for(; i <= max_jump; ++i)
            if(i + nums[i] > max)
                max = i + nums[i];
        if(max_jump == max)
            return false;
        max_jump = max;
    }

    return true;
}

int main() {
    int nums[] = {2, 3, 1, 1, 4};
    int numsSize = sizeof(nums) / sizeof(int);
    int steps = canJump(nums, numsSize);
    printf("Minimum number of jumps to reach the end: %d", steps);
    return 0;
}
