#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) { // 如果根节点为空，直接返回空数组
        *returnSize = 0;
        return NULL;
    }
    int* res = (int*)malloc(sizeof(int) * 1000); // 申请一个足够大的数组
    int front = 0, rear = 0; // 队列的头尾指针
    struct TreeNode* q[1000]; // 定义一个队列
    q[rear++] = root; // 将根节点入队
    while (front < rear) { // 队列不为空时循环
        int n = rear - front; // 当前层的节点数
        for (int i = 0; i < n; i++) { // 遍历当前层的所有节点
            struct TreeNode* node = q[front++]; // 取出队列中的节点
            if (i == n - 1) { // 如果是当前层的最后一个节点
                res[*returnSize] = node->val; // 将节点的值保存在结果数组中
                (*returnSize)++; // 结果数组的大小加1
            }
            if (node->left) { // 如果左子节点不为空，将其入队
                q[rear++] = node->left;
            }
            if (node->right) { // 如果右子节点不为空，将其入队
                q[rear++] = node->right;
            }
        }
    }
    return res; // 返回结果数组
}

int main() {
    // 构造二叉树
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 5;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 4;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    // 调用函数
    int returnSize = 0;
    int* res = rightSideView(root, &returnSize);
    // 输出结果
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    // 释放内存
    free(root->left->right);
    free(root->left);
    free(root->right->right);
    free(root->right);
    free(root);
    free(res);
    return 0;
}