#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**
题目描述

给定一个单链表，判断它是否是回文的。

示例 1:

输入: 1->2
输出: false

示例 2:

输入: 1->2->2->1
输出: true

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

解法思路

首先，我们可以通过快慢指针找到链表的中点，然后将链表后半部分进行翻转，最后比较前半部分和后半部分是否相等即可。

时间复杂度：O(n)，其中 n 是链表的长度。
 */
int get_length(struct ListNode* head)
{
    int ret = 0;
    while (head) {
        head = head->next;
        ret++;
    }
    return ret;
}

bool isPalindrome(struct ListNode* head)
{
    int len;
    int i;
    struct ListNode root;
    struct ListNode* left;
    struct ListNode* tmp;

    root.next = NULL;
    left = head;
    len = get_length(head);

    for (i = 0; i < (len + 1) / 2; i++)
        head = head->next;

    while (head) {
        tmp = head->next;
        head->next = root.next;
        root.next = head;
        head = tmp;
    }

    tmp = root.next;
    while (tmp) {
        if (tmp->val != left->val)
            return false;
        tmp = tmp->next;
        left = left->next;
    }

    return true;
}

int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 2;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 1;
    head->next->next->next->next = NULL;
    printf("%d", isPalindrome(head)); // 输出 1
    return 0;
}