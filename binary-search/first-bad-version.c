#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
    return true;
}

int firstBadVersion(int n)
{
    int start, end, mid;
    start = 1;
    end = n;

    while (start < end) {
        mid = start + (end - start) / 2;
        if (isBadVersion(mid)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    return end;
}

int main()
{
    printf("firstBadVersion\n", firstBadVersion(10));
    return 0;
}