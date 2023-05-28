#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int count = 0, xor_sum = 0;
    unordered_map<int, int> m;
    
    for(int i = 0; i < A.size(); i++) {
        xor_sum = xor_sum ^ A[i];
        
        if(xor_sum == B) {
            count++;
        }
        if(m.find(xor_sum ^ B) != m.end()) {
            count += m[xor_sum ^ B];
        }
        m[xor_sum]++;
    }
    return count;
}