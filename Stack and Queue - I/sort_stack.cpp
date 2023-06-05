#include <bits/stdc++.h>
using namespace std;

void sort() {
   stack<int> temp;
   while(!s.empty()) {
       int curr = s.top();
       s.pop();
       
       while(!temp.empty() && temp.top() > curr) {
           s.push(temp.top());
           temp.pop();
       }
       
       temp.push(curr);
   }
   
   s = temp;
}