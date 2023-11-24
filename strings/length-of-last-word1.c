#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s)
{
    int len = strlen(s);
    int pos;

    while (len > 0 && s[len - 1] == ' ')
        --len;

    pos = len - 1;
    while (pos >= 0 && s[pos] != ' ')
        --pos;

    return len - pos - 1;
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