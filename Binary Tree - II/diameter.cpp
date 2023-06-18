#include < bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diameter(TreeNode* root, int &d) {
        if(!root) {
            return 0;
        }
        
        int left = diameter(root->left, d);
        int right = diameter(root->right, d);
        
        d = max(left + right, d);
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        diameter(root, d);
        return d;
    }
};