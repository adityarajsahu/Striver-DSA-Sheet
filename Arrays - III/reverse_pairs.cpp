#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& nums, int start, int mid, int end) {
    int j = mid + 1, count = 0;
    for(int i = start; i <= mid; i++) {
        while(j <= end && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }
    
    vector<int> temp;
    int i = start;
    j = mid + 1;
    
    while(i <= mid && j <= end) {
        if(nums[i] < nums[j]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[j++]);
        }
    }
    
    while(i <= mid) {
        temp.push_back(nums[i++]);
    }
    
    while(j <= end) {
        temp.push_back(nums[j++]);
    }
    
    for(int k = start; k <= end; k++) {
        nums[k] = temp[k - start];
    }
    return count;
}

int  mergeSort(vector<int>& nums, int start, int end) {
    if(start >= end) {
        return 0;
    }
    
    int mid = (start + end) / 2;
    int count = mergeSort(nums, start, mid);
    count += mergeSort(nums, mid + 1, end);
    count += merge(nums, start, mid, end);
    return count;
}

int reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}