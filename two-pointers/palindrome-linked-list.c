#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listnode.h"

/**

 */
struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode root;
    struct ListNode* tmp;
    root.next = NULL;
    while (head) {
        tmp = head->next;
        head->next = root.next;
        root.next = head;
        head = tmp;
    }

    return root.next;
}

bool isPalindrome(struct ListNode* head)
{
    int count = 0;
    int i;
    struct ListNode root;
    struct ListNode* right;
    struct ListNode *mid, *tmp;

    root.next = head;
    while (head) {
        count++;
        head = head->next;
    }

    head = &root;
    i = 0;
    while (i < ((count + 1) / 2)) {
        head = head->next;
        i++;
    }

    mid = head;
    right = reverse(head->next);
    tmp = right;
    head = root.next;
    while (right) {
        if (right->val != head->val) {
            mid->next = reverse(tmp);
            return false;
        }
        right = right->next;
        head = head->next;
    }

    mid->next = reverse(tmp);
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