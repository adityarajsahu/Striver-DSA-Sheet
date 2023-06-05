#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s;
    stack<int> temp;
    int front;
    MyQueue() {
        front = -1;
    }
    
    void push(int x) {
        if(empty()) {
            front = x;
        }
        s.push(x);
    }
    
    int pop() {
        while(s.size() > 1) {
            temp.push(s.top());
            s.pop();
        }
        int ans = s.top();
        s.pop();
        
        if(!temp.empty()) {
            front = temp.top();
        }
        while(!temp.empty()) { 
            s.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return s.empty();
    }
};