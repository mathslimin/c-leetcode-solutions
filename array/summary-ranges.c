#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char *get_range(int start, int end)
{
    char buf[32];
    if(start == end)
        sprintf(buf,"%d",start);
    else
        sprintf(buf,"%d->%d",start,end);
    return strdup(buf);
}

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char **ret;
    int i,count;
    int start,end;

    count = 0;
    ret = (char **)malloc(sizeof(char *) * numsSize);

    for(i = 0; i < numsSize; ++i){
        start = nums[i];
        while(i < numsSize-1 && nums[i+1] == nums[i]+1)
            i++;
        end = nums[i];
        ret[count++] = get_range(start,end);
    }

    *returnSize = count;
    return ret;
}

int main() {
    int nums[] = {0,1,2,4,5,7};
    int numsSize = 6;
    int returnSize;
    char **result = summaryRanges(nums, numsSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", result[i]);
    }
    return 0;
}