#include <bits/stdc++.h>
using namespace std;

vector<int> minCoins(vector<int>& coins, int V) {
    int len = coins.size();
    vector<int> ans;

    sort(coins.begin(), coins.end(), greater<int>());

    for(int i = 0; i < len; i++) {
        while(V >= coins[i]) {
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans;
}