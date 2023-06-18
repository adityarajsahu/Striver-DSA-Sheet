#include <bits/stdc++.h>
using namespace std;

int height(TreeNode* node) {
    if(node == NULL) {
        return 0;
    }
    
    int lh = height(node->left);
    int rh = height(node->right);
    
    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode* root) {
    if(root == NULL) {
        return true;
    }
    
    int left_height = height(root->left);
    int right_height = height(root->right);
    
    if(abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    }
    return false;
}