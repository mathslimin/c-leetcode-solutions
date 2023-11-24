#include <stdio.h>
#include <stdlib.h>
static int cmpArrayTest1(const void* a, const void* b)
{
    return *(const int*)a - *(const int*)b;
}

int** sortArrayTest1(int* nums, int numsSize, int target, int* returnSize)
{
    int** arr;
    int size = 0;
    int count = 500;
    printf("before sort\n");
    for (int index = 0; index < numsSize; index++) {
        printf("%d\t", nums[index]);
    }
    printf("\n");
    arr = (int**)malloc(sizeof(int*) * count);
    qsort(nums, numsSize, sizeof(int), cmpArrayTest1);

    printf("after sort\n");
    for (int index = 0; index < numsSize; index++) {
        printf("%d\t", nums[index]);
        int* ret = (int*)malloc(sizeof(int) * 2);
        ret[0] = 1;
        ret[2] = nums[index];
        arr[size++] = ret;
    }
    *returnSize = size;
    printf("\n");
    return arr;
}

void test1()
{
    int nums[6] = {1, 0, -1, 0, -2, 2};
    // after sort {-2, -1, 0, 0, 1, 2}
    int numsSize = 6;
    int target = 0;
    int returnSize = 0;

    int** ans = sortArrayTest1(nums, numsSize, target, &returnSize);
    printf("ans:\n");
    for (int index = 0; index < returnSize; index++) {
        printf("%d\t%d\t%d\t%d\n", ans[index][0], ans[index][1], ans[index][2], ans[index][3]);
    }
}

static int cmpSecondArrayDesc(const void* pa, const void* pb)
{
    //按第二列从大到小进行排序
    return (*(int**)pb)[1] - (*(int**)pa)[1];
}

static int cmpSecondArrayAsc(const void* pa, const void* pb)
{
    //按第二列从小到大进行排序
    return (*(int**)pa)[1] - (*(int**)pb)[1];
}

void printSecondArray(int** secondArray, int arraySize, int* colSize)
{
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < colSize[i]; j++) {
            printf("%d ", secondArray[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Func2(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize)
{
    printf("before sort\n");
    printSecondArray(boxTypes, boxTypesSize, boxTypesColSize);
    qsort(boxTypes, boxTypesSize, sizeof(int*), cmpSecondArrayAsc);
    printf("after sort\n");
    printSecondArray(boxTypes, boxTypesSize, boxTypesColSize);
    int res = 0;
    for (int i = 0; i < boxTypesSize; i++) {
        for (int j = 0; j < boxTypes[i][0]; j++) {
            if (truckSize > 0) {
                res += boxTypes[i][1];
                truckSize--;
            }
        }
    }
    return res;
}

void test2()
{
    int numsSize = 3;
    int** nums = (int**)malloc(sizeof(int*) * numsSize);
    nums[0] = (int*)malloc(sizeof(int) * 2);
    nums[0][0] = 1;
    nums[0][1] = 3;
    nums[1] = (int*)malloc(sizeof(int) * 2);
    nums[1][0] = 2;
    nums[1][1] = 2;
    nums[2] = (int*)malloc(sizeof(int) * 2);
    nums[2][0] = 3;
    nums[2][1] = 1;
    int boxTypesColSize[] = {2, 2, 2};
    int truckSize = 4;
    int result = Func2(nums, numsSize, boxTypesColSize, truckSize);
    printf("result:%d\n", result);
}

int getMin(int a, int b)
{
    return a < b ? a : b;
}
int getMax(int a, int b)
{
    return a > b ? a : b;
}
/* 从小到大排列 */
int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

/* 从大到小排列 */
int comb(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

int cmp_twodimension(const void* a, const void* b)
{
    int* a1 = *(int**)a;
    int* b1 = *(int**)b;
    if (a1[0] == b1[0]) {
        return a1[1] - b1[1];
    } else {
        return a1[0] - b1[0];
    }
}

int min_three(int a, int b, int c)
{
    return getMin(a, getMin(b, c));
}

int max_three(int a, int b, int c)
{
    return getMax(a, getMax(b, c));
}

/*
 * 二维数组第一列升序排序
 */
int comp_column_one(const void* a, const void* b)
{
    int* a1 = *(int**)a;
    int* b1 = *(int**)b;

    return a1[0] - b1[0];
}

/*
 * 二维数组第二列升序排序
 */
int comp_column_two(const void* a, const void* b)
{
    int* a1 = *(int**)a;
    int* b1 = *(int**)b;

    return a1[1] - b1[1];
}

int main()
{
    test2();
    return 0;
}