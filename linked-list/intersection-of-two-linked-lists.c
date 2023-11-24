#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    struct ListNode* pA = headA;
    struct ListNode* pB = headB;
    while (pA != pB) {
        pA = (pA == NULL) ? headB : pA->next;
        pB = (pB == NULL) ? headA : pB->next;
    }
    return pA;
}

int main() {
    // 构造两个链表
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    struct ListNode node4 = {4, NULL};
    struct ListNode node5 = {5, NULL};
    struct ListNode node6 = {6, NULL};
    struct ListNode node7 = {7, NULL};

    struct ListNode* headA = &node1;
    struct ListNode* headB = &node4;

    headA->next = &node2;
    headB->next = &node5;

    node2.next = &node3;
    node3.next = &node6;
    node5.next = &node6;

    node6.next = &node7;

    // 测试函数
    struct ListNode* intersection = getIntersectionNode(headA, headB);

    // 输出结果
    if (intersection == NULL) {
        printf("两个链表没有交点");
    } else {
        printf("两个链表的交点是：%d", intersection->val);
    }
    return 0;
}