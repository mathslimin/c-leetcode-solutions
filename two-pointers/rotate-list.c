#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listnode.h"

/**

 */
int list_count(struct ListNode* head)
{
    int count = 0;

    while (head) {
        count++;
        head = head->next;
    }

    return count;
}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    struct ListNode root;
    struct ListNode *l1, *l2;

    root.next = head;
    l1 = &root;
    l2 = &root;

    if (head == NULL)
        return NULL;

    k %= list_count(head);
    while (k-- > 0)
        l2 = l2->next;

    while (l2->next) {
        l1 = l1->next;
        l2 = l2->next;
    }

    l2->next = root.next;
    root.next = l1->next;
    l1->next = NULL;

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