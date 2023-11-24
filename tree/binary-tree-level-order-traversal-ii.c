#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**
 */

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    int** arr;
    int* col;
    struct TreeNode** q;
    struct TreeNode** new_q;
    struct TreeNode** cur;
    int arr_count = 8;
    int idx = 0;
    int q_count = 512;
    int tmp_count = 8;
    int i, j;

    arr = malloc(sizeof(int*) * arr_count);
    col = malloc(sizeof(int) * arr_count);
    q = malloc(sizeof(struct TreeNode*) * q_count);
    new_q = malloc(sizeof(struct TreeNode*) * q_count);

    q[0] = root;
    q[1] = NULL;
    while (*q) {
        int* tmp;
        i = 0;
        j = 0;
        cur = q;
        memset(new_q, 0, sizeof(struct TreeNode*) * q_count);
        tmp = malloc(sizeof(int) * tmp_count);
        while (*cur) {
            if (i == tmp_count) {
                tmp_count <<= 1;
                tmp = realloc(tmp, sizeof(int) * tmp_count);
            }
            tmp[i++] = (*cur)->val;
            if ((*cur)->left)
                new_q[j++] = (*cur)->left;
            if ((*cur)->right)
                new_q[j++] = (*cur)->right;

            cur++;
        }

        if (idx == arr_count) {
            arr_count <<= 1;
            col = realloc(col, sizeof(int) * arr_count);
            arr = realloc(arr, sizeof(int*) * arr_count);
        }

        col[idx] = i;
        arr[idx++] = tmp;

        cur = new_q;
        new_q = q;
        q = cur;
    }

    i = 0;
    j = idx - 1;
    while (i < j) {
        int* swap = arr[i];
        int swap_col = col[i];

        arr[i] = arr[j];
        arr[j] = swap;

        col[i] = col[j];
        col[j] = swap_col;
        i++;
        j--;
    }

    *columnSizes = col;
    *returnSize = idx;
    free(q);
    free(new_q);

    return arr;
}


void printArray(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void printResult(int **result, int *sizes, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printArray(result[i], sizes[i]);
        if (i != size - 1) {
            printf(",");
        }
    }
    printf("]");
}

int main() {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->val = 9;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->val = 20;
    root->right->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->left->val = 15;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->right->val = 7;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    int *columnSizes = NULL;
    int returnSize = 0;
    int **result = levelOrderBottom(root, &columnSizes, &returnSize);
    printResult(result, columnSizes, returnSize);
    return 0;
}
