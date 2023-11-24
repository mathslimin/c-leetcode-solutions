#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* get_node(int val)
{
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val = val;
    ret->next = NULL;

    return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode root;
    struct ListNode* cur = &root;
    struct ListNode* l;
    int carry = 0;
    int sum;

    while (l1 && l2) {
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        cur->next = get_node(sum % 10);
        cur = cur->next;

        l1 = l1->next;
        l2 = l2->next;
    }

    l = l1 ? l1 : l2;
    while (l) {
        sum = carry + l->val;
        carry = sum / 10;
        cur->next = get_node(sum % 10);
        cur = cur->next;

        l = l->next;
    }

    if (carry)
        cur->next = get_node(carry);

    return root.next;
}

int main()
{
    struct ListNode* l1 = (struct ListNode*)calloc(3, sizeof(struct ListNode));
    struct ListNode* p1 = l1;
    p1->val = 2;
    p1->next = p1 + 1;
    p1++;

    p1->val = 4;
    p1->next = p1 + 1;
    p1++;

    p1->val = 5;
    p1->next = NULL;

    struct ListNode* l2 = (struct ListNode*)calloc(5, sizeof(struct ListNode));
    struct ListNode* p2 = l2;
    p2->val = 5;
    p2->next = p2 + 1;
    p2++;

    p2->val = 6;
    p2->next = p2 + 1;
    p2++;

    p2->val = 4;
    p2->next = p2 + 1;
    p2++;

    p2->val = 9;
    p2->next = p2 + 1;
    p2++;

    p2->val = 9;
    p2->next = NULL;

    struct ListNode* p = addTwoNumbers(l1, l2);

    /* 542 + 99465 = 100007 */
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
