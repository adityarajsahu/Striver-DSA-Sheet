#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int len = height.size(), answer = 0;
    int mx = -1, max_idx = 0;
    
    for(int i = 0; i < len; i++) {
        if(mx < height[i]) {
            mx = height[i];
            max_idx = i;
        }
    }
    
    int mxh = 0;
    for(int i = 0; i < max_idx; i++) {
        if(mxh < height[i]) {
            mxh = height[i];
        } else if(mxh == height[i]) {
            continue;
        } else {
            answer += (mxh - height[i]);
        }
    }
    
    mxh = 0;
    for(int i = len-1; i > max_idx; i--) {
        if(mxh < height[i]) {
            mxh = height[i];
        } else if(mxh == height[i]) {
            continue;
        } else {
            answer += (mxh - height[i]);
        }
    }
    return answer;
}