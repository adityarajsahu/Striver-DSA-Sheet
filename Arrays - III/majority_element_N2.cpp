#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int len = nums.size();
    unordered_map<int, int> um;
    for(int i = 0; i < len; i++) {
        um[nums[i]]++;
    }
    
    for(auto x : um) {
        if(x.second > len/2) {
            return x.first;
        }
    }
    return -1;
}