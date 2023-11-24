#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
int get_length(struct ListNode* head)
{
    int ret = 0;
    while (head) {
        ret++;
        head = head->next;
    }

    return ret;
}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    int len;
    int i;
    struct ListNode root;
    struct ListNode* prev;

    if (head == NULL)
        return NULL;

    root.next = head;
    prev = root.next;

    len = get_length(head);
    k %= len;

    for (i = 0; i < k; ++i)
        head = head->next;

    while (head->next) {
        head = head->next;
        prev = prev->next;
    }

    head->next = root.next;
    root.next = prev->next;
    prev->next = NULL;

    return root.next;
}

int main() {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    int k = 2;
    struct ListNode *newHead = rotateRight(head, k);

    while (newHead != NULL) {
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }
    printf("\n");

    return 0;
}