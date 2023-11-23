#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int removeDuplicates(int* nums, int numsSize) {
    int count,i;

    if(numsSize <= 2)
        return numsSize;

    count = 2;
    for(i = 2; i < numsSize; ++i){
        if(nums[i] != nums[count-2])
            nums[count++] = nums[i];
    }

    return count;
}

int main() {
    int nums[] = {1,1,1,2,2,3};
    int numsSize = sizeof(nums) / sizeof(int);
    int newNumsSize = removeDuplicates(nums, numsSize);
    printf("new array: ");
    for (int i = 0; i < newNumsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
