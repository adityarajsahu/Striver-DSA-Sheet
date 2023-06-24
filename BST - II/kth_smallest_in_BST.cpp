#include <bits/stdc++.h>
using namespace std;

void kthSmallestUtil(TreeNode* root, int& k, int& ans) {
    if(root == NULL) {
        return;
    }
    
    kthSmallestUtil(root->left, k, ans);
    k--;
    if(k == 0) {
        ans = root->val;
    }
    kthSmallestUtil(root->right, k, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    kthSmallestUtil(root, k, ans);
    return ans;
}