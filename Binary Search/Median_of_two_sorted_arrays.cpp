#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    vector<int> arr(len1 + len2);
    
    int i = 0, j = 0, k = 0;
    while(i < len1 && j < len2) {
        arr[k++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
    }
    
    if(i < len1) {
        while(i < len1) {
            arr[k++] = nums1[i++];
        }
    }
    
    if(j < len2) {
        while(j < len2) {
            arr[k++] = nums2[j++];
        }
    }
    
    int len = len1 + len2;
    if(len % 2 == 0) {
        return (double)(arr[len / 2] + arr[(len / 2) - 1]) / 2;
    }
    return (double)(arr[len / 2]);
}