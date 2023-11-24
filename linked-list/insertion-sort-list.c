#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**
 */
struct ListNode* insertionSortList(struct ListNode* head)
{
    struct ListNode root;
    struct ListNode* cur;
    struct ListNode* tmp;

    root.next = NULL;
    while (head) {
        cur = &root;
        while (cur->next && cur->next->val < head->val)
            cur = cur->next;

        tmp = head->next;
        head->next = cur->next;
        cur->next = head;
        head = tmp;
    }

    return root.next;
}

int main() {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 4;
    head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->val = 1;
    head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 3;
    head->next->next->next->next = NULL;
    printf("Before sorting: ");
    printList(head);
    head = insertionSortList(head);
    printf("After sorting: ");
    printList(head);
    return 0;
}