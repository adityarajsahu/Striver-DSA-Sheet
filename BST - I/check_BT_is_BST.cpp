#include <bits/stdc++.h>
using namespace std;

bool helper(TreeNode* root, int mn, int mx) {
    if(root == NULL) {
        return true;
    }
    
    if(root->val > mn && root->val < mx) {
        return helper(root->left, mn, root->val) && helper(root->right, root->val, mx);
    }
    return false;
}

bool isValidBST(TreeNode* root) {
    bool ans = helper(root, INT_MIN, INT_MAX);
    return ans;
}