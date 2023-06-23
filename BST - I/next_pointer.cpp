#include <bits/stdc++.h>
using namespace std;

Node* connect(Node* root) {
    Node *first = root, *temp = NULL;
    while(first) {
        temp = first;
        first = first->left;
        
        while(temp) {
            if(temp->left) {
                temp->left->next = temp->right;
                temp->right->next = (temp->next) ? temp->next->left : NULL;
            }
            temp = temp->next;
        }
    }
    return root;
}