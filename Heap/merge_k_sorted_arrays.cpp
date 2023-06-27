#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    for(int i = 0; i < k; i++){
        pq.push({kArrays[i][0], {i, 0}});
    }

    vector<int> ans;
    while(!pq.empty()) {
        auto smallest = pq.top();
        pq.pop();

        ans.push_back(smallest.first);

        if(smallest.second.second + 1 < kArrays[smallest.second.first].size()) {
            pq.push({kArrays[smallest.second.first][smallest.second.second + 1], {smallest.second.first, smallest.second.second + 1}});
        }
    }
    return ans;
}