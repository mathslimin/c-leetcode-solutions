#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */

int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    int** data;
    int* arr_count;
    int data_count = 500;
    int idx = 0;
    struct TreeNode** cur_st;
    struct TreeNode** next_st;
    int cur_top = -1;
    int next_top = -1;
    int left2right = 0;
    struct TreeNode* cur;

    data = malloc(sizeof(int*) * data_count);
    arr_count = malloc(sizeof(int) * data_count);

    cur_st = malloc(sizeof(struct TreeNode*) * 500);
    next_st = malloc(sizeof(struct TreeNode*) * 500);

    if (root)
        cur_st[++cur_top] = root;

    while (cur_top > -1) {
        int c = 0;
        struct TreeNode** swap;

        next_top = -1;
        data[idx] = malloc(sizeof(int) * data_count);
        while (cur_top > -1) {
            cur = cur_st[cur_top--];
            data[idx][c++] = cur->val;
            if (left2right) {
                if (cur->right)
                    next_st[++next_top] = cur->right;
                if (cur->left)
                    next_st[++next_top] = cur->left;
            } else {
                if (cur->left)
                    next_st[++next_top] = cur->left;
                if (cur->right)
                    next_st[++next_top] = cur->right;
            }
        }
        arr_count[idx] = c;
        idx++;
        left2right ^= 1;

        swap = cur_st;
        cur_st = next_st;
        next_st = swap;

        cur_top = next_top;
    }

    *columnSizes = arr_count;
    *returnSize = idx;

    free(cur_st);
    free(next_st);
    return data;
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 9;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 20;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 15;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 7;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    int** columnSizes = (int**)malloc(sizeof(int*));
    columnSizes[0] = (int*)calloc(1000, sizeof(int));
    int returnSize;
    int** res = zigzagLevelOrder(root, columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < columnSizes[0][i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}