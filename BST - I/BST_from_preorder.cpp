#include <bits/stdc++.h>
using namespace std;

TreeNode* bstFromPreorderUtil(vector<int>& preorder, int s, int e) {
    if(s > e) {
        return NULL;
    }
    
    TreeNode* root = new TreeNode(preorder[s]);
    
    int idx;
    for(int i = s + 1; i <= e; i++) {
        if(preorder[i] > preorder[s]) {
            idx = i;
            break;
        }
    }
    
    root->left = bstFromPreorderUtil(preorder, s + 1, idx - 1);
    root->right = bstFromPreorderUtil(preorder, idx, e);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int len = preorder.size();
    
    return bstFromPreorderUtil(preorder, 0, len - 1);
}