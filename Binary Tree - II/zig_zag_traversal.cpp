#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    
    if(root == NULL) {
        return ans;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        int n = q.size();
        
        vector<int> v;
        for(int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            v.push_back(node->val);
            if(node->left) {
                q.push(node->left);
            }
            
            if(node->right) {
                q.push(node->right);
            }
        }
        ans.push_back(v);
    }
    
    for(int i = 1; i < ans.size(); i+=2) {
        reverse(ans[i].begin(), ans[i].end());
    }
    return ans;
}