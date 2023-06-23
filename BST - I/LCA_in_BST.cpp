#include <bits/stdc++.h>
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) {
        return root;
    }
    
    if(root == p || root == q) {
        return root;
    }
    
    TreeNode* left = NULL;
    if(root->val > p->val || root->val > q->val) {
        left = lowestCommonAncestor(root->left, p, q);
    }
    
    TreeNode* right = NULL;
    if(root->val < p->val || root->val < q->val) {
        right = lowestCommonAncestor(root->right, p, q);
    }
    
    if(left && right) {
        return root;
    } else {
        if(left) {
            return left;
        }
    }
    return right;
}