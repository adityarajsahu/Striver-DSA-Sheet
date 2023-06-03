#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string A, int start, int end) {
    while(start <= end) {
        if(A[start] != A[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int Solution::solve(string A) {
    int i = A.length() - 1, count = 0;
    
    while(i >= 0) {
        if(isPalindrome(A, 0, i)) {
            break;
        } else {
            count++;
            s.erase(A.begin() + A.length() - 1);
        }
    }
    return count;
}