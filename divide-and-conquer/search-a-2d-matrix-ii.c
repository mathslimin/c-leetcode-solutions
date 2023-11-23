#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row,col;

    row = matrixRowSize - 1;
    col = 0;

    while(row >= 0 && col < matrixColSize){
        if(matrix[row][col] == target)
            return true;
        if(matrix[row][col] > target)
            --row;
        else
            ++col;
    }

    return false;
}

int main() {
    int nums[3][4] = {{1, 3, 5, 7},
                        {10, 11, 16, 20},
                        {23, 30, 34, 50}};
    int *matrix[3] = {nums[0], nums[1], nums[2]};            
    int target = 3;
    bool result = searchMatrix(matrix, 3, 4, target);
    printf("%d", result);
    return 0;
}