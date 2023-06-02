#include <bits/stdc+.h>
using namespace std;

vector<vector<int>> ans;
    
void findSubsets(vector<int>& nums, int n) {
    if(n <= 0) {
        ans.push_back({});
        return;
    }
    
    findSubsets(nums, n-1);

    int size = ans.size();
    for(int i = 0; i < size; i++) {
        vector<int> temp(ans[i].begin(), ans[i].end());
        temp.push_back(nums[n-1]);
        ans.push_back(temp);
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    findSubsets(nums, n);
    
    set<vector<int>> s;
    for(auto v : ans) {
        sort(v.begin(), v.end());
        s.insert(v);
    }
    
    for(auto v : s) {
        ans.push_back(v);
    }
    return ans;
}