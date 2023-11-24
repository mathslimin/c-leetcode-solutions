#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**
这是一道链表的题目，题目描述为：给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

我们可以使用两个指针，一个指向小于 x 的链表，一个指向大于等于 x 的链表，最后将两个链表拼接在一起即可。
 */
struct ListNode* partition(struct ListNode* head, int x){
    // 创建两个链表，一个存储小于 x 的节点，一个存储大于等于 x 的节点
    struct ListNode *small = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *big = (struct ListNode *)malloc(sizeof(struct ListNode));
    // 创建两个指针，指向两个链表的头节点
    struct ListNode *p1 = small;
    struct ListNode *p2 = big;
    // 遍历链表，将节点分别放入两个链表中
    while (head) {
        if (head->val < x) {
            p1->next = head;
            p1 = p1->next;
        } else {
            p2->next = head;
            p2 = p2->next;
        }
        head = head->next;
    }
    // 将两个链表拼接在一起
    p2->next = NULL;
    p1->next = big->next;
    return small->next;
}

// 创建链表
struct ListNode *createListNode(int arr[], int n) {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = head;
    for (int i = 0; i < n; i++) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        p->next = node;
        p = p->next;
    }
    return head->next;
}

int main() {
    int arr[] = {1, 4, 3, 2, 5, 2};
    int n = sizeof(arr) / sizeof(int);
    struct ListNode *head = createListNode(arr, n);
    printf("原链表：");
    printList(head);
    int x = 3;
    struct ListNode *newHead = partition(head, x);
    printf("分隔后的链表：");
    printList(newHead);
    return 0;
}