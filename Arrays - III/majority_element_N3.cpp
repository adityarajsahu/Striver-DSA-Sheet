#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int len = nums.size();
    unordered_map<int, int> um;
    vector<int> ans;
    
    for(auto num : nums) 
    {
        um[num]++;
    }
    
    for(auto x : um) 
    {
        if(x.second > len / 3)
        {
            ans.push_back(x.first);
        }
    }
    
    return ans;
}