#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    int l1 = s.length(), l2 = t.length();
    
    if(l1 != l2) {
        return false;
    }
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    return (s == t) ? true : false;
}