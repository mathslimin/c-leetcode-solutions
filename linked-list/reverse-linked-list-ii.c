#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    struct ListNode root;
    struct ListNode* cur;
    struct ListNode* tmp;
    struct ListNode* tail;
    int i = 1;

    root.next = head;
    cur = &root;

    while (i < m) {
        i++;
        cur = cur->next;
    }

    head = cur->next;
    tail = head;
    cur->next = NULL;
    while (i <= n) {
        i++;
        tmp = head->next;
        head->next = cur->next;
        cur->next = head;
        head = tmp;
    }

    tail->next = head;

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

    struct ListNode *newHead = reverseBetween(head, 2, 4);

    while (newHead != NULL) {
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }

    return 0;
}