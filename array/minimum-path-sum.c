#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int **arr;
    int ret;
    int i,j;

    arr = (int **)malloc(sizeof(int *) * gridRowSize);
    for(i = 0; i < gridRowSize; ++i)
        arr[i] = (int *)malloc(sizeof(int) * gridColSize);

    for(i = 0; i < gridRowSize; ++i){
        for(j = 0; j < gridColSize; ++j){
            arr[i][j] = grid[i][j];
            if(i - 1 >= 0 && j - 1 < 0)
                arr[i][j] += arr[i-1][j];
            else if(j - 1 >= 0 && i - 1 < 0)
                arr[i][j] += arr[i][j-1];
            else if(i - 1 >= 0 && j - 1 >= 0)
                arr[i][j] += arr[i-1][j] < arr[i][j-1] ?
                        arr[i-1][j] : arr[i][j-1];
        }
    }

    ret = arr[gridRowSize-1][gridColSize-1];

    for(i = 0; i < gridRowSize; ++i)
        free(arr[i]);
    free(arr);

    return ret;
}

int main() {
    int grid[3][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int* gridPtr[3] = {grid[0], grid[1], grid[2]};
    int gridColSize[3] = {3, 3, 3};
    int result = minPathSum(gridPtr, 3, gridColSize);
    printf("The minimum path sum is %d", result);
    return 0;
}
