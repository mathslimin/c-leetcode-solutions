#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode root;
    struct ListNode* tmp;
    root.next = NULL;

    while (head) {
        tmp = head->next;
        head->next = root.next;
        root.next = head;
        head = tmp;
    }

    return root.next;
}

int main() {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    struct ListNode *newHead = reverseList(head);

    while (newHead != NULL) {
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }

    return 0;
}