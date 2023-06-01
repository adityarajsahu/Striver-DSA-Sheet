#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n) {
    vector<pair<int, int>> v;
    
    for(int i = 0; i < n; i++) {
        v.push_back({arr[i], 0});
        v.push_back({dep[i], 1});
    }
    
    sort(v.begin(), v.end());
    
    int count = 0, max_count = 0;
    for(int i = 0; i < 2 * n; i++) {
        if(v[i].second == 0) {
            count++;
            max_count = max(max_count, count);
        } else {
            count--;
        }
    }
    return max_count;
}