#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int i,j;

    for(i = 0; i < numsSize; ++i){
        for(j = i+1; j <= i+k && j < numsSize; ++j)
            if(nums[j] == nums[i])
                return true;
    }

    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1, 2, 3};
    int numsSize = 6;
    int k = 2;
    bool result = containsNearbyDuplicate(nums, numsSize, k);
    if (result) {
        printf("The array contains nearby duplicates within %d indices.", k);
    } else {
        printf("The array does not contain nearby duplicates within %d indices.", k);
    }
    return 0;
}
