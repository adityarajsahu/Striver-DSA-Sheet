#include <bits/stdc++.h>
using namespace std;

int widthOfBinaryTree(TreeNode* root) {
    if(root==NULL) {
        return 0;
    }
    
    queue<pair<TreeNode*,int> > q;
    q.push({root,0});
    
    int ans = 0;

    while(!q.empty()) {
        int size = q.size(), mn = q.front().second, first = 0, last = 0;
        
        for(int i = 0; i < size; i++) {
            long currIndex = q.front().second - mn;
            TreeNode* node = q.front().first;
            q.pop();
            
            if(i==0) {
                first = currIndex;
            }
            if(i==size- 1) {
                last = currIndex;
            }

            if(node->left){
                q.push({node->left, 2 * currIndex + 1});
            }
            
            if(node->right){
                q.push({node->right, 2 * currIndex + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}