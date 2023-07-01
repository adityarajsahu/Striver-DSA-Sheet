#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int potentialMatch = nums[mid];
        int leftNum = nums[left];
        int rightNum = nums[right];
        
        if (potentialMatch == target)
            return mid;
        
        else if (leftNum <= potentialMatch) {
            if (target < potentialMatch && target >= leftNum)
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            if (target > potentialMatch && target <= rightNum)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}