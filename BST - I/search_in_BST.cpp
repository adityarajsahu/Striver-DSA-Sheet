#include <bits/stdc++.h>
using namespace std;

TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) {
        return root;
    }
    
    if(root->val == val) {
        return root;
    }
    
    if(root->val > val) {
        return searchBST(root->left, val);
    }
    return searchBST(root->right, val);
}