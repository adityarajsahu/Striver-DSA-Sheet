#include<bits/stdc++.h>
using namespace std;

class Stack {
    private:
        queue <int> q;

    public:
        void push(int x) {
            int s = q.size();
            q.push(x);
            for (int i = 0; i < s; i++) {

                q.push(q.front());
                q.pop();
            }
        }

        void pop() {
            q.pop();
        }

        int top() {
            return q.front();
        }

        int size() {
            return q.size();
        }
};