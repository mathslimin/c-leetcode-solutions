#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct Interval {
    int start;
    int end;
};

struct Interval* insert(struct Interval* intervals, int intervalsSize,
    struct Interval newInterval, int* returnSize) {
    struct Interval *ret;
    int count = 0;
    int i;

    ret = (struct Interval *)malloc(sizeof(struct Interval) * (intervalsSize + 1));

    for(i = 0; i < intervalsSize; ++i){
        if(intervals[i].end < newInterval.start){
            ret[count].start = intervals[i].start;
            ret[count].end = intervals[i].end;
            count++;
        }else if(intervals[i].start > newInterval.end){
            break;
        }else{
            newInterval.start = intervals[i].start < newInterval.start ?
                intervals[i].start : newInterval.start;
            newInterval.end = intervals[i].end > newInterval.end ?
                intervals[i].end : newInterval.end;
        }
    }

    ret[count].start = newInterval.start;
    ret[count].end = newInterval.end;
    count++;

    for(; i < intervalsSize; ++i){
        ret[count].start = intervals[i].start;
        ret[count].end = intervals[i].end;
        count++;
    }

    *returnSize = count;
    return ret;
}

int main()
{
    // 测试样例
    struct Interval intervals[4] = {{1, 2}, {3, 5}, {6, 7}, {8, 10}};
    int intervalsSize = 4;
    struct Interval newInterval = {4, 6};
    int returnSize;
    struct Interval* result = insert(intervals, intervalsSize, newInterval, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
    printf("\n");
    free(result);
    return 0;
}
