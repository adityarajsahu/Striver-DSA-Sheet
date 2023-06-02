#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
    vector<int> arr;
    int fac = 1;
    
    for(int i = 1; i < n; i++) {
        fac *= i;
        arr.push_back(i);
    }
    
    arr.push_back(n);
    k--;
    string ans = "";
    
    while(true) {
        ans += to_string(arr[k/fac]);
        arr.erase(arr.begin() + k/fac);
        if(arr.size() == 0) {
            break;
        }
        k = k % fac;
        fac = fac / arr.size();
    }
    return ans;
}