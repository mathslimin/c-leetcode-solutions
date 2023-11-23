#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int top;
int *data;
int **ret;
int count;
int alloc_size;
int *col;

int *get_array(int *arr, int size)
{
    int *tmp = (int *)malloc(sizeof(int) * size);
    memcpy(tmp,arr,sizeof(int) * size);
    return tmp;
}

void helper(int *candidates, int candidatesSize, int index, int diff)
{
    if(diff == 0){
        col[count] = top;
        ret[count++] = get_array(data,top);
        if(count == alloc_size){
            alloc_size <<= 1;
            ret = realloc(ret,sizeof(int *) * alloc_size);
            col = realloc(col,sizeof(int) * alloc_size);
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
        helper(candidates,candidatesSize,i,diff - candidates[i]);
        top--;
    }
}

static int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int** combinationSum(int* candidates, int candidatesSize,
        int target, int** columnSizes, int* returnSize)
{
    top = 0;
    count = 0;
    alloc_size = 500;

    ret = (int **)malloc(sizeof(int *) * alloc_size);
    col = (int *)malloc(sizeof(int) * alloc_size);
    data = (int *)malloc(sizeof(int) * target);

    qsort(candidates,candidatesSize,sizeof(int),cmp);
    helper(candidates,candidatesSize,0,target);

    *columnSizes = col;
    *returnSize = count;

    return ret;
}

int main() {
    int candidates[] = {2, 3, 6, 7};
    int candidatesSize = 4;
    int target = 7;
    int** columnSizes;
    int returnSize;
    int** result = combinationSum(candidates, candidatesSize, target, columnSizes, &returnSize);

    // 输出结果
    printf("Result:");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < (*columnSizes)[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(*columnSizes);

    return 0;
}
