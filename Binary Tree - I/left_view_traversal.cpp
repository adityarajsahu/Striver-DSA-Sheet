#include <bits/stdc++.h>
using namespace std;

void leftViewUtil(Node *root, int level, vector<int> &ans) {
    if(root==NULL) {
        return;
    }
    
    if(ans.size()==level) {
        ans.push_back(root->data);
    }

    leftViewUtil(root->left, level+1, ans);
    leftViewUtil(root->right, level+1, ans);
}

vector<int> leftView(Node *root) {
    vector<int> ans;
    leftViewUtil(root, 0, ans);
    return res;
}