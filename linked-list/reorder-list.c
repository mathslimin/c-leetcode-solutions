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
    int len, i;
    struct ListNode* cur;
    struct ListNode* tail;
    struct ListNode* tmp;

    if (head == NULL || head->next == NULL)
        return;

    tmp = NULL;
    cur = head;

    len = get_length(head);
    for (i = 0; i < (len + 1) / 2; ++i) {
        tmp = cur;
        cur = cur->next;
    }
    tmp->next = NULL;
    tail = reverse(cur);

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