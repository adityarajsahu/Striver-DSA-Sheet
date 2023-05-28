#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int max_ending_here = 1, max_so_far = 1;
    
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i-1]) {
            continue;
        } else if(nums[i] == nums[i-1] + 1) {
            max_ending_here++;
        } else {
            max_so_far = max(max_so_far, max_ending_here);
            max_ending_here = 1;
        }
    }
    max_so_far = max(max_so_far, max_ending_here);
    return max_so_far;
}