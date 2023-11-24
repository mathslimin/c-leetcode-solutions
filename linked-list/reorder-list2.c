#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* get_mid(struct ListNode* head)
{
    struct ListNode *slow, *fast;
    slow = head;
    fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct ListNode* reverse(struct ListNode* head)
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

struct ListNode* merge(struct ListNode* h1, struct ListNode* h2)
{
    int index = 0;
    struct ListNode root;
    struct ListNode* cur;
    cur = &root;
    while (h1 && h2) {
        if (index % 2 == 0) {
            cur->next = h1;
            h1 = h1->next;
        } else {
            cur->next = h2;
            h2 = h2->next;
        }
        cur = cur->next;
        index++;
    }

    if (h1) {
        cur->next = h1;
    } else {
        cur->next = h2;
    }

    return root.next;
}

void reorderList(struct ListNode* head)
{
    struct ListNode* tail;
    struct ListNode* mid;

    if (head == NULL || head->next == NULL)
        return;

    mid = get_mid(head);
    tail = reverse(mid->next);
    mid->next = NULL;

    merge(head, tail);
}

// 测试代码
int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = NULL;
    reorderList(head);
    struct ListNode* p = head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    return 0;
}