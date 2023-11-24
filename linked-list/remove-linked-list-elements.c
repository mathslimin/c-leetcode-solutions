#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode root;
    struct ListNode* cur;

    root.next = head;
    cur = &root;
    while (cur->next) {
        if (cur->next->val == val)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }

    return root.next;
}


int main() {
    // 构造链表 1->2->6->3->4->5->6
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 6;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 3;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 4;
    head->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->next->val = 5;
    head->next->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->next->next->val = 6;
    head->next->next->next->next->next->next->next = NULL;

    int val = 6;

    printf("原链表：");
    printList(head);

    struct ListNode *newHead = removeElements(head, val);

    printf("删除节点 %d 后的链表：", val);
    printList(newHead);

    return 0;
}