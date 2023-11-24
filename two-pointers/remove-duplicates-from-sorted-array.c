#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize)
{
    int i, count = 0;

    if (numsSize == 0)
        return 0;

    for (i = 0; i < numsSize; ++i)
        if (nums[i] != nums[count])
            nums[++count] = nums[i];

    return count + 1;
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