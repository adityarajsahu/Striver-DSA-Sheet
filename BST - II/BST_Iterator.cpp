#include <bits/stdc++.h>
using namespace std;

class BSTIterator {
private:
    int idx = 0;
    vector<int> in;
    void inorder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        if(idx == in.size()) {
            return -1;
        }
        return in[idx++];
    }
    
    bool hasNext() {
        return idx < in.size();
    }
};