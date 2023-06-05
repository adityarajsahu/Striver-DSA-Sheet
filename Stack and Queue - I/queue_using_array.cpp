#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue {
    private:
        T *data;
        int next_idx;
        int first_idx;
        int size;
        int capacity;

    public:
        Queue(int total_size) {
            data = new t[total_size];
            next_idx = 0;
            first_idx = -1;
            size = 0;
            capacity = total_size;
        }

        int get_size() {
            return size;
        }

        bool is_empty() {
            return size == 0;
        }

        void enqueue(T val) {
            if(size == capacity) {
                cout << "Queue is full.....\n";
                return;
            }
            data[next_idx] = val;
            next_idx = (next_idx + 1) % capacity;
            if(first_idx == -1) {
                first_idx = 0;
            } 
            size++;
        }

        T front() {
            if(is_empty()) {
                cout << "Queue is empty.....\n";
                return 0;
            }
            return data[first_idx];
        }

        void dequeue() {
            if(is_empty()) {
                cout << "Queue is empty.....\n";
                return;
            }

            first_idx = (first_idx + 1) % capacity;
            size--;
            if(size == 0) {
                first_idx = -1;
                next_idx = 0;
            }
        }
}