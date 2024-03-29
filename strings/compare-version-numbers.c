#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//这是一个字符串比较的问题，我们可以将字符串按照"."分割成数字，然后依次比较每个数字的大小。

int compareVersion(char* version1, char* version2)
{
    int len1, len2;
    int v1, v2;
    int i, j;

    len1 = strlen(version1);
    len2 = strlen(version2);
    i = j = 0;
    v1 = v2 = 0;
    while (v1 == v2 && (i < len1 || j < len2)) {
        while (version1[i] != '.' && i < len1) {
            v1 = v1 * 10 + version1[i] - '0';
            i++;
        }
        while (version2[j] != '.' && j < len2) {
            v2 = v2 * 10 + version2[j] - '0';
            j++;
        }

        if (v1 != v2)
            break;
        v1 = v2 = 0;
        i++;
        j++;
    }

    return v1 == v2 ? 0 : (v1 > v2 ? 1 : -1);
}


int main() {
    char version1[] = "1.2.3.4";
    char version2[] = "1.2.3.5";
    int result = compareVersion(version1, version2);
    printf("%d", result);
    return 0;
}