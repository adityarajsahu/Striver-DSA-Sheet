#include <bits/stdc++.h>
using namespace std;

string cnt(string s){
    string x="";
    char a=s[0];
    int k=0;
    
    for(int i=0;i<s.length();i++){
        if(s[i]==a)
        {
            k++;
        }else
        {
            x+=to_string(k)+a;
            a=s[i];
            k=1;
        }
    }
    x+=to_string(k)+a;
    return x;
}

string countAndSay(int n) {
    if(n==1)
        return to_string(n);
    return cnt(countAndSay(n-1));
}