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

/**

 */
struct RandomListNode* get_node(int label)
{
    struct RandomListNode* ret;

    ret = malloc(sizeof(struct RandomListNode*));
    ret->label = label;
    ret->next = NULL;
    ret->random = NULL;
}

void copyList(struct RandomListNode* head)
{
    struct RandomListNode* next_node;
    while (head) {
        struct RandomListNode* new_node = get_node(head->label);
        next_node = head->next;
        head->next = new_node;
        new_node->next = next_node;
        head = next_node;
    }
}

void copyRandom(struct RandomListNode* head)
{
    while (head) {
        if (head->random) {
            head->next->random = head->random->next;
        }
        head = head->next->next;
    }
}

struct RandomListNode* spiltList(struct RandomListNode* head)
{
    struct RandomListNode* next_node;
    struct RandomListNode* new_node;
    struct RandomListNode root;

    root.next = head ? head->next : NULL;
    while (head) {
        next_node = head->next->next;
        new_node = head->next;
        head->next = next_node;
        new_node->next = next_node ? next_node->next : NULL;
        head = next_node;
    }

    return root.next;
}

struct RandomListNode* copyRandomList(struct RandomListNode* head)
{
    copyList(head);
    copyRandom(head);
    return spiltList(head);
}

int main()
{
    // 构造原链表
    struct RandomListNode node1, node2, node3, node4, node5;
    node1.label = 1;
    node2.label = 2;
    node3.label = 3;
    node4.label = 4;
    node5.label = 5;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    node1.random = &node3;
    node2.random = &node5;
    node3.random = &node1;
    node4.random = &node2;
    node5.random = &node4;

    // 复制链表
    struct RandomListNode* new_head = copyRandomList(&node1);

    // 打印原链表
    printf("原链表：\n");
    struct RandomListNode* p = &node1;
    while (p != NULL) {
        printf("label: %d, random: %d", p->label, (p->random == NULL) ? -1 : p->random->label);
        p = p->next;
    }

    // 打印新链表
    printf("\n新链表：\n");
    p = new_head;
    while (p != NULL) {
        printf("label: %d, random: %d", p->label, (p->random == NULL) ? -1 : p->random->label);
        p = p->next;
    }

    return 0;
}