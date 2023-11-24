#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* glist;
bool helper(struct ListNode* head)
{
    if (head == NULL)
        return true;
    if (!helper(head->next))
        return false;
    if (head->val != glist->val)
        return false;

    glist = glist->next;
    return true;
}

bool isPalindrome(struct ListNode* head)
{
    glist = head;
    return helper(head);
}

int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 2;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 1;
    head->next->next->next->next = NULL;
    printf("%d", isPalindrome(head)); // 输出 1
    return 0;
}