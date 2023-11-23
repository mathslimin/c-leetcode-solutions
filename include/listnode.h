#include <stdarg.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* buildList(int* nums, int numsSize)
{
    if (numsSize == 0)
        return NULL;

    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    struct ListNode* p = dummy;
    for (int i = 0; i < numsSize; i++) {
        p->next = malloc(sizeof(struct ListNode));
        p->next->val = nums[i];
        p = p->next;
    }
    p->next = NULL;

    p = dummy->next;
    free(dummy);

    return p;
}

struct ListNode* createList(int num, ...)
{
    va_list args;
    va_start(args, num);
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    for (int i = 0; i < num; i++) {
        int val = va_arg(args, int);
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = val;
        node->next = NULL;
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    va_end(args);
    return head;
} 

void printList(struct ListNode* list) {
    while (list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
} 
