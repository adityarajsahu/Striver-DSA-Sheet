#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int i1 = 0, i2 = 0, i3 = nums.size() - 1;
    while(i2 <= i3) {
        if(nums[i2] == 0) {
            swap(nums[i1], nums[i2]);
            i1++;
            i2++;
        } else if(nums[i2] == 1) {
            i2++;
        } else {
            swap(nums[i2], nums[i3]);
            i3--;
        }
    }        
}