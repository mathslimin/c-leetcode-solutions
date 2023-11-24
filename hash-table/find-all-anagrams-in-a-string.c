#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* findAnagrams(char* s, char* p, int* returnSize) {
    int *ret;
    int hp[256] = {0};
    int i;
    int ls, lp;
    int count, index = 0;

    ls = strlen(s);
    lp = strlen(p);
    count = lp;
    ret = malloc(sizeof(int) * ls);

    for(i = 0; i < lp; ++i)
        hp[p[i]]++;

    for(i = 0; i < ls; ++i){
        if(hp[s[i]] > 0)
            count--;
        hp[s[i]]--;
        if(i >= lp){
            if(hp[s[i - lp]] >= 0)
                count++;
            hp[s[i - lp]]++;
        }

        if(count == 0)
            ret[index++] = i - lp + 1;
    }

    *returnSize = index;
    return ret;
}


int main() {
    char s[] = "cbaebabacd";
    char p[] = "abc";
    int returnSize = 0;
    int* result = findAnagrams(s, p, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}