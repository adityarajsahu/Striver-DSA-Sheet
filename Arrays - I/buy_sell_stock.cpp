#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0, min_price = prices[0];
    for(int i = 1; i < prices.size(); i++) {
        min_price = min(min_price, prices[i]);
        profit = max(profit, prices[i] - min_price);
    }        
    return profit;
}