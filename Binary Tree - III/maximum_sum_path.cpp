#include <bits/stdc++.h>
using namespace std;

int maxSumPathUtil(TreeNode* root, int& mx) {
    if (root == NULL) {
        return 0;
    }

    int leftMaxPath = max(0, maxSumPathUtil(root->left, mx));
    int rightMaxPath = max(0, maxSumPathUtil(root->right, mx));
    int val = root->val;
    mx = max(mx, (leftMaxPath + rightMaxPath) + val);
    return max(leftMaxPath, rightMaxPath) + val;

}

int maxPathSum(TreeNode* root) {
    int mx = INT_MIN;
    maxSumPathUtil(root, mx);
    return mx;
}