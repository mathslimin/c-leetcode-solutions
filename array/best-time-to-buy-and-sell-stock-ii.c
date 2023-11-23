#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int ret = 0;
    int i;

    for(i = 1; i < pricesSize; ++i)
        if(prices[i] > prices[i-1])
            ret += prices[i] - prices[i-1];

    return ret;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    
    int result = maxProfit(prices, pricesSize);
    printf("Max profit: %d\n", result);
    
    return 0;
}
