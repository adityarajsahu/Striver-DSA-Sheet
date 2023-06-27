#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<pair<int, int>> v;
    unordered_map<int, int> m;
    
    for(int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
    }
    
    for(auto x : m) {
        v.push_back(x);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    vector<int> ans;
    for(int i = 0; i < k; i++) {
        ans.push_back(v[i].first);
    }
    return ans;
}