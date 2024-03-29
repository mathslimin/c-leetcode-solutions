#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int top;
int count;
int alloc_size;
int *data;
int **ret;
int *col;

int *get_array(int *src, int len)
{
    int *dst = (int *)malloc(sizeof(int) * len);
    memcpy(dst,src,sizeof(int) * len);
    return dst;
}

void helper(int *candidates, int candidatesSize, int index, int diff)
{
    if(diff == 0){
        col[count] = top;
        ret[count++] = get_array(data,top);
        if(count == alloc_size){
            alloc_size <<= 1;
            col = realloc(col,sizeof(int) * alloc_size);
            ret = realloc(ret,sizeof(int *) * alloc_size);
        }
        return ;
    }

    int i;
    for(i = index; i < candidatesSize; ++i){
        if(candidates[i] > diff)
            break;
        if(i > index && candidates[i] == candidates[i-1])
            continue;
        data[top++] = candidates[i];
        helper(candidates,candidatesSize,i+1,diff - candidates[i]);
        top--;
    }
}

static int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int** combinationSum2(int* candidates, int candidatesSize,
        int target, int** columnSizes, int* returnSize)
{
    top = 0;
    count= 0;
    alloc_size = 500;

    ret = (int **)malloc(sizeof(int *) * alloc_size);
    col = (int *)malloc(sizeof(int *) * alloc_size);
    data = (int *)malloc(sizeof(int *) * target);

    qsort(candidates,candidatesSize,sizeof(int),cmp);

    helper(candidates,candidatesSize,0,target);
    *columnSizes = col;
    *returnSize = count;

    return ret;
}

int main() {
    int candidates[4] = {2, 3, 6, 7};
    int candidatesSize = 4;
    int target = 7;
    int* columnSizes;
    int returnSize;
    int** res = combinationSum2(candidates, candidatesSize, target, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
