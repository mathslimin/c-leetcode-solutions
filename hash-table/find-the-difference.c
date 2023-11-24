#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char findTheDifference(char* s, char* t)
{
    int hash[256] = {0};
    int len = strlen(s);
    int i;

    for (i = 0; i < len; ++i)
        hash[s[i]]++;

    for (i = 0; i <= len; ++i)
        if (hash[t[i]] == 0)
            break;
        else
            --hash[t[i]];

    return t[i];
}

int main() {
    char s[] = "abcd";
    char t[] = "abcde";
    char result = findTheDifference(s, t);
    printf("%c", result); // 输出e
    return 0;
}