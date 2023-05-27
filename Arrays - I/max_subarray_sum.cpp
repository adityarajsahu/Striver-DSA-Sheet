#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int msf = nums[0], meh = 0;
    for(int i = 0; i < nums.size(); i++) {
        meh += nums[i];
        if(msf < meh) {
            msf = meh;
        }

        if(meh < 0) {
            meh = 0;
        }
    }       
    return msf;
}