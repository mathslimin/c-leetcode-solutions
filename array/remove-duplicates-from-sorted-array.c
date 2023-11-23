#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int removeDuplicates(int* nums, int numsSize) {
    int count,i;

    if(numsSize == 0)
        return 0;

    count = 1;
    for(i = 1; i < numsSize; ++i){
        if(nums[i] != nums[count-1])
            nums[count++] = nums[i];
    }

    return count;
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int newLength = removeDuplicates(nums, numsSize);
    printf("New length of array: %d", newLength);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
