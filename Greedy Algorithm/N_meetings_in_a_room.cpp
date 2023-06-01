#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({end[i], start[i]});
    }
    
    sort(v.begin(),v.end());
    
    int ans = 1, curr = v[0].first;
    for(auto i : v) {
        if(curr < i.second) {
            ans++;
            curr = i.first;
        }
    }
    return ans;
}