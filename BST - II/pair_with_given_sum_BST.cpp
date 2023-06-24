#include <bits/stdc++.h>
using namespace std;

unordered_set<int> s;
    
void findTargetUtil(TreeNode* root, int k, bool& found) {
    if(root == NULL) {
        return;
    }
    
    findTargetUtil(root->left, k, found);
    if(s.find(k - root->val) != s.end()) {
        found = true;
        return;
    }
    s.insert(root->val);
    findTargetUtil(root->right, k, found);
}

bool findTarget(TreeNode* root, int k) {
    bool found = false;
    findTargetUtil(root, k, found);
    return found;
}