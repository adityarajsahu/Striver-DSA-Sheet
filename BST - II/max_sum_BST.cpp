#include <bits/stdc++.h>
using namespace std;

class Node
{
    public: 
        int mx;
        int mn;
        int sum;
        bool isBST;
};

Node solve(TreeNode* root, int& ans) {
    if(root == NULL) {
        return {INT_MIN, INT_MAX, 0, true};
    }

    Node left = solve(root->left, ans);
    Node right = solve(root->right, ans);

    Node currNode;

    currNode.sum = left.sum + right.sum + root->val;
    currNode.mx = max(root->val, right.mx);
    currNode.mn = min(root->val, left.mn);

    if(left.isBST && right.isBST && (root->val > left.mx && root->val < right.mn)) {
        currNode.isBST = true;
    } else {
        currNode.isBST = false;
    }

    if(currNode.isBST) {
        ans = max(ans, currNode.sum);
    }
    return currNode;
}

int maxSumBST(TreeNode* root) {
    
    int maxSum = 0;
    Node temp = solve(root, maxSum);
    return maxSum;
}