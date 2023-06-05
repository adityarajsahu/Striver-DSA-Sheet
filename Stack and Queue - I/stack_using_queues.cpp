#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q;
    queue<int> temp;
    int topElem;
public:
    MyStack() {
        topElem = -1;
    }
    
    void push(int x) {
        q.push(x);
        topElem = x;
    }
    
    int pop() {
        while(q.size() > 1) {
            int front = q.front();
            q.pop();
            temp.push(front);
        }
        
        int ans = q.front();
        q.pop();
        while(!temp.empty()) {
            if(temp.size() == 1) {
                topElem = temp.front();
            }
            q.push(temp.front());
            temp.pop();
        }
        return ans;
    }
    
    int top() {
        return topElem;
    }
    
    bool empty() {
        return q.empty();
    }
};