/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "treenode.h"
int countNodes(struct TreeNode* root) {
    if(root == NULL)
        return 0;

    int lh,rh;
    struct TreeNode *tmp;

    tmp = root->left;
    lh = 0;
    while(tmp){
        lh++;
        tmp = tmp->left;
    }

    tmp = root->right;
    rh = 0;
    while(tmp){
        rh++;
        tmp = tmp->right;
    }

    if(lh == rh)
        return (2<<lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // 构造一棵二叉树
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    // 调用函数计算节点个数
    int count = countNodes(root);

    // TODO: 输出结果
    printf("The number of nodes in the binary tree is: %d", count);

    // TODO: 释放内存
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}