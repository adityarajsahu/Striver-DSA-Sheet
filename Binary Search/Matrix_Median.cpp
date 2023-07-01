#include <bits/stdc++.h>
using namespace std;

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

    int count = 0;
    for(int i = 0; i < n; i++) {
        minHeap.push({matrix[i][0], {i, 0}});
    }

    int median;
    while(true) {
        auto p = minHeap.top();
        minHeap.pop();

        count++;
        if(count == (n * m) / 2 + 1) {
            median = p.first;
            break;
        }

        if(p.second.second < m - 1) {
            minHeap.push({matrix[p.second.first][p.second.second + 1], {p.second.first, p.second.second + 1}});
        }
    }
    return median;
}