#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        while(!s.empty() && price >= s.top().first) {
            count += s.top().second;
            s.pop();
        }
        s.push({price, count});
        return count;
    }
};