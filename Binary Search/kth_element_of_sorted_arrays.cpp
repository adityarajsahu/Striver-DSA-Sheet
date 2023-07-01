#include <bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    vector<int> arr(n + m);
    int i = 0, j = 0, x = 0;
    while(i < n && j < m) {
        arr[x++] = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j++];
    }
    
    while(i < n) {
        arr[x++] = arr1[i++];
    }
    
    while(j < m) {
        arr[x++] = arr2[j++];
    }
    
    return arr[k - 1];
}