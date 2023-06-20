#include <bits/stdc++.h>
using namespace std;

TreeNode* buildTreeHelper(vector<int>& in, vector<int>& post, int inS, int inE, int postS, int postE) {
    if(inS > inE) {
        return NULL;
    }
    
    int root_data = post[postE];
    int root_index = -1;
    for(int i = inS; i <= inE; i++) {
        if(in[i] == root_data) {
            root_index = i;
            break;
        }
    }
    
    int lInS = inS;
    int lInE = root_index - 1;
    int rInS = root_index + 1;
    int rInE = inE;
    int lPostS = postS;
    int lPostE = lInE - lInS + lPostS;
    int rPostS = lPostE + 1;
    int rPostE = postE - 1;
    
    TreeNode* root = new TreeNode(root_data);
    root->left = buildTreeHelper(in, post, lInS, lInE, lPostS, lPostE);
    root->right = buildTreeHelper(in, post, rInS, rInE, rPostS, rPostE);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int size = inorder.size();
    TreeNode* root = buildTreeHelper(inorder, postorder, 0, size - 1, 0, size - 1);
    return root;
}