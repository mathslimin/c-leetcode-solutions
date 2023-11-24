#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL) return true; // 如果两个节点都为空，返回true
    if(p == NULL || q == NULL) return false; // 如果只有一个节点为空，返回false
    if(p->val != q->val) return false; // 如果两个节点的值不相等，返回false
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // 递归判断左右子树是否相同
}

// main()函数测试代码
int main() {
    struct TreeNode *p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode *q = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->val = 1;
    p->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->left->val = 2;
    p->left->left = NULL;
    p->left->right = NULL;
    p->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->right->val = 3;
    p->right->left = NULL;
    p->right->right = NULL;
    q->val = 1;
    q->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    q->left->val = 2;
    q->left->left = NULL;
    q->left->right = NULL;
    q->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    q->right->val = 3;
    q->right->left = NULL;
    q->right->right = NULL;
    bool res = isSameTree(p, q);
    printf("%d", res);
    return 0;
}