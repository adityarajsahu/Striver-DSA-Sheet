#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> ans;
public:
    void inorder(TreeNode* node) {
        if(node == NULL) {
            return;
        }
        
        inorder(node->left);
        ans.push_back(node->val);
        inorder(node->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};