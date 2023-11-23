//23. 合并 K 个升序链表
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "listnode.h"

struct ListNode *merge_two_list(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode head;
    struct ListNode *cursor,*tmp;

    cursor = &head;

    while(l1 && l2){
        if(l1->val < l2->val){
            cursor->next = l1;
            l1 = l1->next;
        }else{
            cursor->next = l2;
            l2 = l2->next;
        }
        cursor = cursor->next;
    }


    if(l1)
        cursor->next = l1;
    else
        cursor->next = l2;

    return head.next;
}

struct ListNode* merge_list_range(struct ListNode **lists, int start, int end)
{
    struct ListNode *left, *right;
    int mid;

    if(start == end)
        return lists[start];

    mid = (start + end) / 2;

    left = merge_list_range(lists, start, mid);
    right = merge_list_range(lists, mid+1, end);

    return merge_two_list(left,right);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0)
        return NULL;

    return merge_list_range(lists, 0, listsSize-1);
}

int main() {
    // 测试样例
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l2->val = 2;
    l3->val = 3;
    l1->next = l2;
    l2->next = l3;
    l3->next = NULL;
    struct ListNode* l4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l4->val = 4;
    l5->val = 5;
    l6->val = 6;
    l4->next = l5;
    l5->next = l6;
    l6->next = NULL;
    struct ListNode* l7 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l8 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l9 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l7->val = 7;
    l8->val = 8;
    l9->val = 9;
    l7->next = l8;
    l8->next = l9;
    l9->next = NULL;
    struct ListNode* lists[3] = {l1, l4, l7};
    struct ListNode* res = mergeKLists(lists, 3);
    while (res) {
        printf("%d ", res->val);
        res = res->next;
    }
    return 0;
}