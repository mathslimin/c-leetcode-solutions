#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

/**

 */
bool hasCycle(struct ListNode* head)
{
    struct ListNode* one;
    struct ListNode* two;

    one = head;
    two = head;

    while (one && two) {
        one = one->next;
        two = two->next;

        if (two)
            two = two->next;
        if (one && one == two)
            return true;
    }

    return false;
}


// 测试代码
int main() {
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    struct ListNode node4 = {4, NULL};
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2; // 构造环
    bool result = hasCycle(&node1);
    printf("%d", result); // 输出1
    return 0;
}