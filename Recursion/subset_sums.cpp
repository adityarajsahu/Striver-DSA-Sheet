#include <bits/stdc++.h>
using namespace std;

vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    if(N <= 0) {
        return {0};
    }
    
    vector<int> smallAns = subsetSums(arr, N - 1);
    int size = smallAns.size();
    
    for(int i = 0; i < size; i++) {
        smallAns.push_back(smallAns[i] + arr[N - 1]);
    }
    return smallAns;
}