#include <bits/stdc++.h>
using namespace std;

bool isPal(string s, int start, int end) {
    while(start <= end) {
        if(s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}
    
void solve(string s, vector<vector<string>> &ans, vector<string> &curr, int start)
{
    if(start == s.length())
    {
        ans.push_back(curr);
        return;
    }
    
    for(int i=start; i<s.length(); i++)
    {
        if(isPal(s, start, i))
        {
            curr.push_back(s.substr(start, i-start+1));
            solve(s, ans, curr, i+1);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> curr;

    solve(s, ans, curr, 0);
    return ans;
}