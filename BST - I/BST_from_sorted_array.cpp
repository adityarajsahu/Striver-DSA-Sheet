#include <bits/stdc++.h>
using namespace std;

TreeNode* newNode(int data)
{
    TreeNode* node = new TreeNode(data);
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

TreeNode* sortedArrayToBSTUtil(vector<int> arr, int s, int e)
{
    if(s > e)
    {
        return NULL;
    }
    
    int mid = (s + e)/2;
    
    TreeNode* root = newNode(arr[mid]);
    
    root->left = sortedArrayToBSTUtil(arr, s, mid-1);
    root->right = sortedArrayToBSTUtil(arr, mid+1, e);
    
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums){
    
    int len = nums.size();
    
    return sortedArrayToBSTUtil(nums, 0, len-1);
}