#include <bits/stdc++.h>
using namespace std;

int findPalindrome(string s, int start, int end) {
    int n = s.length();
    while(start >= 0 && end < n && s[start] == s[end]) {
        start--;
        end++;
    }
    return end - start - 1;
}

string longestPalindrome(string s) {
    int n = s.length();
    int start = 0, end = 0;
    for(int i = 0; i < n; i++) {
        int len1 = findPalindrome(s, i, i);
        int len2 = findPalindrome(s, i, i + 1);
        
        int len = max(len1, len2);
        if(len > end - start) {
            start = i - ((len - 1) / 2);
            end = i + (len / 2);
        }
    }
    return s.substr(start, end - start + 1);
}