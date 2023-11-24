#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    int i = gSize - 1;
    int j = sSize - 1;
    int ret = 0;

    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    while (i >= 0 && j >= 0) {
        if (s[j] >= g[i]) {
            j--;
            ret++;
        }
        i--;
    }

    return ret;
}

int main() {
    int g[] = {1, 2, 3};
    int s[] = {1, 1};
    int ans = findContentChildren(g, sizeof(g) / sizeof(int), s, sizeof(s) / sizeof(int));
    printf("%d", ans); // 输出 1
    return 0;
}