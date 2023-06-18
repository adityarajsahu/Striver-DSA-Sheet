#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) {
        return ans;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        int len = q.size();
        vector<int> v;
        for(int i = 0; i < len; i++) {
            auto front = q.front();
            q.pop();
            
            v.push_back(front->val);
            if(front->left) {
                q.push(front->left);
            }
            
            if(front->right) {
                q.push(front->right);
            }
        }
        ans.push_back(v);
    }
    return ans;
}