#include <bits/stdc++.h>
using namespace std;

void findPredecessor(Node* root, Node*& pre, int key) {
    pre = NULL;
    while(root) {
        if(root->key < key) {
            pre = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
}

void findSuccessor(Node* root, Node*& suc, int key) {
    suc = NULL;
    while(root) {
        if(root->key > key) {
            suc = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Your code goes here
    findPredecessor(root, pre, key);
    findSuccessor(root, suc, key);
}