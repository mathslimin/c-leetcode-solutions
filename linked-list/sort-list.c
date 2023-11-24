#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* merge(struct ListNode* left, struct ListNode* right)
{
    struct ListNode root;
    struct ListNode* cur = &root;
    while (left && right) {
        if (left->val < right->val) {
            cur->next = left;
            left = left->next;
        } else {
            cur->next = right;
            right = right->next;
        }
        cur = cur->next;
    }
    cur->next = left ? left : right;
    return root.next;
}

struct ListNode* split(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    struct ListNode* right = split(slow->next);
    slow->next = NULL;
    struct ListNode* left = split(head);

    return merge(left, right);
}

struct ListNode* sortList(struct ListNode* head)
{
    return split(head);
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

    struct ListNode *newHead = sortList(head);

    while (newHead != NULL) {
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }
    printf("\n");

    return 0;
}