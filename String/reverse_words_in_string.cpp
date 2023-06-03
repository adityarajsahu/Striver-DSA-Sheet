#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    stack<string> st;
    string temp = "";
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != ' ') {
            temp += s[i];
        } else {
            if(temp.length() != 0) {
                st.push(temp);
                temp = "";
            }
        }
    }
    
    if(temp.length() != 0) {
        st.push(temp);
    }
    
    string output = "";
    while(!st.empty()) {
        string top = st.top();
        output += top + ' ';
        st.pop();
    }
    output.pop_back();
    return output;
}