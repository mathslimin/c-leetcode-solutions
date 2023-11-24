#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode root;
    struct ListNode* cur;
    int count;
    int val;

    cur = &root;
    while (head) {
        count = 1;
        val = head->val;
        while (head->next && head->next->val == val) {
            head = head->next;
            count++;
        }

        if (count > 1)
            goto next_loop;

        cur->next = head;
        cur = cur->next;

    next_loop:
        head = head->next;
    }

    cur->next = NULL;
    return root.next;
}


int main() {
    // 创建链表 1->1->2->3->3
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 1;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 2;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 3;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 3;
    head->next->next->next->next->next = NULL;

    // 调用函数
    head = deleteDuplicates(head);

    // 输出结果
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    return 0;
}