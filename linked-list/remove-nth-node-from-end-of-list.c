#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if (n == 0)
        return head;

    struct ListNode *fast, *slow;
    fast = slow = head;

    while (n--) {
        fast = fast->next;
    }

    if (fast == NULL) { /* reach the tail, so we delete the head */
        head = head->next;
        return head;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    /* slow pointer is at the previous node of the one to be deleted */
    slow->next = slow->next->next;

    return head;
}

int main() {
    // 创建链表 1->2->3->4->5
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    struct ListNode node4 = {4, NULL};
    struct ListNode node5 = {5, NULL};
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    // 打印原链表
    struct ListNode *p = &node1;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    // 删除倒数第2个节点
    struct ListNode *newHead = removeNthFromEnd(&node1, 2);

    // 打印新链表
    p = newHead;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}