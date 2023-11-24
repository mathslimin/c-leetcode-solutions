#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* reverseNode(struct ListNode* head)
{
    struct ListNode root;
    root.next = NULL;
    while (head) {
        struct ListNode* tmp = head->next;
        head->next = root.next;
        root.next = head;
        head = tmp;
    }

    return root.next;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode* begin;
    struct ListNode* tail;
    struct ListNode root;
    struct ListNode* prev;
    int i;

    root.next = head;
    prev = &root;
    while (head) {
        i = 1;
        begin = head;
        while (head && i < k) {
            head = head->next;
            i++;
        }

        if (head == NULL)
            goto out;
        tail = head->next;
        head->next = NULL;
        prev->next = reverseNode(begin);
        prev = begin;
        prev->next = tail;
        head = prev->next;
    }

out:
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

    struct ListNode *newHead = reverseKGroup(head, 4);

    while (newHead != NULL) {
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }

    return 0;
}