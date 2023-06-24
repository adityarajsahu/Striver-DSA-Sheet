#include <bits/stdc++.h>
using namespace std;

void findCeilUtil(BinaryTreeNode<int>* root, int x, int& ans) {
    while(root) {
        if(root->data >= x) {
            ans = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }
}

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans = -1;
    findCeilUtil(node, x, ans);
    return ans;
}