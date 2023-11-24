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
    struct ListNode* ret;
    struct ListNode* prev;
    ret = head;

    while (head && head->next) {
        prev = head;
        head = head->next;
        if (prev->val == head->val) {
            prev->next = head->next;
            head = prev;
        }
    }

    return ret;
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