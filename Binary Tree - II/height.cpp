#include <bits/stdc++.h>
using namespace std;

int maxDepth(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    
    return max(lh, rh) + 1;
}