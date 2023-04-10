```c
/* Leetcode 高级算法篇
    ① 数组与字符串
        除自身以外数组的乘积
        螺旋矩阵
        四数相加II
        盛最多水的容器
        生命游戏
        缺失的第一个正数
        最长连续序列
        寻找重复数
        基本计算器II
        滑动窗口最大值
        最小覆盖子串

    ② 链表
        合并K个排序链表
        排序链表
        复制带随机指针的链表

    ③ 树和图
        单词接龙
        被围绕的区域
        二叉树的最近公共祖先
        二叉树中的最大路径和
        朋友圈
        课程表
        课程表II
        矩阵中的最长递增路径
        计算右侧小于当前元素的个数

    ④ 回溯算法
        分割回文串
        单词搜索II
        删除无效的括号
        通配符匹配
        正则表达式匹配

    ⑤ 排序和搜索
        摆动排序II
        有序矩阵中第K小的元素
        寻找两个正序数组的中位数

    ⑥ 动态规划
        乘积最大子数组
        最佳买卖股票时机含冷冻期
        完全平方数
        单词拆分
        单词拆分II
        戳气球

    ⑦ 设计问题
        LRU缓存机制
        实现Trie(前缀树)
        扁平化嵌套列表迭代器
        数据流中的中位数

    ⑧ 数学
        最大数
        直线上最多的点数

    ⑨ 其他
        根据身高队列重建队列
        接雨水
        天际线问题
        柱状图中最大的矩形
*/

/*
    ① 数组与字符串
        除自身以外数组的乘积
        螺旋矩阵
        四数相加II
        盛最多水的容器
        生命游戏
        缺失的第一个正数
        最长连续序列
        寻找重复数
        基本计算器II
        滑动窗口最大值
        最小覆盖子串
*/
// 238. 除自身以外数组的乘积
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    int* head = (int*)malloc(sizeof(int) * numsSize);
    int* tail = (int*)malloc(sizeof(int) * numsSize);
    head[0] = 1;
    tail[numsSize - 1] = 1;

    for (int i = 1; i < numsSize; i++) {
        head[i] = head[i - 1] * nums[i - 1];
    }
    for (int i = numsSize - 2; i >= 0; i--) {
        tail[i] = tail[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < numsSize; i++) {
        ans[i] = head[i] * tail[i];
    }

    *returnSize = numsSize;
    return ans;
}

// 54. 螺旋矩阵
#define INVALID 101
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int row = matrixSize;
    int col = *matrixColSize;

    *returnSize = row * col;
    int* ans = (int*)malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        ans[i] = INVALID;
    }

    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int direct = 0;
    int count = 0;
    int x = 0;
    int y = 0;
    while (count < *returnSize) {
        ans[count++] = matrix[x][y];
        matrix[x][y] = INVALID;
        int nextX = x + direction[direct][0];
        int nextY = y + direction[direct][1];
        if (nextX < 0 || nextX >= row || 
            nextY < 0 || nextY >= col || matrix[nextX][nextY] == INVALID) {
            direct = (direct + 1) % 4;
        }
        x += direction[direct][0];
        y += direction[direct][1];
    }
    return ans;
}

// 454. 四数相加 II
typedef struct HashTable {
    int key;
    int val;
    UT_hash_handle hh;
} MyHash;

int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size)
{
    int ans = 0;
    MyHash* users = NULL;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            MyHash* tmp = NULL;
            int key1 = nums1[i] + nums2[j];
            HASH_FIND_INT(users, &key1, tmp);
            if (tmp == NULL) {
                MyHash* cur = (MyHash*)malloc(sizeof(MyHash));
                cur->key = key1;
                cur->val = 1;
                HASH_ADD_INT(users, key, cur);
            } else {
                tmp->val++;
            }
        }
    }

    for (int i = 0; i < nums3Size; i++) {
        for (int j = 0; j < nums4Size; j++) {
            MyHash* tmp = NULL;
            int key2 = - nums3[i] - nums4[j];
            HASH_FIND_INT(users, &key2, tmp);
            if (tmp != NULL) {
                ans += tmp->val;
            }
        }
    }
    return ans;
}

// 11. 盛最多水的容器
int maxArea(int* height, int heightSize)
{
    int ans = 0;
    int l = 0;
    int r = heightSize - 1;
    while (l < r) {
        int area = fmin(height[l], height[r]) * (r - l);
        ans = fmax(ans, area);
        if (height[l] <= height[r]) {
            l++;
        } else {
            r--;
        }
    }
    return ans;
}

// 289. 生命游戏
#define ROW 8
#define COL 2
int direction[ROW][COL] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

int GetAlive(int** board, int row, int col, int x, int y)
{
    int countAlive = 0;
    for (int i = 0; i < ROW; i++) {
        int newX = x + direction[i][0];
        int newY = y + direction[i][1];
        if (newX < 0 || newX >= row || newY < 0 || newY >= col) {
            continue;
        } else {
            if (board[newX][newY] == 1) {
                countAlive++;
            }
        }
    }
    if (board[x][y] == 1) {
        if (countAlive == 2 || countAlive == 3) {
            return 1;
        }
        return 0;
    } else if (board[x][y] == 0) {
        if (countAlive == 3) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void gameOfLife(int** board, int boardSize, int* boardColSize)
{
    int** temp = (int**)malloc(sizeof(int*) * boardSize);
    for (int i = 0; i < boardSize; i++) {
        temp[i] = (int*)malloc(sizeof(int) * *boardColSize);
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            temp[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            temp[i][j] = GetAlive(board, boardSize, *boardColSize, i, j);
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            board[i][j] = temp[i][j];
        }
    }

    free(temp);
    return;
}

// 41. 缺失的第一个正数
typedef struct HashTable {
    int key;
    UT_hash_handle hh;
} MyHash;

int firstMissingPositive(int* nums, int numsSize)
{
    MyHash* users = NULL;
    for (int i = 0; i < numsSize; i++) {
        MyHash* temp = NULL;
        HASH_FIND_INT(users, nums + i, temp);
        if (temp == NULL) {
            MyHash* cur = (MyHash*)malloc(sizeof(MyHash));
            cur->key = nums[i];
            HASH_ADD_INT(users, key, cur); 
        }
    }

    for (int i = 1; i < INT_MAX; i++) {
        int target = i;
        MyHash* tmp = NULL;
        HASH_FIND_INT(users, &target, tmp);
        if (tmp == NULL) {
            return i;
        }
    }
    return -1;
}

// 128. 最长连续序列
int Compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int longestConsecutive(int* nums, int numsSize)
{
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), Compare);
    int* array = (int*)malloc(sizeof(int) * numsSize);
    int index = 0;
    array[index++] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        while (i < numsSize && nums[i] == nums[i - 1]) {
            i++;
        }
        if (i < numsSize) {
            array[index++] = nums[i];
        }
    }

    int maxLen = 1;
    for (int i = 0; i < index; i++) {
        int tmpLen = 1;
        while (i + 1 < index && array[i + 1] == array[i] + 1) {
            tmpLen++;
            maxLen = fmax(maxLen, tmpLen);
            i++;
        }
    }
    return maxLen;
}

// 287. 寻找重复数
// 法1：uthash
typedef struct HashTable {
    int key;
    UT_hash_handle hh;
} MyHash;

int findDuplicate(int* nums, int numsSize)
{
    MyHash* users = NULL;
    for (int i = 0; i < numsSize; i++) {
        MyHash* tmp = NULL;
        HASH_FIND_INT(users, nums + i, tmp);
        if (tmp == NULL) {
            MyHash* cur = (MyHash*)malloc(sizeof(MyHash));
            cur->key = nums[i];
            HASH_ADD_INT(users, key, cur);
        } else {
            return nums[i];
        }
    }
    return -1;
}

// 法2：快慢指针
int findDuplicate(int* nums, int numsSize)
{
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

// 227. 基本计算器 II
int calculate(char * s)
{
    int len = strlen(s);
    int stack[len];
    int top = 0;
    long ans = 0;
    long num = 0;
    char sign = '+';
    for (int i = 0; i <= len; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        } else {
            if (s[i] == ' ') {
                continue;
            }
            if (sign == '+') {
                stack[top++] = num;
            } else if (sign == '-') {
                stack[top++] = -num;
            } else if (sign == '*') {
                stack[top - 1] *= num;
            } else if (sign == '/') {
                stack[top - 1] /= num;
            }
            sign = s[i];
            num = 0;
        }
    }
    while (top > 0) {
        ans += stack[--top];
    }
    return ans;
}

// 239. 滑动窗口最大值
int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize) 
{
    if (nums == NULL || returnSize == NULL) {
        return NULL;
    }

    int* result = (int *)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = numsSize - k + 1;
    
    int* deque = (int *)malloc(sizeof(int) * numsSize);
    int head = 0;
    int tail = 0;
    for (int i = 0; i < numsSize; i++) {
        while (head != tail && nums[i] > nums[deque[tail - 1]]) {
            tail--;
        }
        deque[tail++] = i;
        if (i >= k - 1) {
            result[i - k + 1] = nums[deque[head]];
            if (head != tail && deque[head] <= i - k + 1) {
                head++;
            }
        }
    }

    free(deque);
    return result;
}

// 76. 最小覆盖子串
#define CHAR_NUM 128
int sMap[CHAR_NUM];
int tMap[CHAR_NUM];

char *minWindow(char *s, char *t)
{
    char* ans = "";
    if (s == NULL || t == NULL) {
        return ans; 
    }

    int sLen = strlen(s);
    int tLen = strlen(t);
    if (sLen < tLen) {
        return ans;
    } 

    memset(sMap, 0, sizeof(int) * CHAR_NUM);
    memset(tMap, 0, sizeof(int) * CHAR_NUM);
    for (int i = 0; i < tLen; i++) {
        sMap[s[i]]++;
        tMap[t[i]]++;
    }
    int left = 0; 
    int right = tLen;
    int start = 0;
    int len = INT_MAX; 
    while (right <= sLen) { 
        bool included = true;   
        if (right - left < tLen) {
            included = false;
        } else {
            for (int i = 0; i < CHAR_NUM; i++) {
                if (sMap[i] < tMap[i]) {
                    included = false;
                    break;
                }
            }
        }
        if (included) {
            if (len > right - left) {
                len = right - left;
                start = left;
            }
            sMap[s[left]]--;
            left++;
        } else {
            sMap[s[right]]++;
            right++;
        }
    }

    if (len == INT_MAX) { 
        return ans;
    } else {
        ans = (char*)calloc(len + 1, sizeof(char));
        strncpy(ans, s + start, len);
        return ans;
    }   
}



/*
    ② 链表
        合并K个排序链表
        排序链表
        复制带随机指针的链表
*/
// 23. 合并K个升序链表
#define MAX 10001
int arr[MAX];
int Compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    int size = 0;
    for (int i = 0; i < listsSize; i++) {
        struct ListNode *tmp = lists[i];
        while (tmp) {
            arr[size++] = tmp->val;
            tmp = tmp->next;
        }
    }
    qsort(arr, size, sizeof(int), Compare);

    struct ListNode *ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    ans->val = arr[0];
    ans->next = NULL;
    if (size == 0) {
        return NULL;
    }
    if (size == 1) {
        return ans;
    }

    struct ListNode *head = ans;
    for (int i = 1; i < size; i++) {
        struct ListNode *cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->val = arr[i];
        cur->next = NULL;
        head->next = cur;
        head = cur;
    }
    return ans;
}

// 148. 排序链表
#define MAX 50001
int temp[MAX];
int Compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

struct ListNode* sortList(struct ListNode* head)
{
    int size = 0;
    struct ListNode* cur = head;
    while (cur) {
        temp[size++] = cur->val;
        cur = cur->next;
    }
    qsort(temp, size, sizeof(int), Compare);
    cur = head;
    int i = 0;
    while (cur) {
        cur->val = temp[i++];
        cur = cur->next;
    }
    return head;
}

// 138. 复制带随机指针的链表
struct HashNode {
    void* key;
    void* index;
    UT_hash_handle hh;
};

struct HashNode *g_user = NULL;

void add_user(void* key, void* index){
    struct HashNode *s = NULL;
    HASH_FIND_PTR(g_user, &key, s);
    if (s == NULL){
        s = (struct HashNode*)malloc(sizeof(struct HashNode));
        s->key = key;
        s->index = index;
        HASH_ADD_PTR(g_user, key, s);
    }
    return;
}

struct HashNode *find_user(void *key){
    struct HashNode *t = NULL;
    HASH_FIND_PTR(g_user, &key, t);
    return t;
}

struct Node* copyRandomList(struct Node* head) {

    struct Node *p = head;
    struct Node *pb = NULL;
    if (head == NULL){
        return NULL;
    }
    //初始化拷贝链表的头节点
    struct Node *res = (struct Node*)malloc(sizeof(struct Node));
    res->val = head->val;
    res->next = NULL;
    res->random = NULL;
    p = head->next;
    pb = res;
    //拷贝链表的建立，所有random节点先置为NULL，同时建立一个哈希表，用于映射新老链表相同index位置节点的指针
    add_user((void *)head, (void *)res);
    while (p) {
        //创建临时节点储存当前head链表的子节点
        struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->next = NULL;
        tmp->val = p->val;
        tmp->random = NULL;
        //将处理好的临时节点挂到拷贝链表上
        pb->next = tmp;
        //将新老链表的同位置节点映射到哈希表
        add_user((void *)p, (void *)tmp);
        //拷贝链表和head链表同时进一步
        pb = pb->next;
        p = p->next;
    }
    //处理拷贝链表中的random节点
    pb = res;
    p = head;
    while(pb){
        struct HashNode *tmpHash = NULL;
        //若head链表中的random节点不为空，则哈希表找到该节点在新链表中对应的新节点地址
        if (p->random){
            tmpHash = find_user((void *)p->random);
            pb->random = (struct Node*)tmpHash->index;
        }
        //后移一个节点
        p = p->next;
        pb = pb->next;
    }
    return res;
}



/*
    ③ 树和图
        单词接龙
        被围绕的区域
        二叉树的最近公共祖先
        二叉树中的最大路径和
        朋友圈
        课程表
        课程表II
        矩阵中的最长递增路径
        计算右侧小于当前元素的个数
*/
// 127. 单词接龙
bool IsNeighborNode(char *one, char *two)
{
    int countDiff = 0;
    int len = strlen(one);
    for (int i = 0; i < len; i++) {
        if (one[i] == two[i]) {
            continue;
        }
        countDiff++;
        if (countDiff > 1) {
            break;
        }
    }
    return countDiff == 1 ? true : false;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize)
{
    if (beginWord == NULL || endWord == NULL || wordList == NULL || wordListSize == 0) {
        return 0;
    }

    int destId = wordListSize;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(endWord, wordList[i]) == 0) {
            destId = i;
            break;
        }
    }
    if (destId == wordListSize) {
        return 0;
    }

    int sourceId = wordListSize;
    int nodeSize = wordListSize + 1;
    int* visit = (int*)calloc(nodeSize, sizeof(int));
    int* queue = (int*)malloc(sizeof(int) * nodeSize);
    int head = 0;
    int tail = 0;
    int step = 1;

    queue[tail++] = sourceId;
    while (head != tail) {
        int size = tail - head;
        for (int i = 0; i < size; i++) {
            int curId = queue[head++];
            if (curId == destId) {
                return step;
            }
            char* curWord = (curId == sourceId) ? beginWord : wordList[curId];
            for (int i = 0; i < wordListSize; i++) { 
                if (visit[i] == 1 || IsNeighborNode(curWord, wordList[i]) == false) {
                    continue;
                }
                visit[i] = 1;
                queue[tail++] = i;
            }
        }
        step++;
    }
    return 0;
}

// 130. 被围绕的区域
// 法1：DFS解法
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(char** board, int row, int col, int x, int y)
{
    if (x < 0 || x >= row || y < 0 || y >= col) {
        return;
    }
    if (board[x][y] == 'X') {
        return;
    }
    if (board[x][y] == 'O') {
        board[x][y] = 'A';
        for (int i = 0; i < 4; i++) {
            DFS(board, row, col, x + direction[i][0], y + direction[i][1]);
        }
    }
}

void solve(char** board, int boardSize, int* boardColSize)
{
    int row = boardSize;
    int col = *boardColSize;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'O' && (i == 0 || i == row - 1 || j == 0 || j == col - 1)) {
                DFS(board, row, col, i, j);
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'A' ) {
                board[i][j] = 'O';
            } else {
                board[i][j] = 'X';
            }
        }
    }
    return;
}

// 法2：BFS
#define DIRECT_NUM 4
#define MAX_N 1000
typedef struct tagPosition {
    int x;
    int y;
}Position;

void Bfs(char **board, int boardSize, int boardColSize, int x, int y, bool isBianJie)
{
    Position queue[MAX_N * MAX_N];
    bool visited[MAX_N][MAX_N] = { { false} };
    int head, tail, curX, curY, i;
    int direct[DIRECT_NUM][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    head = 0;
    tail = 0;
    queue[tail].x = x;
    queue[tail].y = y;
    tail++;
    visited[x][y] = true;
    while (head < tail) {
        for (i = 0; i < DIRECT_NUM; ++i) {
            curX = queue[head].x + direct[i][0];
            curY = queue[head].y + direct[i][1];
            if (!(curX >= 0 && curX < boardSize && curY >= 0 && curY < boardColSize)) {
                continue;
            }
            if (visited[curX][curY]) {
                continue;
            }
            visited[curX][curY] = true;
            if (board[curX][curY] == 'O') {
                queue[tail].x = curX;
                queue[tail].y = curY;
                tail++;
                if (isBianJie) {
                    board[curX][curY] = 'Y';  //边界上的先置为Y
                } else {
                    board[curX][curY] = 'X';  //非边界上的置为X
                }
            }
        }
        head++;
    }
    return;
}

void solve(char **board, int boardSize, int *boardColSize)
{
    int i, j;
    if (board == NULL || boardSize <= 0 || boardColSize == NULL) {
        return;
    }
    for (i = 0; i < boardSize; ++i) {
        for (j = 0; j < boardColSize[i]; ++j) {
            if (board[i][j] != 'O') {
                continue;
            }
            if (i == 0 || i == boardSize - 1 || j == 0 || j == boardColSize[i] - 1) {
                board[i][j] = 'Y';
                Bfs(board, boardSize, boardColSize[i], i, j, true);
            }
        }
    }
    for (i = 1; i < boardSize - 1; ++i) {
        for (j = 1; j < boardColSize[i] - 1; ++j) {
            if (board[i][j] != 'O') {
                continue;
            }
            board[i][j] = 'X';
            Bfs(board, boardSize, boardColSize[i], i, j, false);
        }
    }
    for (i = 0; i < boardSize; ++i) {
        for (j = 0; j < boardColSize[i]; ++j) {
            if (board[i][j] == 'Y') {
                board[i][j] = 'O';
            }
        }
    }
    return;
}

// 法3：并查集
#define ROW 4
#define COL 2
int direction[ROW][COL] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int g_count;
int *g_parent;
int *g_size;

void Init(int n)
{
    g_count = n;
    g_parent = (int*)calloc(n, sizeof(int));
    g_size = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        g_parent[i] = i;
        g_size[i] = 1;
    }
    return;
}

int Find(int x) 
{
    while (x != g_parent[x]) {
        g_parent[x] = g_parent[g_parent[x]];
        x = g_parent[x];
    }
    return x;
}

void Union(int p, int q)
{
    int rootP = Find(p);
    int rootQ = Find(q);
    if (rootP == rootQ) {
        return;
    }

    if (g_size[rootP] < g_size[rootQ]) {
        g_parent[rootP] = rootQ;
        g_size[rootQ] += g_size[rootP];
    } else {
        g_parent[rootQ] = rootP;
        g_size[rootP] += g_size[rootQ];
    }
    g_count--;
    return;
}

void solve(char** board, int boardSize, int* boardColSize)
{
    if (board == NULL || boardSize == 0 || boardColSize == NULL) {
        return;
    } 

    int row = boardSize;
    int col = *boardColSize;
    int g_count = row * col + 1;
    int dummy = row * col;
    Init(g_count);
    for (int i = 0; i < row; i++) {
        if (board[i][0] == 'O') {
            Union(i * col, dummy);
        }
        if (board[i][col - 1] == 'O') {
            Union(i * col + col - 1, dummy);
        }
    }
    for (int j = 0; j < col; j++) {
        if (board[0][j] == 'O') {
            Union(j, dummy);
        }
        if (board[row - 1][j] == 'O') {
            Union((row - 1) * col + j, dummy);
        }
    }
    for (int i = 1; i < row - 1; i++) {
        for (int j = 1; j < col - 1; j++) {
            if (board[i][j] == 'O') {
                for (int k = 0; k < ROW; k++) {
                    int newX = i + direction[k][0];
                    int newY = j + direction[k][1];
                    if (board[newX][newY] == 'O') {
                        Union(i * col + j, newX * col + newY);
                    }
                }
            }
        }
    }

    for (int i = 1; i < row - 1; i++) {
        for (int j = 1; j < col - 1; j++) {
            if (Find(i * col + j) != Find(dummy)) {
                board[i][j] = 'X';
            }
        }
    }
    return;
}

// 剑指 Offer 68 - II. 二叉树的最近公共祖先
/*
    对于一个公共祖先（一定有子节点才能当祖先）来说，其两个子节点 p、q 有三种分布情况
    1 p, q 分别位于 x 的左子树和右子树；
    2 p, q 都在 x 的左子树（也包括祖先其自身，另一个字节点在左子树）；
    3 p, q 都在 x 的右子树（也包括祖先其自身，另一个字节点在右子树）；
    上述3条规律对每一子树都成立， 所以只要检查每个节点的 左右子树即可， 所以要用后序遍历
*/
int flagP = 0;
int flagQ = 0;
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    if (!root){
        return NULL;
    }
    if (root == p || root == q){
        return root;
    }
    struct TreeNode* left = lowestCommonAncestor(root -> left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root -> right, p, q);
    if (left && right){ //  p, q 分别位于 x 的左子树和右子树；
        return root;
    } else if (left){  // p, q 都在 x 的左子树（也包括祖先其自身，另一个字节点在左子树）；
        return left;
    } else if (right){ // p, q 都在 x 的右子树（也包括祖先其自身，另一个字节点在右子树）；
        return right;
    }
    return NULL;
}

// 124. 二叉树中的最大路径和
int postOrder(struct TreeNode* root, int* ans) 
{
    if (root == NULL) {
        return 0;
    }
    const int l = fmax(0, postOrder(root->left,  ans));
    const int r = fmax(0, postOrder(root->right, ans));
    *ans = fmax(*ans, root->val + l + r);
    return root->val + fmax(l, r);
}

int maxPathSum(struct TreeNode* root) 
{
    int ans = INT_MIN;
    postOrder(root, &ans);
    return ans;
}

// 547. 省份数量
int gCount = 0;
int* gParent;
int* gSize;

void Init(int n)
{
    gCount = n;
    gParent = (int*)calloc(n, sizeof(int));
    gSize = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        gParent[i] = i;
        gSize[i] = 1;
    }
    return;
}

int Find(int x)
{
    while (x != gParent[x]) {
        gParent[x] = gParent[gParent[x]];
        x = gParent[x];
    }
    return x;
}

void Union(int p, int q)
{
    int rootP = Find(p);
    int rootQ = Find(q);
    if (rootP == rootQ) {
        return;
    }
    if (gSize[rootP] < gSize[rootQ]) {
        gParent[rootP] = rootQ;
        gSize[rootQ] += gSize[rootP];
    } else {
        gParent[rootQ] = rootP;
        gSize[rootP] += gSize[rootQ];
    }
    gCount--;
    return;
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize)
{
    Init(isConnectedSize);
    for (int i = 0; i < isConnectedSize; i++) {
        for (int j = i + 1; j < isConnectedSize; j++) {
            if (isConnected[i][j] == 1) {
                Union(i, j);
            }
        }
    }
    return gCount;
}

// 207. 课程表
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++) {
        inDegree[prerequisites[i][0]]++;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int head = 0;
    int tail = 0;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }
    while (head != tail) {
        int size = tail - head;
        for (int i = 0; i < size; i++) {
            int course = queue[head];
            for (int j = 0; j < prerequisitesSize; j++) {
                if (prerequisites[j][1] == course) {
                    inDegree[prerequisites[j][0]]--;
                    if (inDegree[prerequisites[j][0]] == 0) {
                        queue[tail++] = prerequisites[j][0];
                    }
                }
            }
            head++;
        }
    }
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] != 0) {
            return false;
        }
    }
    return true;
}

// 210. 课程表 II
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, 
               int* prerequisitesColSize, int* returnSize)
{
    *returnSize = 0;
    int *ans = (int*)calloc(numCourses, sizeof(int));
    int *indegree = (int*)calloc(numCourses, sizeof(int));
    int *queue = (int*)calloc(numCourses, sizeof(int));
    int head = 0;
    int tail = 0;

    for (int i = 0; i < prerequisitesSize; i++) {
        indegree[prerequisites[i][0]]++;
    }
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            ans[(*returnSize)++] = i;
            queue[tail++] = i;
        }
    }

    while (head != tail) {
        int size = tail - head;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < prerequisitesSize; j++) {
                if (prerequisites[j][1] == queue[head]) {
                    indegree[prerequisites[j][0]]--;
                    if (indegree[prerequisites[j][0]] == 0) {
                        ans[(*returnSize)++] = prerequisites[j][0];
                        queue[tail++] = prerequisites[j][0];
                    }
                }
            }
            head++;
        }
    }
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] != 0) {
            *returnSize = 0;
            return ans;
        }
    }
    return ans;
}

// 329. 矩阵中的最长递增路径
#define MAXSIZE 201

int DFS(int** matrix, int rowSize, int colSize, 
        int row, int col, int lastnums, int (*lins)[MAXSIZE])
{
    // 退出条件，范围越界 或者 不大于上一个数
    if (row < 0 || row >= rowSize || col < 0 || col >= colSize ||
        matrix[row][col] <= lastnums) {
        return 0;
    }

    // 如果已经访问过了，则不需要再进行访问，直接返回结果，降低时间复杂大
    if (lins[row][col] != -1) {
        return lins[row][col];
    }

    // 分别对上下左右四个方向进行遍历，并得到遍历结果
    int a = DFS(matrix, rowSize, colSize, row + 1, col, matrix[row][col], lins);
    int b = DFS(matrix, rowSize, colSize, row - 1, col, matrix[row][col], lins);
    int c = DFS(matrix, rowSize, colSize, row, col + 1, matrix[row][col], lins);
    int d = DFS(matrix, rowSize, colSize, row, col - 1, matrix[row][col], lins);

    // 在遍历结果中选择最大的路径长度
    a = a > b ? a : b;
    c = c > d ? c : d;
    a = a > c ? a : c;

    // 将最大路径长度 记录在lins数组中
    lins[row][col] = a + 1;

    // 返回次节点最大的递增路径长度
    return lins[row][col];
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    int max = 0;
    int linCount[MAXSIZE][MAXSIZE];
    memset(linCount, -1, sizeof(int) * MAXSIZE * MAXSIZE);
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            int nums = DFS(matrix, matrixSize, *matrixColSize, i, j, -1, linCount);
            max = fmax(max, nums);
        }
    }
    return max;
}

// 315. 计算右侧小于当前元素的个数
int LowBit(int x) 
{ 
    return x & (-x); 
}

void Update(int* c, int n, int pos) 
{
    while (pos < n) {
        c[pos] += 1;
        pos += LowBit(pos);
    }
}

int Query(int* c, int n, int pos) 
{
    int ret = 0;
    while (pos > 0) {
        ret += c[pos];
        pos -= LowBit(pos);
    }
    return ret;
}

int lower_bound(int* a, int n, int x) 
{
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int comp(const void* a, const void* b) 
{ 
    return (*(int*)a - *(int*)b); 
}

int Discretization(int* a, int* nums, int n) 
{
    memcpy(a, nums, sizeof(int) * n);
    qsort(a, n, sizeof(int), comp);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[m]) {
            a[++m] = a[i];
        }
    }
    return m + 1;
}

int* countSmaller(int* nums, int numsSize, int* returnSize) 
{
    int* a = (int*)malloc(sizeof(int) * numsSize);
    int* c = (int*)malloc(sizeof(int) * (numsSize + 1));
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    memset(a, 0, sizeof(int) * numsSize);
    memset(c, 0, sizeof(int) * (numsSize + 1));
    memset(ret, 0, sizeof(int) * numsSize);

    int m = Discretization(a, nums, numsSize);
    for (int i = numsSize - 1; i >= 0; --i) {
        int id = lower_bound(a, m, nums[i]) + 1;
        ret[i] = Query(c, m + 1, id - 1);
        Update(c, m + 1, id);
    }
    free(a);
    free(c);
    *returnSize = numsSize;
    return ret;
}



/*
    ④ 回溯算法
        分割回文串
        单词搜索II
        删除无效的括号
        通配符匹配
        正则表达式匹配
*/
// 131. 分割回文串
void dfs(char* s, int n, int i, int** f, char*** ret, int* retSize, int* retColSize, char** ans, int* ansSize) {
    if (i == n) {
        char** tmp = malloc(sizeof(char*) * (*ansSize));
        for (int j = 0; j < (*ansSize); j++) {
            int ansColSize = strlen(ans[j]);
            tmp[j] = malloc(sizeof(char) * (ansColSize + 1));
            strcpy(tmp[j], ans[j]);
        }
        ret[*retSize] = tmp;
        retColSize[(*retSize)++] = *ansSize;
        return;
    }
    for (int j = i; j < n; ++j) {
        if (f[i][j]) {
            char* sub = malloc(sizeof(char) * (j - i + 2));
            for (int k = i; k <= j; k++) {
                sub[k - i] = s[k];
            }
            sub[j - i + 1] = '\0';
            ans[(*ansSize)++] = sub;
            dfs(s, n, j + 1, f, ret, retSize, retColSize, ans, ansSize);
            --(*ansSize);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    int retMaxLen = n * (1 << n);
    char*** ret = malloc(sizeof(char**) * retMaxLen);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * retMaxLen);
    int* f[n];
    for (int i = 0; i < n; i++) {
        f[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            f[i][j] = 1;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
        }
    }
    char* ans[n];
    int ansSize = 0;
    dfs(s, n, 0, f, ret, returnSize, *returnColumnSizes, ans, &ansSize);
    return ret;
}

// 212. 单词搜索 II
#define N 200
int visit[N][N] = { 0 }; // 是否访问
char *result[N]= { 0 }; // 返回结果

bool dfs(char** a, int n, int* col, char *word, int r, int c)
{
    if (a == NULL || n == 0 || col == NULL || word == NULL) {
        return false; // 参数错误
    } else if (r < 0 || r >= n || c < 0 || c >= *col) {
        return false; // 越界了
    } else if (visit[r][c]) {
        return false; // 已访问
    } else if (a[r][c] != word[0]) {
        return false; // 字母不相等 
    } else if (strlen(word) == 1) { // 只有1个字母，并且相等 
        return true;
    } else { // 查看后续的字母 
        visit[r][c] = 1; // 已访问 
        if (dfs(a, n, col, &word[1], r - 1, c)) {
            return true;
        }
        if (dfs(a, n, col, &word[1], r + 1, c)) {
            return true;
        }
        if (dfs(a, n, col, &word[1], r, c - 1)) {
            return true;
        }
        if (dfs(a, n, col, &word[1], r, c + 1)) {
            return true;
        }
        visit[r][c] = 0; // 回溯 
        return false;
    }
}

bool exist(char** a, int n, int* col, char *word)
{
    if (a == NULL || n <= 0 || col == NULL || word == NULL) {
        return false;
    }
    memset(visit, 0, sizeof(visit));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < col[r]; c++) {
            if (a[r][c] != word[0]) { // 这里剪枝了下
                continue; // 找其他的 
            }
            if (dfs(a, n, col, &word[0], r, c)) {
                return true;
            }
        }
    }
    return false;
}

char **findWords(char** a, int n, int* col, char ** wdList, int m, int* returnSize)
{
    if (a == NULL || col == NULL || wdList == NULL || returnSize == NULL) {
        return NULL; // 参数错误
    } else if (n <= 0 || *col <= 0 || m <= 0) {
        *returnSize = 0;
        return NULL; // 参数错误
    }
    *returnSize = 0;
    memset(result, 0, sizeof(result));
    for (int i = 0; i < m; i++) {
        if (exist(a, n, col, wdList[i])) {
            int len = strlen(wdList[i]) + 1;
            result[*returnSize] = (char*)calloc(sizeof(char), len);
            strncpy(result[*returnSize], wdList[i], len - 1);
            (*returnSize)++;
        }
    }
    return result;
}


// 301. 删除无效的括号
int gResultSize = 0;
char **gResult;
bool IsValid(char *s){
    int cnt = 0;
    char *p = s;
    while (*p != '\0') {
        if (*p == '(') {
            cnt++;
        } else if (*p == ')') {
            cnt--;
        }
        if (cnt < 0) {
            return false;
        }
        p++;
    }
    return cnt == 0;
}

void removeInvalidParentheses2(char * s, int sLen , int start, int leftCnt, int rightCnt)
{
    if (start > sLen) {
        return;
    }
    if (leftCnt == 0 && rightCnt == 0) {
        if (IsValid(s)) {
            gResult[gResultSize] = malloc(sizeof(char) * sLen + 1);
            strcpy(gResult[gResultSize], s);
            gResultSize++;
        }
        return;
    }
    char subStr[sLen];
    for (int i = start; i < sLen; ++i) {
        if (i > start && s[i] == s[i - 1]){
            continue;
        }
        if (s[i] == '(' && leftCnt > 0){
            memcpy(subStr, s, i);
            subStr[i] = '\0';
            strcat(subStr, s + i + 1);
            removeInvalidParentheses2(subStr, sLen - 1, i, leftCnt - 1, rightCnt);
        } else if (s[i] == ')' && rightCnt > 0){
            memcpy(subStr, s, i);
            subStr[i] = '\0';
            strcat(subStr, s + i + 1);
            removeInvalidParentheses2(subStr, sLen - 1, i, leftCnt, rightCnt - 1);
        }
    }
}
#define MAX_RESULT_LEN 10000
char ** removeInvalidParentheses(char * s, int* returnSize){
    int leftCnt = 0;
    int rightCnt = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '(') {
            leftCnt++;
        } else if (s[i] == ')'){
            if (leftCnt == 0){
                rightCnt++;
            } else {
                leftCnt--;
            }
        }
    }
    char **ans = malloc(sizeof(char*) * MAX_RESULT_LEN);
    memset(ans, 0, sizeof(char*) * MAX_RESULT_LEN);
    gResult = ans;
    gResultSize = 0;
    removeInvalidParentheses2(s, strlen(s), 0, leftCnt, rightCnt);
    if (gResultSize == 0){
        gResult[0] = "";
        gResultSize = 1;
    }
    *returnSize = gResultSize;
    return ans;
}

// 44. 通配符匹配
bool isMatch(char * s, char * p){
    int m = strlen(s);
    int n = strlen(p);
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        if (p[i - 1] == '*') {
            dp[0][i] = true;
        } else {
            break;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            } else if (p[j - 1] == '?' || (s[i - 1] == p[j - 1])) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][n];
}

// 10. 正则表达式匹配
bool isMatch(char * s, char * p)
{
    if (!(*p)) {
        return !(*s);
    }
    bool first_match = *s && (*s == *p || *p == '.');
    if (*(p+1) == '*') {
        return isMatch(s, p + 2) || (first_match && isMatch(++s, p));
    } else {
        return first_match && isMatch(++s, ++p);
    }
}



/*
    ⑤ 排序和搜索
        摆动排序II
        有序矩阵中第K小的元素
        寻找两个正序数组的中位数
*/
// 324. 摆动排序 II
int Compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void Reverse(int* nums, int size)
{
    for (int i = 0; i < size / 2; i++) {
        int temp = nums[i];
        nums[i] = nums[size - 1 - i];
        nums[size - 1 - i] = temp;
    }
    return;
}

void Handle(int* nums, int numsSize, int* head, int headSize, int* tail, int tailSize)
{
    int index = 0;
    while (index < headSize) {
        head[index] = nums[index];
        index++;
    }
    while (index < numsSize) {
        tail[index - headSize] = nums[index];
        index++;
    }
    Reverse(head, headSize);
    Reverse(tail, tailSize);
    return;
}

void wiggleSort(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), Compare);
    int* head;
    int* tail;
    if (numsSize % 2) {
        head = (int*)malloc(sizeof(int) * (numsSize + 1) / 2);    
        tail = (int*)malloc(sizeof(int) * numsSize / 2);
        Handle(nums, numsSize, head, (numsSize + 1) / 2, tail, numsSize / 2);
    } else {
        head = (int*)malloc(sizeof(int) * numsSize / 2);
        tail = (int*)malloc(sizeof(int) * numsSize / 2);
        Handle(nums, numsSize, head, numsSize / 2, tail, numsSize / 2);
    }
    int h = 0, t = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            nums[i] = head[h++];
        } else {
            nums[i] = tail[t++];
        }
    }
    return;
}

// 378. 有序矩阵中第 K 小的元素
int Compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
    int* temp = (int*)malloc(sizeof(int) * matrixSize * *matrixColSize);
    int size = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            temp[size++] = matrix[i][j];
        }
    }
    qsort(temp, matrixSize * *matrixColSize, sizeof(int), Compare);
    return temp[k - 1];
}

// 4. 寻找两个正序数组的中位数
int Compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int len = nums1Size + nums2Size;
    int *arr = (int*)malloc(sizeof(int) * len);
    int cur1 = 0, cur2 = 0;
    for (int i = 0; i < len; i++) {
        if (i < nums1Size) {
            arr[i] = nums1[cur1++];
        } else {
            arr[i] = nums2[cur2++];
        } 
    }
    qsort(arr, len, sizeof(int), Compare);
    if (len % 2 == 0) {
        return (arr[(len - 1) / 2] + arr[len / 2]) / 2.0;
    } else {
        return arr[len / 2];
    }
}



/*
    ⑥ 动态规划
        乘积最大子数组
        最佳买卖股票时机含冷冻期
        完全平方数
        单词拆分
        单词拆分II
        戳气球
*/
// 152. 乘积最大子数组
int maxProduct(int* nums, int numsSize)
{
    if (NULL == nums || 0 == numsSize){
        return 0;
    }

    int max = nums[0];
    int min = nums[0];
    int res = nums[0];
    int index = 0;
    int tempMax = 0;
    int tempMin = 0;

    for (index = 1; index <= numsSize - 1; index++) {
        tempMax = fmax(max * nums[index], min * nums[index]);
        tempMin = fmin(max * nums[index], min * nums[index]);
        max = fmax(tempMax, nums[index]);
        min = fmin(tempMin, nums[index]);
        res = fmax(max, res);
    }
    return res;
}

// 309. 最佳买卖股票时机含冷冻期
int maxProfit(int* prices, int pricesSize) 
{
    if (pricesSize == 0) {
        return 0;
    }

    int f0 = -prices[0];
    int f1 = 0;
    int f2 = 0;
    for (int i = 1; i < pricesSize; ++i) {
        int newf0 = fmax(f0, f2 - prices[i]);
        int newf1 = f0 + prices[i];
        int newf2 = fmax(f1, f2);
        f0 = newf0;
        f1 = newf1;
        f2 = newf2;
    }
    return fmax(f1, f2);
}

// 279. 完全平方数
bool isPerfectSquare(int x) {
    int y = sqrt(x);
    return y * y == x;
}

bool checkAnswer4(int x) {
    while (x % 4 == 0) {
        x /= 4;
    }
    return x % 8 == 7;
}

int numSquares(int n) 
{
    if (isPerfectSquare(n)) {
        return 1;
    }
    if (checkAnswer4(n)) {
        return 4;
    }
    for (int i = 1; i * i <= n; i++) {
        int j = n - i * i;
        if (isPerfectSquare(j)) {
            return 2;
        }
    }
    return 3;
}

// 139. 单词拆分
bool wordBreak(char * s, char ** wordDict, int wordDictSize)
{
    int queue[10000] = {0};
    int head = 0;
    int tail = 0;

    char temp[10000] = {0};
    int vist[10000] = {0};
    int sLen = strlen(s);

    for (int i = 0; i < wordDictSize; i++) {
        int len = strlen(wordDict[i]);
        strncpy(temp, s, len);
        temp[len] = '\0';
        if (strcmp(temp, wordDict[i]) == 0) {
            queue[tail++] = len;
            vist[len] = 1;
        }
    }
    char* current;
    while (head < tail) {
        int currentLen = queue[head++];
        current = s + currentLen;
        if (*current == '\0') {
            return true;
        }
        for (int j = 0; j < wordDictSize; j++) {
            int len = strlen(wordDict[j]);
            if (len > strlen(current)) {
                continue;
            }
            strncpy(temp, current, len);
            temp[len] = '\0';
            if (strcmp(temp, wordDict[j]) == 0) {
               if (vist[currentLen + len] == 1) {
                    continue;
                }
                queue[tail++] = currentLen + len;
                vist[currentLen + len] = 1;
            }
        }
    }
    return false;
}

// 140. 单词拆分 II
struct Trie {
    int ch[26];
    bool flag;
} trie[10001];

int size;

void insert(char* s, int sSize) {
    int add = 0;
    for (int i = 0; i < sSize; i++) {
        int x = s[i] - 'a';
        if (trie[add].ch[x] == 0) {
            trie[add].ch[x] = ++size;
            memset(trie[size].ch, 0, sizeof(trie[size].ch));
            trie[size].flag = false;
        }
        add = trie[add].ch[x];
    }
    trie[add].flag = true;
}

bool find(char* s, int sSize) {
    int add = 0;
    for (int i = 0; i < sSize; i++) {
        int x = s[i] - 'a';
        if (trie[add].ch[x] == 0) {
            return false;
        }
        add = trie[add].ch[x];
    }
    return trie[add].flag;
}

char** ans[1001];
int ansSize[1001];

void backtrack(char* s, int sSize, int index) {
    if (ans[index] == NULL) {
        ans[index] = malloc(sizeof(char**));
        if (index == sSize) {
            ansSize[index] = 1;
            char* tmp = malloc(sizeof(char));
            tmp[0] = '\0';
            ans[index][0] = tmp;
            return;
        }
        ansSize[index] = 0;
        for (int i = index + 1; i <= sSize; ++i) {
            int len = i - index;
            char* word = malloc(sizeof(char) * (len + 1));
            for (int j = 0; j < len; ++j) word[j] = s[index + j];
            word[len] = '\0';
            if (find(word, len)) {
                backtrack(s, sSize, i);
                ans[index] = realloc(ans[index], sizeof(char**) * (ansSize[index] + ansSize[i]));
                for (int j = 0; j < ansSize[i]; ++j) {
                    int len1 = len, len2 = strlen(ans[i][j]);
                    char* tmp = malloc(sizeof(char) * (len1 + len2 + 2));
                    strcpy(tmp, word);
                    if (len2 > 0) {
                        tmp[len1] = ' ';
                    }
                    strcpy(tmp + len1 + 1, ans[i][j]);
                    ans[index][ansSize[index]++] = tmp;
                }
            }
        }
    }
}

char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) 
{
    memset(ans, 0, sizeof(ans));
    size = 0;
    memset(trie[0].ch, 0, sizeof(trie[0].ch));
    trie[0].flag = false;
    for (int i = 0; i < wordDictSize; i++) {
        insert(wordDict[i], strlen(wordDict[i]));
    }
    backtrack(s, strlen(s), 0);
    *returnSize = ansSize[0];
    return ans[0];
}

// 312. 戳气球
int maxCoins(int* nums, int numsSize) {
    int rec[numsSize + 2][numsSize + 2];
    memset(rec, 0, sizeof(rec));
    int val[numsSize + 2];
    val[0] = val[numsSize + 1] = 1;
    for (int i = 1; i <= numsSize; i++) {
        val[i] = nums[i - 1];
    }
    for (int i = numsSize - 1; i >= 0; i--) {
        for (int j = i + 2; j <= numsSize + 1; j++) {
            for (int k = i + 1; k < j; k++) {
                int sum = val[i] * val[k] * val[j];
                sum += rec[i][k] + rec[k][j];
                rec[i][j] = fmax(rec[i][j], sum);
            }
        }
    }
    return rec[0][numsSize + 1];
}



/*
    ⑦ 设计问题
        LRU缓存机制
        实现Trie(前缀树)
        扁平化嵌套列表迭代器
        数据流中的中位数
*/
// 146. LRU 缓存机制
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} LRUCache;

LRUCache* cache = NULL;
int g_capacity = 0;

LRUCache** lRUCacheCreate(int capacity) {
    g_capacity = capacity;
    return &cache;
}

int lRUCacheGet(LRUCache** obj, int key) {
    LRUCache* s;

    HASH_FIND_INT(*obj, &key, s);
    if (s) {
        HASH_DEL(*obj, s);
        HASH_ADD_INT(*obj, key, s);
        return s->val;
    }

    return -1;
}

void lRUCachePut(LRUCache** obj, int key, int value) {
    LRUCache* s = NULL;

    HASH_FIND_INT(*obj, &key, s);
    if (s) {
        HASH_DEL(*obj, s);
    }
    s = (LRUCache*) malloc(sizeof (*s));
    s->key = key;
    HASH_ADD_INT(*obj, key, s);
    s->val = value;

    s = *obj;
    int capacity = HASH_COUNT(*obj);
    if (capacity > g_capacity) {
        HASH_DEL(*obj, s);
        free(s);
    }
}

void lRUCacheFree(LRUCache** obj) {
    LRUCache *current_user, *tmp;
    HASH_ITER(hh, *obj, current_user, tmp) {
        HASH_DEL(*obj, current_user); 
        free(current_user); 
    }
}

// 208. 实现 Trie (前缀树)
#define NUM 26
typedef struct Trie_{
    bool isWord;
    struct Trie_ *nextList[NUM];
} Trie;

Trie* trieCreate() {
    Trie *root = (Trie *)malloc(sizeof(Trie));
    memset(root, 0, sizeof(*root));
    return root; 
}

void trieInsert(Trie* obj, char * word) {
    Trie *root = obj;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int id = word[i] - 'a';
        //printf("%d %c %s\n", id, word[i], word);
        if (root->nextList[id] == NULL) {
            root->nextList[id] = trieCreate();
        }
        root = root->nextList[id];        
    }
    root->isWord = true;
}

bool trieSearch(Trie* obj, char * word) {
    Trie *root = obj;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int id = word[i] - 'a';
        if (root->nextList[id] == NULL) {
            return false;
        }
        root = root->nextList[id];
    }
    return root->isWord;  
}

bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *root = obj;
    int len = strlen(prefix);
    for (int i = 0; i < len; i++) {
        int id = prefix[i] - 'a';
        if (root->nextList[id] == NULL) {
            return false;
        }
        root = root->nextList[id];
    }
    return true;
}

void trieFree(Trie* obj) {
    Trie *root = obj;   
    for (int i = 0; i < NUM; i++) {        
        if (root->nextList[i] == NULL) {
            continue;
        }
        return trieFree(root->nextList[i]);
    }
    free(root);
}

// 341. 扁平化嵌套列表迭代器
struct NestedIterator {
    int *vals;
    int size;
    int cur;
};

void dfs(struct NestedIterator *iter, struct NestedInteger **nestedList, int nestedListSize) {
    for (int i = 0; i < nestedListSize; i++) {
        if (NestedIntegerIsInteger(nestedList[i])) {
            (iter->vals)[(iter->size)++] = NestedIntegerGetInteger(nestedList[i]);
        } else {
            dfs(iter, NestedIntegerGetList(nestedList[i]), NestedIntegerGetListSize(nestedList[i]));
        }
    }
}

struct NestedIterator *nestedIterCreate(struct NestedInteger **nestedList, int nestedListSize) {
    struct NestedIterator *ret = malloc(sizeof(struct NestedIterator));
    ret->vals = malloc(sizeof(int) * 20001);
    ret->size = 0;
    ret->cur = 0;
    dfs(ret, nestedList, nestedListSize);
    return ret;
}

bool nestedIterHasNext(struct NestedIterator *iter) {
    return iter->cur != iter->size;
}

int nestedIterNext(struct NestedIterator *iter) {
    return (iter->vals)[(iter->cur)++];
}

void nestedIterFree(struct NestedIterator *iter) {
    free(iter->vals);
    free(iter);
}

// 295. 数据流的中位数
typedef struct {
    int top;
    int data[50000];
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->top = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    obj->data[obj->top] = num;
    int i = obj->top - 1;
    int t;
    while (i >= 0 && obj->data[i + 1] < obj->data[i]) {
        t = obj->data[i + 1];
        obj->data[i + 1] = obj->data[i];
        obj->data[i] = t;
        i--;
    }
    obj->top++;
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->top == 0) {
        return 0;
    } else if (obj->top % 2 == 1) {
        return obj->data[obj->top / 2];
    } else {
        int mid = obj->top / 2;
        return (obj->data[mid - 1] + obj->data[mid]) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}



/*
    ⑧ 数学
        最大数
        直线上最多的点数
*/
// 179. 最大数
#define MAX 20 
#define SIZE 10000
int Compare(const void *a, const void *b)
{
    char** aa = (char**)a;
    char** bb = (char**)b;
    char* tempA = (char*)calloc(MAX * 2, sizeof(char));
    char* tempB = (char*)calloc(MAX * 2, sizeof(char));
    strcat(tempA, *aa);
    strcat(tempA, *bb);
    strcat(tempB, *bb);
    strcat(tempB, *aa);
    return strcmp(tempB, tempA);
}

bool IsAllZero(int *nums, int numsSize)
{
    long long sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum != 0) {
            return false;
        }
    }
    return true;
}

char* largestNumber(int* nums, int numsSize)
{
    if (IsAllZero(nums, numsSize)) {
        return "0";
    }

    char** temp = (char**)malloc(sizeof(char*) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        temp[i] = (char*)calloc(MAX, sizeof(char));
        sprintf(temp[i], "%d", nums[i]);
    }

    qsort(temp, numsSize, sizeof(char*), Compare);

    char* ans = (char*)calloc(SIZE, sizeof(char));
    for (int i = 0; i < numsSize; i++) {
        strcat(ans, temp[i]);
    }
    return ans;
}

// 149. 直线上最多的点数
int maxPoints(int** points, int pointsSize, int* pointsColSize)
{
    if (pointsSize <= 2) {
        return pointsSize;
    }
    int max = 2;
    for (int i = 0; i < pointsSize - 2; i++) {
        int count0 = 1;
        for (int j = i + 1; j < pointsSize - 1; j++) {
            int count = 2;
            int count0 = 2;
            int x1 = points[j][0] - points[i][0];
            int y1 = points[j][1] - points[i][1];
            for (int k = j + 1; k < pointsSize; k++) {
                int x2 = points[k][0] - points[i][0];
                int y2 = points[k][1] - points[i][1];
                if (x1 != 0 && x2 != 0) {
                    double k1 = 1.0 * y1 / x1;
                    double k2 = 1.0 * y2 / x2;
                    if (k1 == k2) {
                        count++;
                    }
                } else if(x2 == 0) {
                    count0++;
                }
            }
            if (x1 != 0) {
                count0--;
            }
            max = fmax(fmax(count, count0), max);
        }
    }
    return max;
}



/*
    ⑨ 其他
        根据身高队列重建队列
        接雨水
        天际线问题
        柱状图中最大的矩形
*/
// 406. 根据身高重建队列
int Compare(const void *a, const void *b)
{
    int* aa = *(int**)a;
    int* bb = *(int**)b;
    return (aa[0] == bb[0]) ? aa[1] - bb[1] : bb[0] - aa[0];
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    int** ans = (int**)malloc(sizeof(int*) * peopleSize);
    *returnSize = peopleSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * peopleSize);

    qsort(people, peopleSize, sizeof(int*), Compare);
    for (int i = 0; i < peopleSize; i++) {
        int k = people[i][1];
        memmove(&ans[k + 1], &ans[k], (i - k) * sizeof(int*));
        ans[k] = (int*)malloc(sizeof(int) * 2);
        ans[k][0] = people[i][0];
        ans[k][1] = people[i][1];
        (*returnColumnSizes)[i] = 2;
    }
    return ans;
}

// 42. 接雨水
int trap(int* height, int heightSize)
{
    int *stack = (int*)malloc(sizeof(int) * heightSize);
    memset(stack, -1, sizeof(int) * heightSize);
    int top = -1;
    int ans = 0;

    for (int i = 0; i < heightSize; i++) {
        while (top > -1 && height[stack[top]] < height[i]) { 
            int bH = height[stack[top]];
            top--;
            if (top < 0) {
                break;
            } else {
                if (bH == height[stack[top]]) {
                    continue;
                }
                int h = fmin(height[i], height[stack[top]]) - bH;
                int width = i - 1 - stack[top];
                ans += h * width;
            }
        }
        stack[++top] = i;
    }
    
    return ans;
}

// 218. 天际线问题
struct BuildingPoints {
    int points[2];
    int LorR;
    int index;
};

int compare(const void *a, const void *b)
{
    struct BuildingPoints *p1 = (struct BuildingPoints *)a;
    struct BuildingPoints *p2 = (struct BuildingPoints *)b;
    return p1->points[0] - p2->points[0];
}

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes){
    int i;
    int j;
    int height = 0;
    struct BuildingPoints *queue = malloc(sizeof(struct BuildingPoints) * buildingsSize * 2);
    int **ret = malloc(sizeof(int*) * buildingsSize * 2);
    int *retCol = malloc(sizeof(int) * buildingsSize * 2);
    int cnt = 0;
    int queueLen = 0;

    for (i = 0; i < buildingsSize; i++) {
        queue[queueLen].points[0] = buildings[i][0];
        queue[queueLen].points[1] = buildings[i][2];
        queue[queueLen].LorR = 1;
        queue[queueLen].index = i;
        queueLen++;
        queue[queueLen].points[0] = buildings[i][1];
        queue[queueLen].points[1] = 0;
        queue[queueLen].LorR = 2;
        queue[queueLen].index = i;
        queueLen++;
    }

    qsort(queue, queueLen, sizeof(struct BuildingPoints), compare);

    for (i = 0; i < queueLen; i++) {
        if (queue[i].LorR == 1) {
            // left edge
            for (j = i+1; j < queueLen; j++) {
                if (queue[j].LorR == 1) {
                    continue;
                }
                if (queue[j].points[0] >= buildings[queue[i].index][1]) {
                    break;
                }

                // if right edge is in range, update height
                if (queue[j].points[1] < queue[i].points[1]) {
                    queue[j].points[1] = queue[i].points[1];
                }
            }
        }
    }

    for (i = 0; i < queueLen; i++) {
        if (queue[i].LorR == 1) {
            // left edge
            if (queue[i].points[1] > height) {
                height = queue[i].points[1];
                while ((cnt > 0) && (queue[i].points[0] == ret[cnt-1][0])) {
                    // reduce more than one left edge
                    (cnt)--;
                    free(ret[cnt]);
                }
                if ((cnt > 0) && (ret[cnt-1][1] == queue[i].points[1])) {
                    // reduce same height
                    continue;
                }
                ret[cnt] = malloc(sizeof(int) * 2);
                ret[cnt][0] = queue[i].points[0];
                ret[cnt][1] = queue[i].points[1];
                (cnt)++;
            }
        } else {
            // right edge
            if (queue[i].points[1] < height) {
                height = queue[i].points[1];
                ret[cnt] = malloc(sizeof(int) * 2);
                ret[cnt][0] = queue[i].points[0];
                ret[cnt][1] = queue[i].points[1];
                (cnt)++;
            }
        }
    }

    for (i = 0; i < cnt; i++) {
        retCol[i] = 2;
    }

    free(queue);
    *returnSize = cnt;
    *returnColumnSizes = retCol;
    return ret;
}

// 84. 柱状图中最大的矩形
int largestRectangleArea(int* heights, int heightsSize)
{
    int maxArea = 0;
    int area = 0;

    int top = -1;
    int* stack = (int*)malloc(sizeof(int) * (heightsSize + 2));
    int* buff = (int*)malloc(sizeof(int) * (heightsSize + 2));

    buff[0] = 0;
    for (int i = 1; i <= heightsSize; i++) {
        buff[i] = heights[i - 1];
    }
    buff[heightsSize + 1] = 0;

    stack[++top] = 0;
    for (int i = 1; i < heightsSize + 2; i++) {
        while (top > 0 && buff[i] < buff[stack[top]]) {
            area = (i - 1 - stack[top - 1]) * buff[stack[top]];
            maxArea = fmax(maxArea, area);
            top--;
        }
        stack[++top] = i;
    }

    return maxArea;
}
```
