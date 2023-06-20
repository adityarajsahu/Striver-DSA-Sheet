#include <bits/stdc++.h>
using namespace std;

TreeNode* buildTreeHelper(vector<int>& in, vector<int>& pre, int inS, int inE, int preS, int preE) {
    if(inS > inE) {
        return NULL;
    }
    
    int root_data = pre[preS];
    int root_index = -1;
    for(int i = inS; i <= inE; i++) {
        if(in[i] == root_data) {
            root_index = i;
            break;
        }
    }
    
    int lInS = inS;
    int lInE = root_index - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = root_index + 1;
    int rInE = inE;
    
    TreeNode* root = new TreeNode(root_data);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreS);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int size = preorder.size();
    TreeNode* root = buildTreeHelper(inorder, preorder, 0, size - 1, 0, size - 1);
    return root;
}