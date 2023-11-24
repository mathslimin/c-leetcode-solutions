#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int titleToNumber(char* s)
{
    int ret = 0;
    while (*s) {
        ret = ret * 26 + (*s - 'A' + 1);
        s++;
    }
    return ret;
}

int main() {
    char* s1 = "A";
    char* s2 = "AB";
    char* s3 = "ZY";
    printf("%s -> %d", s1, titleToNumber(s1));
    printf("%s -> %d", s2, titleToNumber(s2));
    printf("%s -> %d", s3, titleToNumber(s3));
    return 0;
}