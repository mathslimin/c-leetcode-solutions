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
    struct ListNode* cur;
    cur = &root;

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

struct ListNode* split(struct ListNode** lists, int start, int end)
{
    if (end < start)
        return NULL;
    if (start == end)
        return lists[start];
    int mid = (start + end) / 2;
    struct ListNode* left = split(lists, start, mid);
    struct ListNode* right = split(lists, mid + 1, end);

    return merge(left, right);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    return split(lists, 0, listsSize - 1);
}

int main() {
    struct ListNode* l1 = createList(1, 4, 5);
    struct ListNode* l2 = createList(1, 3, 4);
    struct ListNode* l3 = createList(2, 6);
    struct ListNode* lists[] = {l1, l2, l3};
    int listsSize = sizeof(lists) / sizeof(lists[0]);
    struct ListNode* merged = mergeKLists(lists, listsSize);
    printList(merged);
    return 0;
}