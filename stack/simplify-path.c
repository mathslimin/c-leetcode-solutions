#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//71. 简化路径

/**
给定一个文档 (Unix-style) 的完全路径，请进行路径简化。

例如，

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

边界情况:

你是否考虑了 路径 = "/../" 的情况？
在这种情况下，你需返回 "/" 。
此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/" 。
在这种情况下，你可忽略多余的斜杠，返回 "/home/foo" 。

示例 1:

输入: "/home/"
输出: "/home"
解释: 注意，最后一个目录名后面没有斜杠。

示例 2:

输入: "/a/./b/../../c/"
输出: "/c"
解释: 由于路径 "/a/./b/../../c/" 的规范化结果是 "/c"。

示例 3:

输入: "/../"
输出: "/"
解释: 上一级目录是一个合法的目录，所以返回 "/" 。

示例 4:

输入: "/home//foo/"
输出: "/home/foo"
解释: 在规范化路径中，多个连续斜杠需要用一个斜杠替换。

思路：

使用栈来存储路径，遇到 . 和空字符串不做处理，遇到 .. 则弹出栈顶元素。

*/

struct path {
    char* name;
    struct path* parent;
    struct path* child;
};

struct path* init_path(char* name)
{
    struct path* p = malloc(sizeof(struct path));
    p->name = strdup(name);
    p->parent = NULL;
    p->child = NULL;

    return p;
}

struct path* handle_dotdot(struct path* p)
{
    if (!p->parent)
        return p;

    struct path* parent = p->parent;
    parent->child = NULL;
    free(p->name);
    free(p);
    return parent;
}

char* simplifyPath(char* path)
{
    struct path* root;
    struct path *cur, *parent;
    char *start, *name;

    root = init_path("/");
    cur = root;

    while (*path) {
        while (*path == '/')
            path++;
        if (*path == '\0')
            break;

        start = path;
        while (*path && *path != '/')
            path++;

        int len = path - start;
        char* name = strndup(start, len);
        if (!strcmp(name, "."))
            continue;
        if (!strcmp(name, "..")) {
            cur = handle_dotdot(cur);
            continue;
        }

        struct path* p = init_path(name);
        p->parent = cur;
        cur->child = p;
        cur = p;
        free(name);
    }

    cur = root;
    char* ret = malloc(4096);
    ret[0] = 0;
    strcat(ret, root->name);
    cur = root->child;

    while (cur) {
        strcat(ret, cur->name);
        parent = cur;
        cur = cur->child;
        free(parent->name);
        free(parent);
        if (cur)
            strcat(ret, "/");
    }

    return ret;
}

int main(){
    char *path = "/a/./b/../../c/";
    char *res = simplifyPath(path);
    printf("%s", res);
    free(res);
    return 0;
}