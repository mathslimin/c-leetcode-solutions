// https://leetcode.cn/problems/number-of-recent-calls
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int *queue;
  int capability;
  int head;
  int tail;
} RecentCounter;

RecentCounter *recentCounterCreate() {
  RecentCounter *obj = (RecentCounter *)malloc(sizeof(RecentCounter));
  obj->capability = 10001;
  obj->queue = (int *)malloc(sizeof(int) * obj->capability);
  obj->head = 0;
  obj->tail = 0;
  return obj;
}

int recentCounterPing(RecentCounter *obj, int t) {
  obj->queue[obj->tail++] = t;
  while (obj->queue[obj->head] < t - 3000) {
    obj->head++;
  }
  return obj->tail - obj->head;
}

void recentCounterFree(RecentCounter *obj) {
  free(obj->queue);
  free(obj);
}

int main() {
  RecentCounter *obj = recentCounterCreate();
  int param_1 = recentCounterPing(obj, 1);
  printf("param_1:%d equal 1\n", param_1);
  return 0;
}