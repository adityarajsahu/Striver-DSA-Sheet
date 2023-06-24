#include <bits/stdc++.h>
using namespace std;

void kthLargestUtil(Node* root, int& k, int& ans) {
    if(root == NULL) {
        return;
    }
    
    kthLargestUtil(root->right, k, ans);
    k--;
    if(k == 0) {
        ans = root->data;
    }
    kthLargestUtil(root->left, k, ans);
}

int kthLargest(Node *root, int K)
{
    //Your code here
    int ans = -1;
    kthLargestUtil(root, K, ans);
    return ans;
}