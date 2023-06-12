#include <bits/stdc++.h>
using namespace std;

int prevSmaller(vector<int> &A) {
    unordered_map<int, int> m;
    stack<int> s;

    for(int i = A.size() - 1; i >= 0; i--) {
        while(!s.empty() && s.top() > A[i]) {
            m[s.top()] = A[i];
            s.pop();
        }
        s.push(A[i]);
    }

    vector<int> ans;
    for(auto num : A) {
        if(m.find(num) != m.end()) {
            ans.push_back(m[num]);
        } else {
            ans.push_back(-1);
        }
    }
    return ans;
}