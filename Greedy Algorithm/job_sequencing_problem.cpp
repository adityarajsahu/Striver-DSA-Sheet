#include <bits/stdc++.h>
using namespace std;

static bool cmp(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    sort(arr, arr + n, cmp);
    bool vis[n] = {0};
    int count = 0, prof = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if(vis[j] == false) {
                count++;
                prof += arr[i].profit;
                vis[j] = true;
                break;
            }
        }
    }
    return {count, prof};
} 