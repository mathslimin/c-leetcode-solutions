#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**

*/
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct TreeNode** st;
    struct TreeNode* cur;
    int* arr;
    int top;
    int idx = 0;
    int st_count = 50;
    int arr_count = 50;

    st = malloc(sizeof(struct TreeNode*) * st_count);
    arr = malloc(sizeof(int) * arr_count);
    top = -1;

    cur = root;
    while (cur || top > -1) {
        while (cur) {
            if (top + 1 == st_count) {
                st_count <<= 1;
                st = realloc(st, st_count * sizeof(struct TreeNode*));
            }
            st[++top] = cur;
            cur = cur->left;
        }

        cur = st[top];
        top--;
        arr[idx++] = cur->val;
        cur = cur->right;
        if (idx == arr_count) {
            arr_count <<= 1;
            arr = realloc(arr, arr_count * sizeof(int));
        }
    }

    free(st);
    *returnSize = idx;

    return arr;
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 2;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 3;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = NULL;

    int returnSize;
    int* res = inorderTraversal(root, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(root->right->left);
    free(root->right);
    free(root);

    free(res);

    return 0;
}