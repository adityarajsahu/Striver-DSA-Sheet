#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int len = nums.size();
    int max_so_far = 0, max_ending_here = 0;
    
    for(int i = 0; i < len; i++) {
        if(nums[i] == 1) {
            max_ending_here++;
        } else {
            max_so_far = max(max_so_far, max_ending_here);
            max_ending_here = 0;
        }
    }
    return max(max_so_far, max_ending_here);
}