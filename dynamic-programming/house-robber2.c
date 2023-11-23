#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int rob(int* nums, int numsSize) {
    int value,pre_value,tmp;
    int i;

    pre_value = 0;
    value = 0;

    for(i = 0; i < numsSize; ++i){
        tmp = value;
        value = pre_value + nums[i] > value ? pre_value + nums[i] : value;
        pre_value = tmp;
    }

    return value;
}

int main(){
    int nums[] = {1,2,3,1};
    int numsSize = 4;
    int result = rob(nums, numsSize);
    printf("%d", result); // 输出 4
    return 0;
}
