#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    struct ListNode root;
    struct ListNode* prev;
    struct ListNode* tail;
    int i;
    int count;

    if (head == NULL)
        return NULL;

    root.next = head;
    prev = &root;

    count = 0;
    while (head) {
        tail = head;
        head = head->next;
        count++;
    }
    head = root.next;
    k %= count;

    for (i = 0; i < count - k; ++i) {
        prev = prev->next;
    }

    tail->next = root.next;
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