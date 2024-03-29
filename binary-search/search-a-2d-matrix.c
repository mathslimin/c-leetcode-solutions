#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int start,end,mid;
    int tmp;

    start = 0;
    end = matrixRowSize * matrixColSize - 1;
    while(start <= end){
        mid = (start + end) / 2;
        tmp= matrix[mid / matrixColSize][mid % matrixColSize];
        if(tmp == target)
            return true;
        else if(tmp > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return false;
}

int main() {
    int matrix[3][4] = {{1, 3, 5, 7},
                        {10, 11, 16, 20},
                        {23, 30, 34, 50}};
    int* ptr[3] = {matrix[0], matrix[1], matrix[2]};
    int matrixRowSize = 3;
    int matrixColSize = 4;
    int target = 3;
    bool result = searchMatrix(ptr, matrixRowSize, matrixColSize, target);
    printf("%d\n", result);
    return 0;
}