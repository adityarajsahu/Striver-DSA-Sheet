#include <bits/stdc++.h>
using namespace std;

void floorInBSTUtil(TreeNode<int>* root, int x, int& ans) {
    while(root) {
        if(root->val <= x) {
            ans = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans = -1;
    floorInBSTUtil(root, X, ans);
    return ans;
}