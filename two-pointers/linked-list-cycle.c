#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listnode.h"

/**

 */
bool hasCycle(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }

    return false;
}

int main() {
    // 创建链表
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 3;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 0;
    head->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->val = -4;
    head->next->next->next->next = head->next;

    // 判断链表中是否存在环，并找到环的起始位置
    bool ret = hasCycle(head);

    // 输出结果
    if (ret) {
        printf("链表中存在环");
    } else {
        printf("链表中不存在环");
    }

    return 0;
}