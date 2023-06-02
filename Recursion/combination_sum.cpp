#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void findCombinations(vector<int>& candidates, vector<int>& v, int target, int i) {
    if(target == 0) {
        ans.push_back(v);
        return;
    }

    if(target < 0) {
        return;
    }

    if(i == candidates.size()) {
        return;
    }

    findCombinations(candidates, v, target, i + 1);

    v.push_back(candidates[i]);
    findCombinations(candidates, v, target - candidates[i], i);
    v.pop_back();
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> ans;
    findCombinations(candidates, ans, target, 0);
    return ans;
}