#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s)
{
    int start;
    int end, last;

    start = -1;
    end = 0;
    last = strlen(s);

    while (last > 0 && s[last - 1] == ' ')
        --last;

    while (end < last) {
        if (s[end] == ' ')
            start = end;
        end++;
    }

    return end - start - 1;
}

int main() {
    char s1[] = "Hello World";
    char s2[] = "   fly me   to   the moon  ";
    char s3[] = "luffy is still joyboy";
    printf("%d", lengthOfLastWord(s1)); // 5
    printf("%d", lengthOfLastWord(s2)); // 4
    printf("%d", lengthOfLastWord(s3)); // 7
    return 0;
}