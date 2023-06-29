#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;

public:
    void permutation(vector<int> &nums, int i, int n) {
        if(i == n) {
            ans.push_back(nums);
            return;
        }
        
        for(int j = i; j <= n; j++) {
            swap(nums[i], nums[j]);
            permutation(nums, i + 1, n);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permutation(nums, 0, nums.size()-1);
        return ans;
    }
};