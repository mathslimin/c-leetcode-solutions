#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int removeElement(int* nums, int numsSize, int val) {
    int count,i;

    count = 0;
    for(i = 0; i < numsSize; ++i){
        if(nums[i] != val)
            nums[count++] = nums[i];
    }

    return count;
}

int main() {
    int nums[] = {3,2,2,3};
    int val = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int newLen = removeElement(nums, numsSize, val);
    printf("New array length: %d", newLen);
    printf("New array: ");
    for (int i = 0; i < newLen; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
