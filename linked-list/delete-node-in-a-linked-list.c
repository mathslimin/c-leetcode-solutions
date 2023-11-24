#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int main()
{
    return 0;
}