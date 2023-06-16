#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& answer) {
        if(root == NULL) {
            return;
        }
        
        answer.push_back(root->val);
        preorder(root->left, answer);
        preorder(root->right, answer);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        preorder(root, answer);
        return answer;
    }
};