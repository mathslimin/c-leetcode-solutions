#include <stdio.h>
#include <stdlib.h>
#include "listnode.h"

/**
根据题目描述，我们需要判断链表中是否存在环，并返回环的起始位置。我们可以使用快慢指针来判断链表中是否存在环，并找到环的起始位置。
 */
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;

    // 判断链表中是否存在环
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    // 如果链表中不存在环，直接返回NULL
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }

    // 找到环的起始位置
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
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
    struct ListNode *cycleStart = detectCycle(head);

    // 输出结果
    if (cycleStart == NULL) {
        printf("链表中不存在环");
    } else {
        printf("链表中存在环，环的起始位置为：%d", cycleStart->val);
    }

    return 0;
}