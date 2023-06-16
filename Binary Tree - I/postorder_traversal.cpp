#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void postorder(TreeNode* root, vector<int>& answer) {
        if(root == NULL) {
            return;
        }
        
        postorder(root->left, answer);
        postorder(root->right, answer);
        answer.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        postorder(root, answer);
        return answer;
    }
};