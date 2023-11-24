#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_equal(int a, int b)
{
    if (a >= 'A' && a <= 'Z')
        a = a - 'A' + 'a';
    if (b >= 'A' && b <= 'Z')
        b = b - 'A' + 'a';
    return a == b;
}

bool isPalindrome(char* s)
{
    int start, end;

    start = 0;
    end = strlen(s) - 1;
    while (start < end) {
        if (!isalpha(s[start]) && !isdigit(s[start])) {
            start++;
            continue;
        }
        if (!isalpha(s[end]) && !isdigit(s[end])) {
            --end;
            continue;
        }
        if (!is_equal(s[start], s[end]))
            return false;
        ++start;
        --end;
    }

    return true;
}

int main() {
    char s1[] = "A man, a plan, a canal: Panama";
    char s2[] = "race a car";
    printf("%s is %s\n", s1, isPalindrome(s1) ? "a palindrome" : "not a palindrome");
    printf("%s is %s\n", s2, isPalindrome(s2) ? "a palindrome" : "not a palindrome");
    return 0;
}