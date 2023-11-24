#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct RandomListNode {
    int label;
    struct RandomListNode* next;
    struct RandomListNode* random;
};
struct RandomListNode* copyRandomList(struct RandomListNode* head)
{
    struct RandomListNode root;
    struct RandomListNode* pre;
    struct RandomListNode* new_node;

    root.next = head;
    while (head) {
        new_node = malloc(sizeof(struct RandomListNode));
        new_node->next = head->next;
        new_node->label = head->label;
        head->next = new_node;
        head = head->next->next;
    }

    head = root.next;
    while (head) {
        new_node = head->next;
        if (head->random)
            new_node->random = head->random->next;
        else
            new_node->random = NULL;

        head = head->next->next;
    }

    head = root.next;
    pre = &root;
    while (head) {
        new_node = head->next;
        head->next = new_node->next;
        head = head->next;

        pre->next = new_node;
        pre = new_node;
    }

    pre->next = NULL;

    return root.next;
}

int main()
{
    //测试样例
    struct RandomListNode* head = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
    head->label = 1;
    head->next = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
    head->next->label = 2;
    head->next->next = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
    head->next->next->label = 3;
    head->next->next->next = NULL;
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;

    struct RandomListNode* newHead = copyRandomList(head);
    while (newHead != NULL) {
        printf("%d ", newHead->label);
        if (newHead->random != NULL) {
            printf("%d ", newHead->random->label);
        } else {
            printf("null ");
        }
        newHead = newHead->next;
    }
    return 0;
}