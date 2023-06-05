#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    stack<int> st;
    
    for(auto num : nums2)
    {
        while(!st.empty() && st.top() < num)
        { 
            mp[st.top()] = num ; st.pop();
        }
        st.push(num);
    }
    
    vector<int> ans;
    
    for(auto item : nums1)
    {
        if(mp.find(item) != mp.end()) 
            ans.push_back(mp[item]);
        else ans.push_back(-1);
    }
    
    return ans;
}