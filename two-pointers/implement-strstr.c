#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle)
{
    int step[256];
    int i, j;
    int nd_len = strlen(needle);
    int ht_len = strlen(haystack);

    for (i = 0; i < ht_len; ++i)
        step[haystack[i]] = nd_len + 1;

    for (i = 0; i < nd_len; ++i)
        step[needle[i]] = nd_len - i;

    for (i = 0; i <= ht_len - nd_len; i += step[haystack[i + nd_len]]) {
        j = 0;
        while (j < nd_len && haystack[j + i] == needle[j])
            ++j;
        if (j == nd_len)
            return i;
    }

    return -1;
}

int main() {
    char haystack[] = "hello world";
    char needle[] = "world";
    int index = strStr(haystack, needle);
    printf("%d", index);
    return 0;
}