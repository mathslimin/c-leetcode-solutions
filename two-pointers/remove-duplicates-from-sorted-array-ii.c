#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize)
{
    int i, count;

    count = 1;
    for (i = 2; i < numsSize; ++i)
        if (nums[i] != nums[count - 1])
            nums[++count] = nums[i];

    return numsSize < 2 ? numsSize : count + 1;
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