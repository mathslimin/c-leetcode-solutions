```c
/* Leetcode 中级算法篇
    ① 数组和字符串
        三数之和
        矩阵置零
        字母异位词分组
        无重复字符的最长子串
        最长回文子串
        递增的三元子序列

    ② 链表
        两数相加
        奇偶链表
        相交链表

    ③ 树和图
        二叉树的中序遍历
        二叉树的锯齿形层次遍历
        从前序与中序遍历构造二叉树
        填充每个节点的下一个右侧节点指针
        二叉搜索树中第K小的元素
        岛屿数量

    ④ 回溯算法
        电话号码的字母组合
        括号生成
        全排列
        子集
        单词搜索

    ⑤ 排序和搜索
        颜色分类
        前K个高频元素
        数组中的第K个最大元素
        寻找峰值
        在拍序数组中查找元素的第一个和最后一个位置
        合并区间
        搜索旋转排序数组
        搜索二维矩阵II

    ⑥ 动态规划
        跳跃游戏
        不同路径
        零钱兑换
        最长上升子序列

    ⑦ 设计问题
        二叉树的序列化与反序列化
        常熟时间插入、删除和获取随机元素

    ⑧ 数学
        快乐数
        阶乘后的零
        Excel表列序号
        Pow（x,n）
        x的平方根
        两数相除
        分数到小数

    ⑨ 其他
        两整数之和
        逆波兰表达式求值
        多数元素
        任务调度器
*/

/*
    ① 数组和字符串
        三数之和
        矩阵置零
        字母异位词分组
        无重复字符的最长子串
        最长回文子串
        递增的三元子序列
*/
// 15. 三数之和
#define MAX_SIZE_FACTOR 6
int Compare(const void *a, const void *b) 
{
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    *returnSize = 0;
    if (nums == NULL || numsSize < 3) {  
        *returnColumnSizes = NULL; 
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), Compare);
    int **ans = (int**)malloc((numsSize + 1) * MAX_SIZE_FACTOR * sizeof(int *));
    *returnColumnSizes = (int*)malloc((numsSize + 1) * MAX_SIZE_FACTOR * sizeof(int));    
    for (int i = 0; i < numsSize ; i++) {
        if (nums[i] > 0) {
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int L = i + 1;
        int R = numsSize - 1;
        while (L < R) {
            int sum = nums[i] + nums[L] + nums[R];
            if (sum == 0) {
                ans[*returnSize] = malloc(sizeof(int) * 3);
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[L];
                ans[*returnSize][2] = nums[R];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while (L < R && nums[L] == nums[++L]);
                while (L < R && nums[R] == nums[--R]);
            } else if (sum < 0) {
                L++;
            } else if (sum > 0) {
                R--;
            }
        }
    }
    return ans;
}

// 73. 矩阵置零
void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    int* row = (int*)calloc(matrixSize, sizeof(int));
    int* col = (int*)calloc(*matrixColSize, sizeof(int));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                row[i]++;
                col[j]++;
            }
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (row[i] != 0 || col[j] != 0) {
                matrix[i][j] = 0;
            }
        }
    }
    return;
}

// 49. 字母异位词分组
#define MAXLENGTH 10000
typedef struct hashTable {
    char keyStr[MAXLENGTH]; // key值为排序后的字符串
    int id;                 // 记录在res中的位置
    int count;              // 记录分组中元素的个数
    UT_hash_handle hh;
} MyHash;

int Compare(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    if (strsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    char ***res = (char ***)malloc(sizeof(char **) * strsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);
    *returnSize = 0;
    MyHash* hashtable = NULL;
    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        char* tmp = (char*)calloc(len + 1, sizeof(int));
        sprintf(tmp, "%s", strs[i]);
        qsort(tmp, len, sizeof(char), Compare);
        MyHash* tmpHash = NULL;
        HASH_FIND_STR(hashtable, tmp, tmpHash);
        if (tmpHash == NULL) {
            tmpHash = (MyHash*)malloc(sizeof(MyHash));
            memset(tmpHash->keyStr, 0, sizeof(char) * MAXLENGTH);
            memcpy(tmpHash->keyStr, tmp, sizeof(char) * len);
            tmpHash->id = *returnSize;
            tmpHash->count = 1;
            HASH_ADD_STR(hashtable, keyStr, tmpHash);
            res[*returnSize] = (char**)malloc(sizeof(char*) * strsSize);
            res[*returnSize][tmpHash->count - 1] = (char*)calloc(len + 1, sizeof(char));
            sprintf(res[*returnSize][tmpHash->count - 1], "%s", strs[i]);
            (*returnColumnSizes)[*returnSize] = tmpHash->count;
            (*returnSize)++;
        } else {
            res[tmpHash->id][tmpHash->count] = (char *)calloc(len + 1, sizeof(char));
            sprintf(res[tmpHash->id][tmpHash->count], "%s", strs[i]);
            tmpHash->count++;
            (*returnColumnSizes)[tmpHash->id] = tmpHash->count;
        }
    }
    return res;
}

// 3. 无重复字符的最长子串
#define SIZE 300
int hash[SIZE];

bool IsNoRepeat(char *s, int begin, int end)
{
    memset(hash, 0, sizeof(int) * SIZE);
    for (int i = begin; i <= end; i++) {
        hash[s[i]]++;
        if (hash[s[i]] > 1) {
            return false;
        }
    }
    return true;
}

int lengthOfLongestSubstring(char * s)
{
    int len = strlen(s);
    if (len <= 1) {
        return len;
    }

    int maxLen = INT_MIN;
    int head = 0;
    int tail = 0;

    while (tail < len) {
        if (IsNoRepeat(s, head, tail)) {
            maxLen = fmax(maxLen, tail - head + 1);
            tail++;
        } else {
            head++;
        }
    }

    return maxLen;
}

// 5. 最长回文子串
void Help(char *s, int len, int left, int right, int *start, int *length)
{
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    if (right - left - 1 > *length) {
        *start = left + 1;
        *length = right - left - 1;
    }
    return;
}

char * longestPalindrome(char * s)
{
    int len = strlen(s);
    int start = 0;
    int length = 0;
    for (int i = 0; i < len; i++) {
        Help(s, len, i - 1, i + 1, &start, &length);
    }
    for (int i = 0; i < len; i++) {
        Help(s, len, i, i + 1, &start, &length);
    }
    s[start + length] = '\0';
    return s + start;
}

// 334. 递增的三元子序列
bool increasingTriplet(int* nums, int numsSize)
{
    if (numsSize < 3) {
        return false;
    }

    int* minNum = (int*)malloc(sizeof(int) * (numsSize - 2));
    int* maxNum = (int*)malloc(sizeof(int) * (numsSize - 2));
    minNum[0] = nums[0];
    maxNum[numsSize - 3] = nums[numsSize - 1];
    for (int i = 1; i < numsSize - 2; i++) {
        minNum[i] = fmin(nums[i], minNum[i - 1]);
    }
    for (int i = numsSize - 4; i >= 0; i--) {
        maxNum[i] = fmax(nums[i + 2], maxNum[i + 1]);
    }
    for (int i = 1; i < numsSize - 1; i++) {
        if (minNum[i - 1] < nums[i] && nums[i] < maxNum[i - 1]) {
            return true;
        }
    }
    return false;
}



/*
    ② 链表
        两数相加
        奇偶链表
        相交链表
*/
// 2. 两数相加
#define SIZE 102

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int temp[SIZE];
    int size = 0;
    int res = 0;
    struct ListNode *tmp1 = l1;
    struct ListNode *tmp2 = l2;
    while (tmp1 && tmp2) {
        int val = (tmp1->val + tmp2->val + res) % 10;
        res = (tmp1->val + tmp2->val + res) / 10;
        temp[size++] = val;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    while (tmp1) {
        int val = (tmp1->val + res) % 10;
        res = (tmp1->val+ res) / 10;
        temp[size++] = val;
        tmp1 = tmp1->next;
    }
    while (tmp2) {
        int val = (tmp2->val + res) % 10;
        res = (tmp2->val+ res) / 10;
        temp[size++] = val;
        tmp2 = tmp2->next;
    }
    if (res != 0) {
        temp[size++] = res;
    }

    struct ListNode *ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    ans->val = temp[0];
    ans->next = NULL;
    if (size < 2) {
        return ans;
    }

    struct ListNode *head = ans;
    for (int i = 1; i < size; i++) {
        struct ListNode *cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->val = temp[i];
        cur->next = NULL;
        head->next = cur;
        head = cur;
    }
    
    return ans;
}

// 328. 奇偶链表
#define SIZE 10000
struct ListNode* oddEvenList(struct ListNode* head)
{
    int tempA[SIZE];
    int tempB[SIZE];
    int sizeA = 0;
    int sizeB = 0;
    int cur = 0;
    struct ListNode *tmp = head;
    while (tmp) {
        if (cur % 2 == 0) {
            tempA[sizeA++] = tmp->val;
        } else {
            tempB[sizeB++] = tmp->val;
        }
        cur++;
        tmp = tmp->next;
    }
    tmp = head;
    cur = 0;
    int curB = 0;
    while (tmp) {
        if (cur < sizeA) {
            tmp->val = tempA[cur];
            cur++;
            tmp = tmp->next;
        } else {
            tmp->val = tempB[curB];
            curB++;
            tmp = tmp->next;
        }
        
    }
    return head;
}

// 160. 相交链表
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    struct ListNode *pA = headA;
    struct ListNode *pB = headB;
    while (pA != pB) {
        pA = (pA == NULL ? headB : pA->next);
        pB = (pB == NULL ? headA : pB->next);
    }
    return pA;
}

/*
    ③ 树和图
        二叉树的中序遍历
        二叉树的锯齿形层次遍历
        从前序与中序遍历构造二叉树
        填充每个节点的下一个右侧节点指针
        二叉搜索树中第K小的元素
        岛屿数量
*/
// 94. 二叉树的中序遍历
#define MAX 101
void InOrder(struct TreeNode* root, int* arr, int* size)
{
    if (root) {
        InOrder(root->left, arr, size);
        arr[(*size)++] = root->val;
        InOrder(root->right, arr, size);
    }
    return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * MAX);
    *returnSize = 0;
    InOrder(root, ans, returnSize);
    return ans;
}

// 103. 二叉树的锯齿形层序遍历
#define MAX 10000
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int** ans = (int**)malloc(sizeof(int*) * MAX);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX);
    *returnSize = 0;

    struct TreeNode* queue[MAX];
    int head = 0;
    int tail = 0;
    queue[tail++] = root;
    while (head != tail) {
        int size = tail - head;
        ans[*returnSize] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[*returnSize] = size;
        for (int i = 0; i < size; i++) {
            ans[*returnSize][i] = queue[head]->val;
            if (queue[head]->left) {
                queue[tail++] = queue[head]->left;
            }
            if (queue[head]->right) {
                queue[tail++] = queue[head]->right;
            }
            head++;
        }
        (*returnSize)++;
    }

    for (int i = 0; i < *returnSize; i++) {
        if (i % 2) {
            int size = (*returnColumnSizes)[i];
            for (int j = 0; j < size / 2; j++) {
                int temp = ans[i][j];
                ans[i][j] = ans[i][size - 1 - j];
                ans[i][size - 1 - j] = temp;
            }
        }
    }
    return ans;
}

// 105. 从前序与中序遍历序列构造二叉树
typedef struct TreeNode TreeNode;
TreeNode* construct(int* preorder, int* inorder, int i, int j, int n) 
{
    if (n <= 0) {
        return NULL;
    }

    TreeNode* root = malloc(sizeof(TreeNode));
    if (n == 1) {
        root->val = *(preorder + i);
        root->left = root->right = NULL;
        return root;
    }

    int k = j;
    while (inorder[k] != preorder[i]) {
        k++;
    }

    const int leftLen = k - j;
    root->val = inorder[k];
    root->left  = construct(preorder, inorder, i + 1, j, leftLen);
    root->right = construct(preorder, inorder, i + 1 + leftLen, k + 1, n - leftLen - 1);
    return root;
}

TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) 
{
    return construct(preorder, inorder, 0, 0, preorderSize);
}

// 116. 填充每个节点的下一个右侧节点指针
struct Node* connect(struct Node* root) 
{
    if (root == NULL) {
        return root;
    }
    struct Node* leftmost = root;
    while (leftmost->left != NULL) {
        struct Node* head = leftmost;
        while (head != NULL) {
            head->left->next = head->right;
            if (head->next != NULL) {
                head->right->next = head->next->left;
            }
            head = head->next;
        }
        leftmost = leftmost->left;
    }
    return root;
}

// 230. 二叉搜索树中第K小的元素
#define MAX 10001
void InOrder(struct TreeNode* root, int* arr, int* size)
{
    if (root) {
        InOrder(root->left, arr, size);
        arr[(*size)++] = root->val;
        InOrder(root->right, arr, size);
    }
    return;
}

int kthSmallest(struct TreeNode* root, int k)
{
    int* temp = (int*)malloc(sizeof(int) * MAX);
    int size = 0;
    InOrder(root, temp, &size);
    return temp[k - 1];
}

// 200. 岛屿数量
// DFS解法
#define ROW 4
#define COL 2
int direciton[ROW][COL] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void Dfs(char** grid, int row, int col, int x, int y)
{
    if (x < 0 || x >= row || y < 0 || y >= col) {
        return;
    }
    if (grid[x][y] == '2' || grid[x][y] == '0') {
        return;
    }
    grid[x][y] = '2';
    for (int i = 0; i < ROW; i++) {
        Dfs(grid, row, col, x + direciton[i][0], y + direciton[i][1]);
    }
    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == '1') {
                Dfs(grid, gridSize, *gridColSize, i, j);
                count++;
            }
        }
    }
    return count;
}

// BFS
#define MAX 100001
#define ROW 4
#define COL 2
int direciton[ROW][COL] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct Point {
    int x;
    int y;
} MyPoint;

void Bfs(char** grid, int row, int col, int x, int y)
{
    MyPoint* queue = (MyPoint*)malloc(sizeof(MyPoint) * MAX);
    int head = 0;
    int tail = 0;
    queue[tail].x = x;
    queue[tail++].y = y;
    while (head != tail) {
        for (int i = 0; i < tail - head; i++) {
            grid[queue[head].x][queue[head].y] = '2';
            for (int j = 0; j < ROW; j++) {
                int newX = queue[head].x + direciton[j][0];
                int newY = queue[head].y + direciton[j][1];
                if (newX < 0 || newX >= row || newY < 0 || newY >= col) {
                    continue;
                }
                if (grid[newX][newY] == '0' || grid[newX][newY] == '2') {
                    continue;
                }
                queue[tail].x = newX;
                queue[tail++].y = newY;
            }
            head++;
        }
    }
    return;
}


int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == '1') {
                Bfs(grid, gridSize, *gridColSize, i, j);
                count++;
            }
        }
    }
    return count;
}

// 并查集
#define ROW 4
#define COL 2
int direciton[ROW][COL] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int gCount;
int* gParent;
int* gSize;

void InitSet(int n)
{
    gCount = n;
    gParent = (int*)malloc(sizeof(int) * n);
    gSize = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        gParent[i] = i;
        gSize[i] = 1;
    }
    return;
}

int FindRoot(int x) {
    while (x != gParent[x]) {
        gParent[x] = gParent[gParent[x]];
        x = gParent[x];
    }
    return x;
}

void Union(int x, int y)
{
    int rootX = FindRoot(x);
    int rootY = FindRoot(y);
    if (rootX == rootY) {
        return;
    }

    if (gSize[rootX] < gSize[rootY]) {
        gParent[rootX] = rootY;
        gSize[rootY] += gSize[rootX];
    } else {
        gParent[rootY] = rootX;
        gSize[rootX] += gSize[rootY];
    }
    gCount--;
    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int row = gridSize;
    int col = *gridColSize;
    InitSet(row * col + 1);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == '0') {
                Union(i * col + j, row * col);
                continue;
            }
            for (int k = 0; k < ROW; k++) {
                int newX = i + direciton[k][0];
                int newY = j + direciton[k][1];
                if (newX >= 0 && newX < row && newY >= 0 && newY < col && grid[newX][newY] == '1') {
                    Union(i * col + j, newX * col + newY);
                }
            }
        }
    }
    return gCount - 1;
}



/*
    ④ 回溯算法
        电话号码的字母组合
        括号生成
        全排列
        子集
        单词搜索
*/
// 17. 电话号码的字母组合
char map[8][5] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int AlphaSize(char c)
{
    if (c =='7' || c == '9') {
        return 4;
    }
    return 3;
}

char** letterCombinations(char* digits, int* returnSize)
{
    int len = strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 1;
    for (int i = 0; i < len; i++) {
        (*returnSize) *= AlphaSize(digits[i]);
    }

    char** ans = (char**)malloc(sizeof(char*) * (*returnSize));
    int interval = *returnSize;
    for (int i = 0; i < (*returnSize); i++) {
        ans[i] = (char*)malloc(sizeof(char) * (len + 1));
        ans[i][len] = '\0';
    }
    for (int i = 0; i < len; i++) {
        interval /= AlphaSize(digits[i]);
        for (int j = 0; j < (*returnSize); ++j) {
            ans[j][i] = map[digits[i] - '2'][(j / interval) % AlphaSize(digits[i])];
        }
    }

    return ans;
}

// 22. 括号生成
#define MAX_CNT 5000
void DFS(char* str, int n, int left, int right, char** ans, int* returnsize)
{
    if (left < right) {
        return;
    }
    if (left == n && right == n) {
        int size = 2 * n + 1;
        ans[*returnsize] = (char*)calloc(size, sizeof(char));
        memcpy(ans[*returnsize], str, size * sizeof(char));
        (*returnsize)++;
        return;
    }
    if (left < n) {
        str[left + right] = '(';
        DFS(str, n, left + 1, right, ans, returnsize);
        str[left + right] = 0;
    }
    if (right < n && left > right) {
        str[left + right] = ')';
        DFS(str, n, left, right + 1, ans, returnsize);
        str[left + right] = 0;
    }
}

char** generateParenthesis(int n, int* returnSize) 
{
    char* str = (char*)calloc(2 * n + 1, sizeof(char));
    char** ans = (char**)calloc(MAX_CNT, sizeof(char*));
    *returnSize = 0;

    DFS(str, n, 0, 0, ans, returnSize);
    return ans;
}

// 46. 全排列
int count;
void Dfs(int* nums, int numsSize, int depth, int* tmp, bool* used, int** ans)
{
    if (depth == numsSize) {
        ans[count] = (int*)malloc(numsSize * sizeof(int));
        memcpy(ans[count++], tmp, numsSize * sizeof(int));
        return;
    }

    for (int i = 0; i < numsSize; ++i) {
        if (used[i] == true) {
            continue;
        }
        tmp[depth] = nums[i];
        used[i] = true;
        Dfs(nums, numsSize, depth + 1, tmp, used, ans);
        used[i] = false;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int solution = 1;
    for (int i = 1; i <= numsSize; ++i) {
        solution *= i;
    }

    int** ans = (int**)malloc(solution * sizeof(int*));
    *returnSize = solution;
    *returnColumnSizes = (int*)malloc(solution * sizeof(int));
    for (int i = 0; i < solution; ++i) {
        (*returnColumnSizes)[i] = numsSize;
    }

    int* tmp = (int*)malloc(numsSize * sizeof(int));
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    count = 0;
    Dfs(nums, numsSize, 0, tmp, used, ans);
    return ans;
}

// 78. 子集
// DFS，回溯
int** ans;
int* ansColSize;
int ansSize;

int* t;
int tSize;

void dfs(int* nums, int numsSize, int cur) 
{
    if (cur == numsSize) {
        int* tmp = malloc(sizeof(int) * tSize);
        memcpy(tmp, t, sizeof(int) * tSize);
        ansColSize[ansSize] = tSize;
        ans[ansSize++] = tmp;
        return;
    }
    t[tSize++] = nums[cur];
    dfs(nums, numsSize, cur + 1);
    tSize--;
    dfs(nums, numsSize, cur + 1);
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    ans = malloc(sizeof(int*) * (1 << numsSize));
    ansColSize = malloc(sizeof(int) * (1 << numsSize));
    t = malloc(sizeof(int) * numsSize);
    *returnSize = 1 << numsSize;
    ansSize = 0;
    tSize = 0;
    dfs(nums, numsSize, 0);
    *returnColumnSizes = ansColSize;
    return ans;
}

// 递归，循环，回溯
#define MAXSIZE  20000
int** res;
int resSize;
int* temp;
int tempSize;

void helper(int* nums, int numsSize, int** returnColumnSizes, int startindex) 
{
    res[resSize] = malloc(sizeof(int) * tempSize);
    memcpy(res[resSize], temp, sizeof(int) * tempSize);
    (*returnColumnSizes)[resSize++] = tempSize;
    for (int i = startindex; i < numsSize; i++) {
        temp[tempSize++] = nums[i];
        helper(nums, numsSize, returnColumnSizes, i + 1);
        tempSize--;
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    if (!nums || !numsSize) {
        return nums;
    }

    res = (int**)malloc(sizeof(int*) * MAXSIZE);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAXSIZE);
    temp = (int*)malloc(sizeof(int) * numsSize);
    resSize = 0;
    tempSize = 0;
    helper(nums, numsSize, returnColumnSizes, 0);
    *returnSize = resSize;
    return res; 
}

// 79. 单词搜索
bool _exist(char **board, int row, int col, char *word, int y, int x)
{
    if (*word == '\0') {
        return true;
    }
    if (y < 0 || y >= row || x < 0 || x >= col || *word != board[y][x]) {
        return false;
    }
    board[y][x] = '\0';
    bool result = _exist(board, row, col, word + 1, y, x - 1) ||
                  _exist(board, row, col, word + 1, y - 1, x) ||
                  _exist(board, row, col, word + 1, y, x + 1) ||
                  _exist(board, row, col, word + 1, y + 1, x);
    board[y][x] = *word;
    return result;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardColSize[0]; x++) {
            if (board[y][x] == word[0] && _exist(board, boardSize, boardColSize[0], word, y, x)) {
                return true;
            }
        }
    }
    
    return false;
}



/*
    ⑤ 排序和搜索
        颜色分类
        前K个高频元素
        数组中的第K个最大元素
        寻找峰值
        在拍序数组中查找元素的第一个和最后一个位置
        合并区间
        搜索旋转排序数组
        搜索二维矩阵II
*/
// 75. 颜色分类
#define MAX 3
void sortColors(int* nums, int numsSize)
{
    int count[MAX] = {0, 0, 0};
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    for (int i = 0; i < numsSize; i++) {
        if (i < count[0]) {
            nums[i] = 0;
        } else if (i < count[0] + count[1]) {
            nums[i] = 1;
        } else {
            nums[i] = 2;
        }
    }
    return;
}

// 347. 前 K 个高频元素
typedef struct Hash {
    int key;
    int fre;
    UT_hash_handle hh;
} MyHash;

int Compare(MyHash* a, MyHash* b)
{
    return b->fre - a->fre;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * k);
    *returnSize = 0;

    MyHash* users = NULL;
    MyHash* temp = NULL;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(users, nums + i, temp);
        if (temp == NULL) {
            temp = (MyHash*)malloc(sizeof(MyHash));
            temp->key = nums[i];
            temp->fre = 1;
            HASH_ADD_INT(users, key, temp);
        } else {
            temp->fre++;
        }
    }
    HASH_SORT(users, Compare);
    MyHash* cur = users;
    while (*returnSize < k) {
        ans[(*returnSize)++] = cur->key;
        cur = cur->hh.next;
    }
    return ans;
}

// 215. 数组中的第K个最大元素
int Compare(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), Compare);
    return nums[k - 1];
}

// 162. 寻找峰值
int findPeakElement(int* nums, int numsSize)
{
    if(numsSize == 1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[numsSize-1] > nums[numsSize-2]) return numsSize-1;
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] < nums[i-1] && nums[i-1] > nums[i]) {
            return i-1;
        }
    }
    return -1;
}

// 34. 在排序数组中查找元素的第一个和最后一个位置
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            ans[0] = i;
            break;
        }
    }
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] == target) {
            ans[1] = i;
            break;
        }
    }
    return ans;
}

// 56. 合并区间
int Compare(const void *a, const void *b)
{
    int* aa = *(int**)a;
    int* bb = *(int**)b;
    if (aa[0] == bb[0]) {
        return aa[1] - bb[1];
    }
    return aa[0] - bb[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    int** ans = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);
    *returnSize = 0;
    
    qsort(intervals, intervalsSize, sizeof(int*), Compare);

    ans[*returnSize] = (int*)malloc(sizeof(int) * 2);
    (*returnColumnSizes)[*returnSize] = 2;
    ans[*returnSize][0] = intervals[0][0];
    ans[*returnSize][1] = intervals[0][1];
    (*returnSize)++; 
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] > ans[*returnSize - 1][1]) {
            ans[*returnSize] = (int*)malloc(sizeof(int) * 2);
            (*returnColumnSizes)[*returnSize] = 2;
            ans[*returnSize][0] = intervals[i][0];
            ans[*returnSize][1] = intervals[i][1];
            (*returnSize)++;
        } else {
            ans[*returnSize - 1][1] = fmax(ans[*returnSize - 1][1] , intervals[i][1]);
        }
    }
    return ans;
}

// 33. 搜索旋转排序数组
int search(int* nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

// 240. 搜索二维矩阵 II
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) 
{
    int row = matrixRowSize - 1;
    int col = 0;
    while (row >= 0 && col < matrixColSize) {
        if (target < matrix[row][col]) {
            row--;
        } else if (target > matrix[row][col]) {
            col++;
        } else {
            return true;
        }
    }
    return false;
}



/*
    ⑥ 动态规划
        跳跃游戏
        不同路径
        零钱兑换
        最长上升子序列
*/
// 55. 跳跃游戏
bool canJump(int* nums, int numsSize)
{
    int rightmost = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (i <= rightmost) {
            rightmost = fmax(rightmost, i + nums[i]);
            if (rightmost >= numsSize - 1) {
                return true;
            }
        }
    }
    return false;
}

// 62. 不同路径
int uniquePaths(int m, int n)
{
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n -1];
}

// 322. 零钱兑换
int coinChange(int* coins, int coinsSize, int amount)
{
    int *dp = (int *)malloc(sizeof(int) * (amount + 1));
    for (int i = 0; i < amount + 1; i ++) {
        dp[i] = amount + 1;
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (i >= coins[j]) {
                dp[i] = fmin(dp[i - coins[j]] + 1, dp[i]);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

// 300. 最长递增子序列
int lengthOfLIS(int* nums, int numsSize)
{
    int *dp = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
    }
    int max = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
                max = fmax(dp[i], max);
            }
        }
    }
    return max;
}



/*
    ⑦ 设计问题
        二叉树的序列化与反序列化
        常数时间插入、删除和获取随机元素
*/
// 297. 二叉树的序列化与反序列化
char* serialize(struct TreeNode* root) {
    return  (char *)root;
}

struct TreeNode* deserialize(char* data) {
    return (struct TreeNode *)data;
}

// 380. O(1) 时间插入、删除和获取随机元素
typedef struct {
    int key;
    int pos;
    UT_hash_handle hh;
} DataHash;

/* uthash和数组结构 */
typedef struct {
    DataHash *data;
    int *map;
    int mapLen;
} RandomizedSet;

/** Initialize your data structure here. */

RandomizedSet* randomizedSetCreate() {
    RandomizedSet *obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    obj->data = NULL;
    obj->map  = (int*)malloc(sizeof(int) * 65536);
    obj->mapLen = 0;
    return obj;
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool randomizedSetInsert(RandomizedSet* obj, int val) {
    DataHash *s = NULL;
    HASH_FIND_INT(obj->data, &val, s);
    /* 已经存在, 返回false */
    if (s != NULL) {
        return false;
    }
    /* 将新值插入hash中和map数组中, 记录pos */
    s = (DataHash*)malloc(sizeof(DataHash));
    s->key = val;
    s->pos = obj->mapLen;
    HASH_ADD_INT(obj->data, key, s);
    obj->map[obj->mapLen++] = val;
    return true;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool randomizedSetRemove(RandomizedSet* obj, int val) {
    DataHash *s = NULL;
    DataHash *endNode = NULL;
    HASH_FIND_INT(obj->data, &val, s);
    /* 需要删除的元素不在hash中, 返回false */
    if (s == NULL) {
        return false;
    }
    /* 找到结尾元素, 将map中s的信息改为endNode, 再删除s */
    HASH_FIND_INT(obj->data, &obj->map[obj->mapLen - 1], endNode);
    endNode->pos = s->pos;
    HASH_DEL(obj->data, s);
    obj->map[s->pos] = obj->map[--obj->mapLen];
    return true;
}

/** Get a random element from the set. */
int randomizedSetGetRandom(RandomizedSet* obj) {
    /* 取随机idx进行输出 */
    int idx = rand() % obj->mapLen;
    return obj->map[idx];
}

void randomizedSetFree(RandomizedSet* obj) {
    DataHash *s = NULL;
    DataHash *tmp = NULL;
    free(obj->map);
    HASH_ITER(hh, obj->data, s, tmp) {
        HASH_DEL(obj->data, s);
        free(s);
    }
    free(obj);
}



/*
    ⑧ 数学
        快乐数
        阶乘后的零
        Excel表列序号
        Pow（x,n）
        x的平方根
        两数相除
        分数到小数
*/
// 202. 快乐数
int doHappy(int n)
{
    int ret = 0;
    while (n) {
        ret += (n % 10) * (n % 10);
        n /= 10;
    }
    return ret;
}

bool isHappy(int n)
{
    int fast = n;
    int slow = n;
    do {
        slow = doHappy(slow);
        fast = doHappy(doHappy(fast));
        if (fast == 1) {
            return true;
        }
    } while (fast != slow);

    return false;
}

// 172. 阶乘后的零
int trailingZeroes(int n)
{
    if (n < 2) {
        return 0;
    }

    int count5 = 0;
    for (int i = 2; i <= n; i++) {
        int tmp = i;
        while (tmp % 5 == 0) {
            count5++;
            tmp /= 5;
        }
    }
    return count5;
}

// 171. Excel表列序号
int titleToNumber(char * s){
    int num;
    int ret = 0;
    for(int i = 0; i < strlen(s); i++){
        num = s[i] - 'A' + 1;
        ret = ret * 26 + num;
    }
    return ret;
}

// 50. Pow(x, n)
double myPow(double x, int n){
    return pow(x, n);
}

// 69. x 的平方根
int mySqrt(int x){
    return sqrt(x);
}

// 29. 两数相除
int divide(int dividend, int divisor)
{
    if (divisor != 0) {
        if (dividend == -2147483648 && divisor == -1) {
            return 2147483647;
        }
        return dividend / divisor;
    }
    return -1;
}

// 166. 分数到小数
struct HashMapNode {
    int key;
    int val;
    UT_hash_handle hh;
};

struct HashMapNode* hashMap = NULL;

int hashMapAdd(int key, int val) {
    struct HashMapNode* node;
    HASH_FIND_INT(hashMap, &key, node);
    if(node != NULL){
        return node->val;
    }
    
    node = (struct HashMapNode*)malloc(sizeof(struct HashMapNode));
    node->key = key;
    node->val = val;
    HASH_ADD_INT(hashMap, key, node);
    
    return -1;
}

char * fractionToDecimal(int numerator, int denominator){
    char* buf = (char*)malloc(sizeof(char) * 1024);
    int pos;
    long num = numerator;
    long den = denominator;
    
    num = labs(num);
    den = labs(den);
    if (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0){
        sprintf(buf, "-%ld", num / den);
    } else {
        sprintf(buf, "%ld", num / den);
    }
    
    pos = strlen(buf);
    num = num % den;
    if (num) {
        buf[pos++] = '.';
        int start = -1;
        while (num && (start = hashMapAdd(num, pos)) == -1) {
            buf[pos++] = (num * 10 / den) + '0';
            num = num * 10 % den;
        }
    
        if (start != -1) {
            for (int i = pos++; i > start; i--) {
                buf[i] = buf[i - 1];
            }
            buf[start] = '(';
            buf[pos++] = ')';
        }
    }
    
    buf[pos] = '\0';  
    
    hashMap = NULL;
    return buf;
}



/*
    ⑨ 其他
        两整数之和
        逆波兰表达式求值
        多数元素
        任务调度器
*/
// 371. 两整数之和
int getSum(int a, int b){
    return a + b;
}

// 150. 逆波兰表达式求值
int get_result(char* a, int b, int c)
{
    if (!strcmp(a, "+")) {
        return b + c;
    }
    if (!strcmp(a, "-")) {
        return b - c;
    }
    if (!strcmp(a, "*")) {
        return b * c;
    }
    if (!strcmp(a,"/")) {
        return b / c;
    }
    return 0;
}

int evalRPN(char ** tokens, int tokensSize)
{
    int i = 0;
    int j = 0;
    int* data = (int*)malloc((tokensSize / 2 + 2) * sizeof(int));
    while (j < tokensSize) {
        if (strcmp(tokens[j], "+") && strcmp(tokens[j], "-") && strcmp(tokens[j], "*") && strcmp(tokens[j], "/")) {
            data[i++] = atoi(tokens[j]);
        } else {
            data[i - 2] = get_result(tokens[j], data[i - 2], data[i - 1]);
            i = i - 1;
        }
        j++;
    }
    return data[i - 1];
}

// 169. 多数元素
typedef struct Hash {
    int key;
    int fre;
    UT_hash_handle hh;
} MyHash;

int majorityElement(int* nums, int numsSize)
{
    MyHash* users = NULL;
    MyHash* temp = NULL;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(users, nums + i, temp);
        if (temp == NULL) {
            temp = (MyHash*)malloc(sizeof(MyHash));
            temp->key = nums[i];
            temp->fre = 1;
            HASH_ADD_INT(users, key, temp);
            if (temp->fre > numsSize / 2) {
                return temp->key;
            }
        } else {
            temp->fre++;
            if (temp->fre > numsSize / 2) {
                return temp->key;
            }
        }
    }
    return -1;
}

// 621. 任务调度器
#define SIZE 26
int hash[SIZE];

int leastInterval(char* tasks, int tasksSize, int n)
{
    if (n == 0) {
        return tasksSize;
    }

    memset(hash, 0, SIZE * sizeof(int));

    int max = INT_MIN;
    int maxCount = 0;
    for (int i = 0; i < tasksSize; i++) {
        hash[tasks[i] - 'A']++;
        max = fmax(max, hash[tasks[i] - 'A']);
    }
    for (int i = 0; i < SIZE; i++) {
        if (hash[i] == max) {
            maxCount++;
        }
    }

    int ans = (n + 1) * (max - 1) + maxCount;
    return fmax(ans, tasksSize);
}

```
