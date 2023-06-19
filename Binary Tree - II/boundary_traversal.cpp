#include <bits/stdc++.h>
using namespace std;

bool isLeaf(node * root) {
  return (!root->left) && (!root->right);
}

void addLeftBoundary(node * root, vector < int > & res) {
  node * curr = root->left;
  while (curr) {
    if (!isLeaf(curr)) {
        res.push_back(curr->data);
    }

    if (curr->left) {
        curr = curr->left;
    } else {
        curr = curr->right;
    }
  }
}
void addRightBoundary(node* root, vector<int>& res) {
  node * curr = root->right;
  vector<int> tmp;
  while (curr) {
    if (!isLeaf(curr)) {
        tmp.push_back(curr->data);
    }
    if (curr->right) {
        curr = curr->right;
    } else {
        curr = curr->left;
    }
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(node* root, vector<int>& res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root->left) {
    addLeaves(root -> left, res);
  }
  if (root->right) {
    addLeaves(root -> right, res);
  }
}

vector < int > printBoundary(node* root) {
  vector<int> res;
  if (!root) {
    return res;
  }

  if (!isLeaf(root)) {
    res.push_back(root -> data);
  }

  addLeftBoundary(root, res);
  addLeaves(root, res);
  addRightBoundary(root, res);
  return res;
}
