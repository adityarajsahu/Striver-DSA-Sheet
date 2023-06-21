#include <bits/stdc++.h>
using namespace std;

TreeNode* prev = NULL;
    
void flatten(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    
    TreeNode *left = root->left, *right = root->right;
    if(prev) {
        prev->right = root;
        prev->left = NULL;
    }
    prev = root;
    flatten(left);
    flatten(right);
}