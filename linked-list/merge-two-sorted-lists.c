#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode root;
    struct ListNode* cur = &root;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    cur->next = l1 ? l1 : l2;

    return root.next;
}

int main() {
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 2;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 4;
    l1->next->next->next = NULL;

    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 1;
    l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 3;
    l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    struct ListNode* result = mergeTwoLists(l1, l2);

    while (result) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");

    return 0;
}