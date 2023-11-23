#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int i;
    int ret,min;

    min = INT_MAX;
    ret = 0;
    for(i = 0; i < pricesSize; ++i){
        min = prices[i] < min ? prices[i] : min;
        ret = (prices[i] - min) > ret ? (prices[i] - min) : ret;
    }

    return ret;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    
    int result = maxProfit(prices, pricesSize);
    printf("Max profit: %d\n", result);
    
    return 0;
}