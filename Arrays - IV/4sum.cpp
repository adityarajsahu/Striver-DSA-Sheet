#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector < int>> ans;
        if (nums.empty()) {
            return ans;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int target_2 = target - (nums[i] + nums[j]);
                int front = j + 1, back = nums.size() - 1;
                while (front < back) {
                    int two_sum = nums[front] + nums[back];
                    if (target_2 > two_sum) {
                        front++;
                    } else if (target_2 < two_sum) {
                        back--;
                    } else {
                        vector<int> quad = { nums[i], nums[j], nums[front],nums[back]};
                        ans.push_back(quad);
                        while (front < back && nums[front] == quad[2]) {
                            front++;
                        }
                        while (front < back && nums[back] == quad[3]) {
                            back--;
                        }
                    }
                }
                while (j < nums.size() - 1 && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return ans;
}