#include <bits/stdc++.h>
using namespace std;

void mirror(Node* node) {
    Node* temp;
    if(node == NULL)
    {
        return;
    }
    mirror(node->left);
    mirror(node->right);
     
    temp = node->left;
    node->left = node->right;
    node->right = temp;
}