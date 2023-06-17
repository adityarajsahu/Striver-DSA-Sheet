#include <bits/stdc++.h>
using namespace std;

vector<int> topView(Node *root)
{
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }
    
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({root, 0});
    
    while(!q.empty()) {
        auto p = q.front();
        Node* node = p.first;
        int level = p.second;
        
        if(m.find(level) == m.end()) {
            m[level] = node->data;
        }
        
        if(node->left) {
            q.push({node->left, level - 1});
        }
        
        if(node->right) {
            q.push({node->right, level + 1});
        }
    }
    
    for(auto x : m) {
        ans.push_back(x.second);
    }
    return ans;
}