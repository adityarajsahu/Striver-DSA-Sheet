#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int i1 = -1, len = nums.size();
    for(int i = len - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            i1 = i;
            break;
        }
    }  

    if(i1 < 0) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int i2 = -1;
    for(int i = len - 1; i > i1; i--) {
        if(nums[i] > nums[i1]) {
            i2 = i;
        }
    }

    swap(nums[i1], nums[i2]);
    reverse(nums.begin() + i1 + 1, nums.end());
}