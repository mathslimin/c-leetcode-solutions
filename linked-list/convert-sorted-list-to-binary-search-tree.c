#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "listnode.h"
#include "treenode.h"

//由于题目要求将有序链表转换为平衡二叉搜索树，因此我们需要找到链表的中间节点，将其作为根节点，然后递归处理左右子树。

int get_size(struct ListNode* head)
{
    int size = 0;
    while (head) {
        head = head->next;
        ++size;
    }

    return size;
}

struct TreeNode* bst_helper(struct ListNode** head, int size)
{
    if (size == 0)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left = bst_helper(head, size / 2);
    root->val = (*head)->val;
    (*head) = (*head)->next;
    root->right = bst_helper(head, size - size / 2 - 1);

    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    int size = get_size(head);
    if (head == NULL)
        return NULL;

    return bst_helper(&head, size);
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

int main() {
    // 构造有序链表
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;
    // 将有序链表转换为平衡二叉搜索树
    struct TreeNode* root = sortedListToBST(head);
    // 输出中序遍历结果
    inorderTraversal(root);
    return 0;
}