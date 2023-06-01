#include <bits/stdc++.h>
using namespace std;

static bool cmp(Item i1, Item i2) {
    double r1 = (float)i1.value / (float)i1.weight;
    double r2 = (float)i2.value / (float)i2.weight;
    
    if(r1 > r2) {
        return true;
    }
    return false;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr, arr + n, cmp);
    double ans = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[i].weight <= W) {
            ans += (double)arr[i].value;
            W -= arr[i].weight;
        } else {
            ans += (double)arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return ans;
}