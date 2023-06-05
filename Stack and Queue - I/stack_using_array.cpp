#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
    private:
        T *data;
        int next_idx;
        int capacity;

    public:
        Stack(int total_size) {
            data = new T[total_size];
            next_idx = 0;
            capacity = total_size;
        }

        int size() {
            return next_idx;
        }

        bool is_empty() {
            return next_idx == 0;
        }

        void push(T val) {
            if(next_idx == capacity) {
                cout << "Stack is full.....\n";
                return;
            }
            data[next_idx] = val;
            next_idx++;
        }

        void pop() {
            if(is_empty()) {
                cout << "Stack is empty....\n";
                return;
            }
            next_idx--;
        }

        T top() {
            if(is_empty()) {
                cout << "Stack is empty....\n";
                return 0;
            }
            return data[next_idx - 1];
        }
}