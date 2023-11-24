#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* convertToTitle(int n)
{
    char* ret;
    int i;

    ret = (char*)malloc(sizeof(char) * 26);
    memset(ret, 0, sizeof(char) * 26);
    i = 24;
    while (n) {
        ret[i--] = (n - 1) % 26 + 'A';
        n = (n - 1) / 26;
    }

    return ret + i + 1;
}

int main() {
    int s1 = 700;
    int s2 = 30;
    int s3 = 777;
    printf("%d -> %s", s1, convertToTitle(s1));
    printf("%d -> %s", s2, convertToTitle(s2));
    printf("%d -> %s", s3, convertToTitle(s3));
    return 0;
}