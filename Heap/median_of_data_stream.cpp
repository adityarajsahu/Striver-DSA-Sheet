#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.empty() || num <= mx.top()) {
            mx.push(num);
        } else {
            mn.push(num);
        }
        
        if(mx.size() > mn.size() + 1) {
            mn.push(mx.top());
            mx.pop();
        } else if(mn.size() > mx.size()) {
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        if(mx.size() == mn.size()) {
            return((double)(mx.top()) + (double)(mn.top())) / 2.0;
        }
        return mx.top();
    }
};
