#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    map<int, map<int, vector<int>>> m;
    
public:
    void preorder(TreeNode* root, int hori_dist, int vert_dist) {
        if(root == NULL) {
            return;
        }
        
        m[hori_dist][vert_dist].push_back(root->val);
        preorder(root->left, hori_dist - 1, vert_dist + 1);
        preorder(root->right, hori_dist + 1, vert_dist + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        
        preorder(root, 0, 0);
        for(auto x : m) {
            vector<int> v;
            for(auto y : x.second) {
                sort(y.second.begin(), y.second.end());
                v.insert(v.end(), y.second.begin(), y.second.end());
            }
            
            ans.push_back(v);
        }
        return ans;
    }
};