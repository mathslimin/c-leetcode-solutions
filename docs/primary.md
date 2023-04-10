```c
/* Leetcode 初级算法篇
    ① 数组
        删除排序数组中的重复项
        买卖股票的最佳时机II
        旋转数组
        存在重复元素
        只出现一次的数字
        两个数组的交集II
        加一
        移动零
        两数之和
        有效的数独
        旋转图像

    ② 字符串
        反转字符串
        整数反转
        字符串中的第一个唯一字符
        有效的字母异位词
        验证回文串
        字符串转换证书（atoi）
        实现strStr()
        外观数列
        最长公共前缀

    ③ 链表
        删除链表中的节点
        删除链表的倒数第N个节点
        反转链表
        合并两个有序链表
        回文链表
        环形链表

    ④ 树
        二叉树的最大深度
        验证二叉搜索树
        对称二叉树
        二叉树的层序遍历
        将有序数组转换为二叉搜索树

    ⑤ 排序和搜索
        合并两个有序数组
        第一个错误的版本

    ⑥ 动态规划
        爬楼梯
        买卖股票的最佳时机
        最大子序和
        打家劫舍

    ⑦ 设计问题
        打乱数组
        最小栈

    ⑧ 数学
        Fizz Buzz
        计数质数
        3的幂
        罗马数字转整数

    ⑨ 其他
        位1的个数
        汉明距离
        颠倒二进制位
        杨辉三角
        有效的括号
        缺失数字
*/

/*
    ① 数组
        删除排序数组中的重复项
        买卖股票的最佳时机II
        旋转数组
        存在重复元素
        只出现一次的数字
        两个数组的交集II
        加一
        移动零
        两数之和
        有效的数独
        旋转图像
*/
// 26. 删除有序数组中的重复项
int removeDuplicates(int* nums, int numsSize)
{
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int index = 1;
    for (int i = 1; i < numsSize; i++) {
        while (i < numsSize && nums[i] == nums[i - 1]) {
            i++;
        }
        if (i < numsSize) {
            nums[index++] = nums[i];
        }
    }
    return index;
}

// 122. 买卖股票的最佳时机 II
int maxProfit(int* prices, int pricesSize)
{
    int profit = 0;
    for (int i = 1; i < pricesSize; i++) {
        profit += (prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0);
    }
    return profit;
}

// 189. 旋转数组
void rotate(int* nums, int numsSize, int k)
{
    int i = 0, j = 0;
    k %= numsSize;
    for (i = 0, j = numsSize - 1 - k; i<j; i++, j--){
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }
    for (i = numsSize - k, j = numsSize - 1; i<j; i++, j--){
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }
    for (i = 0, j = numsSize-1; i<j; i++, j--){
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }
}

// 217. 存在重复元素
typedef struct Hash {
    int key;
    UT_hash_handle hh;
} MyHash;

bool containsDuplicate(int* nums, int numsSize)
{
    MyHash* users = NULL;
    MyHash* temp = NULL;
    for (int i= 0; i < numsSize; i++) {
        HASH_FIND_INT(users, nums + i, temp);
        if (temp == NULL) {
            temp = (MyHash*)malloc(sizeof(MyHash));
            temp->key = nums[i];
            HASH_ADD_INT(users, key, temp);
        } else {
            return true;
        }
    }
    return false;
}

// 136. 只出现一次的数字
// uthash解法
typedef struct Hash {
    int key;
    int fre;
    UT_hash_handle hh;
} MyHash;

int singleNumber(int* nums, int numsSize)
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
        } else {
            temp->fre++;
        }
    }
    for (temp = users; temp != NULL; temp = temp->hh.next) {
        if (temp->fre == 1) {
            return temp->key;
        }
    }
    return -1;
}
// 异或解法
int singleNumber(int* nums, int numsSize)
{
    int ans = nums[0];
    for (int i = 1; i < numsSize; i++) {
        ans ^= nums[i];
    }
    return ans;
}

// 350. 两个数组的交集 II
int Compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    qsort(nums1, nums1Size, sizeof(int), Compare);
    qsort(nums2, nums2Size, sizeof(int), Compare);

    int* ans = (int*)malloc(sizeof(int) * fmax(nums1Size, nums2Size));
    *returnSize = 0;
    int index1 = 0;
    int index2 = 0;

    while (index1 < nums1Size && index2 < nums2Size) {
        if (nums1[index1] == nums2[index2]) {
            ans[(*returnSize)++] = nums1[index1];
            index1++;
            index2++;
        } else if (nums1[index1] < nums2[index2]) {
            index1++;
        } else if (nums1[index1] > nums2[index2]) {
            index2++;
        }
    }
    return ans;
}

// 66. 加一
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i] = digits[i] + 1;
            *returnSize = digitsSize;
            return digits;
        }
    }

    // 全部为9的情况
    *returnSize = digitsSize + 1;
    int *ret = (int*)calloc(digitsSize + 1, sizeof(int));
    ret[0] = 1;
    return ret;
}

// 283. 移动零
void moveZeroes(int* nums, int numsSize)
{
    int countZero = 0;
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            countZero++;
        } else {
            nums[index++] = nums[i];
        }
    }
    for (int i = 0; i < countZero; i++) {
        nums[index++] = 0;
    }
    return;
}

// 1. 两数之和
typedef struct {
    int key;
    int index;
    UT_hash_handle hh;
} MyHash;

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    MyHash* users = NULL;
    MyHash* temp = (MyHash*)malloc(sizeof(MyHash));
    temp->key = nums[0];
    temp->index = 0;
    HASH_ADD_INT(users, key, temp);
    for (int i = 1; i < numsSize; i++) {
        int number = target - nums[i];
        MyHash* tmp = NULL;
        HASH_FIND_INT(users, &number, tmp);
        if (tmp != NULL) {
            ans[0] = tmp->index;
            ans[1] = i;
            return ans;
        }
        HASH_FIND_INT(users, nums + i, tmp);
        if (tmp == NULL) {
            tmp = (MyHash*)malloc(sizeof(MyHash));
            tmp->key = nums[i];
            tmp->index = i;
            HASH_ADD_INT(users, key, tmp);
        }
    }
    return ans;
}

// 36. 有效的数独
bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int rows[9][9];
    int columns[9][9];
    int boxes[9][9];
    int i, j, m, n;
    memset(rows, 0, sizeof(rows));
    memset(columns, 0, sizeof(columns));
    memset(boxes, 0, sizeof(boxes));
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            m = i / 3 * 3 + j / 3;
            n = (int)board[i][j] - '1';
            if (rows[i][n] == 0) {
                rows[i][n] = 1;
            } else {
                return false;
            }
            if (columns[j][n] == 0) {
                columns[j][n] = 1;
            } else {
                return false;
            }
            if (boxes[m][n] == 0) {
                boxes[m][n] = 1;
            } else {
                return false;
            }
        }
    }
    return true;
}

// 48. 旋转图像
void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    for(int row = 1; row < matrixSize; row++){
        for(int col = 0; col < row; col++){
            swap(&matrix[row][col], &matrix[col][row]);
        }
    }
    for(int col = 0; col < (*matrixColSize) / 2; col++){
        for(int row = 0; row < matrixSize; row++){
            swap(&matrix[row][col], &matrix[row][(*matrixColSize) - 1 - col]);
        }
    }
}



/*
    ② 字符串
        反转字符串
        整数反转
        字符串中的第一个唯一字符
        有效的字母异位词
        验证回文串
        字符串转换证书（atoi）
        实现strStr()
        外观数列
        最长公共前缀
*/
// 344. 反转字符串
void reverseString(char* s, int sSize)
{
    for (int i = 0; i < sSize / 2; i++) {
        char ch = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = ch;
    }
    return s;
}

// 7. 整数反转
int reverse(int x)
{
    long ans = 0;
    while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
}

// 387. 字符串中的第一个唯一字符
#define SIZE 26
int firstUniqChar(char * s)
{
    int* alpha = (int*)calloc(SIZE, sizeof(int));
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        alpha[s[i] - 'a']++;
    }
    for (int i = 0; i < len; i++) {
        if (alpha[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}

// 242. 有效的字母异位词
#define MAX 26
bool isAnagram(char * s, char * t)
{
    int lenS = strlen(s);
    int lenT = strlen(t);
    if (lenS != lenT) {
        return false;
    }

    int* alphaS = (int*)calloc(MAX, sizeof(int));
    int* alphaT = (int*)calloc(MAX, sizeof(int));
    for (int i = 0; i < lenS; i++) {
        alphaS[s[i] - 'a']++;
        alphaT[t[i] - 'a']++;
    }
    for (int i = 0; i < MAX; i++) {
        if (alphaS[i] != alphaT[i]) {
            return false;
        }
    }
    return true;
}

// 125. 验证回文串
bool isPalindrome(char * s)
{
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        if (!isalnum(s[left])) {
            left++;
            continue;
        }
        if (!isalnum(s[right])) {
            right--;
            continue;
        }
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// 8. 字符串转换整数 (atoi)
int myAtoi(char* str)
{
    int len = strlen(str);
    int sign = 1;
    double sum = 0;
    for (int i = 0; i < len; i++) {
        if (str[i]==' ') {
            continue;
        } else if (str[i] == '+' && isdigit(str[i + 1])) {
            continue;
        } else if (str[i] == '-' && isdigit(str[i + 1])) {
            sign = -1;
            continue;
        }
        if (isdigit(str[i])) {
            while (isdigit(str[i])) {
                sum = sum * 10 + str[i] - '0';
                i++;
            }
            if (sum * sign >= INT_MAX) { 
                return INT_MAX;
            } else if (sum * sign <= INT_MIN) { 
                return INT_MIN;
            }
            return sum * sign;
        } else {
            return 0;
        }
    }

    return sum * sign;
}

// 28. 实现 strStr()
int strStr(char* haystack, char* needle) 
{
    int n = strlen(haystack);
    int m = strlen(needle);
    for (int i = 0; i + m <= n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}

// 38. 外观数列
char s[5000] = {0};
char s1[5000] = {0};

char* countAndSay(int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char count;
    memset(s, 0, 5000);
    memset(s1, 0, 5000);
    s[0] = '1';
    
    while (i < n - 1) {
        j = 0;
        k = 0;
        count = 1;
        int len = strlen(s);
        while (j < len) {
            if (s[j] == s[j+1]) {
                count++;
            } else {
                s1[k] = count + '0';
                s1[k + 1] = s[j];
                count = 1;
                k = k + 2;
            }
            j++;
        }
        s1[k] = '\0';
        memcpy(s, s1, strlen(s1));
        i++;
    }
    return s;
}

// 14. 最长公共前缀
#define MAX 201
char * longestCommonPrefix(char ** strs, int strsSize)
{
    int size = 0;
    char *ans = (char*)malloc(sizeof(char) * MAX);

    if (strs == NULL || strsSize == 0) {
        ans[size] = '\0';
        return ans;
    }

    int col = MAX;
    for (int i = 0; i < strsSize; i++) {
        col = fmin(strlen(strs[i]), col);
    }

    for (int j = 0; j < col; j++) {
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][j] != strs[i - 1][j]) {
                ans[size] = '\0';
                return ans;
            }
        }
        ans[size++] = strs[strsSize - 1][j];
    }
    ans[size] = '\0';
    return ans;
}

/*
    ③ 链表
        删除链表中的节点
        删除链表的倒数第N个节点
        反转链表
        合并两个有序链表
        回文链表
        环形链表
*/
// 237. 删除链表中的节点
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

// 19. 删除链表的倒数第 N 个结点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    for (int i = 0; i < n; i++) {
        if (fast->next) {
            fast = fast->next;
        } else {
            return head->next;
        }
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}

// 206. 反转链表
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 21. 合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    } else if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// 234. 回文链表
#define MAX 100001
bool isPalindrome(struct ListNode* head) 
{
    int vals[MAX];
    int index = 0;
    while (head != NULL) {
        vals[index++] = head->val;
        head = head->next;
    }
    for (int i = 0, j = index - 1; i < j; ++i, --j) {
        if (vals[i] != vals[j]) {
            return false;
        }
    }
    return true;
}

// 141. 环形链表
typedef struct hashTable {
    struct ListNode* key;
    UT_hash_handle hh;
} MyHash;

MyHash *hashtable = NULL;

struct ListNode* hasCycle(struct ListNode* head) 
{
    struct ListNode *iter = head;
    while (iter != NULL) {
        struct hashTable* tmp;
        HASH_FIND_PTR(hashtable, &iter, tmp);
        if (tmp != NULL) {
            return iter;
        }
        MyHash *cur = malloc(sizeof(MyHash));
        cur->key = iter;
        HASH_ADD_PTR(hashtable, key, cur);
        iter = iter->next;
    }
    return false;
}



/*
    ④ 树
        二叉树的最大深度
        验证二叉搜索树
        对称二叉树
        二叉树的层序遍历
        将有序数组转换为二叉搜索树
*/
// 104. 二叉树的最大深度
// 递归解法
int maxDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    return fmax(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
}
// 队列解法
#define MAX 10000
int maxDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }

    struct TreeNode* queue[MAX];
    int head = 0;
    int tail = 0;
    queue[tail++] = root;
    int ans = 0;

    while (head != tail) {
        ans++;
        int size = tail - head;
        for (int i = 0; i < size; i++) {
            if (queue[head]->left) {
                queue[tail++] = queue[head]->left;
            }
            if (queue[head]->right) {
                queue[tail++] = queue[head]->right;
            }
            head++;
        }
    }
    return ans;
}

// 98. 验证二叉搜索树
#define MAX 10000
void InOrder(struct TreeNode* root, int* arr, int *size)
{
    if (root) {
        InOrder(root->left, arr, size);
        arr[(*size)++] = root->val;
        InOrder(root->right, arr, size);
    }
}

bool isValidBST(struct TreeNode* root)
{
    int arr[MAX];
    int size = 0;
    InOrder(root, arr, &size);
    for (int i = 1; i < size; i++) {
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// 101. 对称二叉树
bool isSym(struct TreeNode *left, struct TreeNode *right) 
{
    if (!left && !right) {
        return true;
    }
    if (left && !right || !left && right || left->val != right->val) {
        return false;
    }
    return isSym(left->left, right->right) && isSym(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (!root) {
        return true;
    }
    return isSym(root->left, root->right);
}

// 102. 二叉树的层序遍历
#define MAX 2000
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    *returnSize = 0;
    int** ans = (int**)malloc(sizeof(int*) * MAX);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX);

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
    return ans;
}

// 108. 将有序数组转换为二叉搜索树
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if ((NULL == nums) || (numsSize == 0)) {
        return NULL;
    }
    int iRoot = 0;
    struct TreeNode* pCurNode = NULL;
    pCurNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    iRoot = numsSize / 2;
    pCurNode->val = nums[iRoot];
    pCurNode->left = sortedArrayToBST(&nums[0], iRoot);
    pCurNode->right = sortedArrayToBST(&nums[iRoot + 1], numsSize - 1 - iRoot);
    return pCurNode;
}



/*
    ⑤ 排序和搜索
        合并两个有序数组
        第一个错误的版本
*/
// 88. 合并两个有序数组
// qsort排序
int Compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    for (int i = 0; i < n; i++) {
        nums1[m + i] = nums2[i];
    }
    qsort(nums1, m + n, sizeof(int), Compare);
    return;
}
// 双指针
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    int p1 = 0, p2 = 0;
    int sorted[m + n];
    int cur;
    while (p1 < m || p2 < n) {
        if (p1 == m) {
            cur = nums2[p2++];
        } else if (p2 == n) {
            cur = nums1[p1++];
        } else if (nums1[p1] < nums2[p2]) {
            cur = nums1[p1++];
        } else {
            cur = nums2[p2++];
        }
        sorted[p1 + p2 - 1] = cur;
    }
    for (int i = 0; i != m + n; ++i) {
        nums1[i] = sorted[i];
    }
}

// 278. 第一个错误的版本
int firstBadVersion(int n) 
{
    int left = 1;
    int right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}



/*
    ⑥ 动态规划
        爬楼梯
        买卖股票的最佳时机
        最大子序和
        打家劫舍
*/
// 70. 爬楼梯
int climbStairs(int n)
{
    if (n <= 2) {
        return n;
    }
    int dp1 = 1;
    int dp2 = 2;
    int ans;
    for (int i = 1; i <= n - 2; i++) {
        ans = dp1 + dp2;
        dp1 = dp2;
        dp2 = ans;
    }
    return ans;
}

// 121. 买卖股票的最佳时机
int maxProfit(int* prices, int pricesSize)
{
    int max = 0;
    int minIndex = 0;
    for (int i = 1; i < pricesSize; i++) {
        minIndex = (prices[i] < prices[minIndex]) ? i : minIndex;
        max = fmax(max, prices[i] - prices[minIndex]);
    }
    return max;
}

// 53. 最大子序和
int maxSubArray(int* nums, int numsSize)
{
    int tmp = nums[0];
    int max = tmp; 
    for (int i = 1; i < numsSize; i++) {
        tmp = fmax(nums[i], tmp + nums[i]);
        max = fmax(max, tmp);
    }
    return max;
}

// 198. 打家劫舍
int rob(int* nums, int numsSize)
{
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    if (numsSize == 2) {
        return fmax(nums[0], nums[1]);
    }

    int dp1 = nums[0];
    int dp2 = fmax(nums[0], nums[1]);
    int sum = 0;
    for (int i = 2; i < numsSize; i++) {
        sum = fmax(nums[i] + dp1, dp2);
        dp1 = dp2;
        dp2 = sum;
    }
    return sum;
}



/*
    ⑦ 设计问题
        打乱数组
        最小栈
*/
// 384. 打乱数组
#include <time.h>

typedef struct {
    int *array;
    int *origin;
    int size;
} Solution;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int randomInt(int min, int max){
    int ret = rand() % (max - min + 1) + min;
    return ret;
}

Solution* solutionCreate(int* nums, int numsSize) {
    Solution *new = malloc(sizeof(Solution));
    new->size = numsSize;
    new->array = malloc(sizeof(int) * numsSize);
    new->origin = malloc(sizeof(int) * numsSize);
    for(int i = 0; i <  numsSize; i++){
        new->array[i] = nums[i];
        new->origin[i] = nums[i];
    }
    return new;
}

int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->size;
    for(int i = 0; i < *retSize; i++){
        obj->array[i] = obj->origin[i];
    }
    return obj->array;
}

int* solutionShuffle(Solution* obj, int* retSize) {
    *retSize = obj->size;
    int swapIndex;
    //srand(time(NULL));
    for(int i = 0; i < *retSize; i++){
        swapIndex = randomInt(i, *retSize - 1);
        swap(&(obj->array[i]), &(obj->array[swapIndex]));
    }
    return obj->array;
}

void solutionFree(Solution* obj) {
    free(obj->array);
    free(obj->origin);
    free(obj);
    return;
}

// 155. 最小栈
#define MAX 10000
typedef struct {
    int stack[MAX];
    int top;

    int minstack[MAX];
    int mintop;
} MinStack;

MinStack* minStackCreate() {
    MinStack *obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    obj->mintop = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->stack[++obj->top] = val;
    if (obj->mintop == -1 || val <= obj->minstack[obj->mintop]) {
        obj->minstack[++obj->mintop] = val;
    }
    return;
}

void minStackPop(MinStack* obj) {
    if (obj->stack[obj->top] == obj->minstack[obj->mintop]) {
        obj->mintop--;
    }
    obj->top--;
    return;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minstack[obj->mintop];
}

void minStackFree(MinStack* obj) {
    free(obj);
    return;
}



/*
    ⑧ 数学
        Fizz Buzz
        计数质数
        3的幂
        罗马数字转整数
*/
// 412. Fizz Buzz
char** fizzBuzz(int n, int* returnSize)
{
    char* fizz = malloc(5);
    char* buzz = malloc(5);
    char* fizzbuzz = malloc(9);
    sprintf(fizz, "%s", "Fizz");
    sprintf(buzz, "%s", "Buzz");
    sprintf(fizzbuzz, "%s", "FizzBuzz");
    char** res = (char**)malloc(sizeof(char*) * n);
    *returnSize = n;
    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) {   
            res[i - 1] = fizzbuzz;
        } else if (i % 5 == 0) { 
            res[i - 1] = buzz;
        } else if (i % 3 == 0) { 
            res[i - 1] = fizz;
        } else {
            res[i - 1] = malloc(10);
            sprintf(res[i - 1], "%d", i);
        }
    }
    return res;
}

// 204. 计数质数
int countPrimes(int n) 
{
    if (n < 2) {
        return 0;
    }
    int isPrime[n];
    int primes[n], primesSize = 0;
    memset(isPrime, 0, sizeof(isPrime));
    for (int i = 2; i < n; ++i) {
        if (!isPrime[i]) {
            primes[primesSize++] = i;
        }
        for (int j = 0; j < primesSize && i * primes[j] < n; ++j) {
            isPrime[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    return primesSize;
}

// 326. 3的幂
bool isPowerOfThree(int n)
{
    if (n < 1) {
        return false;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

// 13. 罗马数字转整数
int romanToInt(char * s)
{
    int hashmap[26] = {0};
        hashmap['I'-'A'] = 1;
        hashmap['V'-'A'] = 5;
        hashmap['X'-'A'] = 10;
        hashmap['L'-'A'] = 50;
        hashmap['C'-'A'] = 100;
        hashmap['D'-'A'] = 500;
        hashmap['M'-'A'] = 1000;
    int previous = 0;
    int sum = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (previous < hashmap[s[i] - 'A']) {
            sum -= previous *  2;
        }
        sum += (previous = hashmap[s[i] - 'A']);
    }
    return sum;
}

/*
    ⑨ 其他
        位1的个数
        汉明距离
        颠倒二进制位
        杨辉三角
        有效的括号
        缺失数字
*/
// 191. 位1的个数
int hammingWeight(uint32_t n) 
{
    int count = 0;
    while (n) {
        count += n & 1;
        n = n >> 1;
    }
    return count;
}

// 461. 汉明距离
int hammingDistance(int x, int y)
{
    int n = x ^ y;
    int c = 0;
    while (n) {
        c += n & 1;
        n >>= 1;
    }
    return c;
}

// 190. 颠倒二进制位
uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for (int i = 0; i < 32 && n > 0; ++i) {
        rev |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return rev;
}

// 118. 杨辉三角
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int** ans = (int**)malloc(sizeof(int*) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++) {
        ans[i] = (int*)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                ans[i][j] = 1;
            } else {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
    }
    return ans;
}

// 20. 有效的括号
bool isValid(char * s)
{
    int len = strlen(s);
    char *stack = (char*)malloc(sizeof(char) * len);
    int  top = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[top++] = s[i];
            continue;
        }
        if (s[i] == ')' && top > 0 && stack[top - 1] == '(') {
            top--;
            continue;
        }
        if (s[i] == ']' && top > 0 && stack[top - 1] == '[') {
            top--;
            continue;
        }
        if (s[i] == '}' && top > 0 && stack[top - 1] == '{') {
            top--;
            continue;
        }
        return false;
    }
    return (!top);
}

// 剑指 Offer 53 - II. 0～n中缺失的数字
int Compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;    
}

int missingNumber(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), Compare);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i) {
            return i;
        }
    }
    return numsSize;
}

```
