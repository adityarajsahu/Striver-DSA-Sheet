#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 1) {
        return strs[0];
    }
    string common = "";
    int i = 0, j = 0;
    while(i < strs[0].length() && j < strs[1].length()) {
        if(strs[0][i] == strs[1][j]) {
            common += strs[0][i];
            i++;
            j++;
        } else {
            break;
        }
    }
    
    if(common == "") {
        return common;
    }
    
    for(int k = 2; k < strs.size(); k++) {
        string temp = "";
        int a = 0, b = 0;
        while(a < common.length() && b < strs[k].length()) {
            if(common[a] == strs[k][b]) {
                temp += common[a];
                a++;
                b++;
            } else {
                break;
            }
        }
        
        if(temp == "") {
            return temp;
        }
        common = temp;
    }
    return common;
}