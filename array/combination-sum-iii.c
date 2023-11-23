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

void helper(int index, int k, int diff)
{
    if(top == k && diff == 0){
        col[count] = top;
        ret[count++] = get_array(data,top);
        if(count == alloc_size){
            alloc_size <<= 1;
            col = realloc(col,sizeof(int) * alloc_size);
            ret = realloc(ret,sizeof(int *) * alloc_size);
        }
        return ;
    }
    if(top == k || diff == 0)
        return ;

    int i;
    for(i = index; i <= 9; ++i){
        if(i > diff)
            break;
        data[top++] = i;
        helper(i+1,k,diff - i);
        top--;
    }
}

int** combinationSum3(int k, int n, int** columnSizes, int* returnSize) {
    top = 0;
    count= 0;
    alloc_size = 500;

    ret = (int **)malloc(sizeof(int *) * alloc_size);
    col = (int *)malloc(sizeof(int *) * alloc_size);
    data = (int *)malloc(sizeof(int *) * 9);

    helper(1,k,n);

    *columnSizes = col;
    *returnSize = count;
    return ret;
}

int main() {
    int k = 3, n = 7;
    int* columnSizes = (int*)malloc(sizeof(int) * 1000);
    int returnSize = 0;
    int** res = combinationSum3(k, n, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
