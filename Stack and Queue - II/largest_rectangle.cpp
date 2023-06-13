#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();

    vector<int> arr1(n, 0);
    vector<int> arr2(n, 0);
    stack<int>st;

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        arr1[i] = st.empty()?-1:st.top();
        st.push(i);
    }


    while(!st.empty())
        st.pop();


    for(int i = n-1; i >= 0; i--)
    {
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        arr2[i] = st.empty()?n:st.top();
        st.push(i);
    }

    int ans=0;
    for(int i = 0; i < n; i++)
    {
        int area1 = (i - arr1[i]) * heights[i]; 
        int area2 = (arr2[i] - i) * heights[i]; 
        ans = max(ans, area1 + area2 - heights[i]);
    } 
    return ans;
}