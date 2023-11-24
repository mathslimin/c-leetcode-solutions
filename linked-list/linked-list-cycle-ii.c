#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**
由于题目要求找到链表中的环的起点，我们可以使用快慢指针来判断链表是否有环，并且找到环的长度。接着，我们可以使用双指针来找到环的起点。
 */
struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    do {
        if (!slow || !fast || !fast->next)
            return NULL;

        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    while (head != slow) {
        head = head->next;
        slow = slow->next;
    }

    return head;
}

int main() {
    struct ListNode n1, n2, n3, n4, n5;
    n1.val = 1; n2.val = 2; n3.val = 3; n4.val = 4; n5.val = 5;
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5; n5.next = &n2;

    struct ListNode *res = detectCycle(&n1);
    printf("%d", res->val); // 输出2
    return 0;
}