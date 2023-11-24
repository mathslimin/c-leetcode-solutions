#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode root;
    struct ListNode* cur;

    root.next = head;
    cur = &root;
    while (head && head->next) {
        struct ListNode* tmp = head->next->next;

        cur->next = head->next;
        head->next->next = head;
        head->next = tmp;

        cur = head;
        head = head->next;
    }

    return root.next;
}

int main() {
    // 构造链表
    struct ListNode n1 = {1, NULL};
    struct ListNode n2 = {2, NULL};
    struct ListNode n3 = {3, NULL};
    struct ListNode n4 = {4, NULL};
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    // 测试swapPairs函数
    struct ListNode *newHead = swapPairs(&n1);
    while (newHead != NULL) {
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }
    printf("\n");

    return 0;
}