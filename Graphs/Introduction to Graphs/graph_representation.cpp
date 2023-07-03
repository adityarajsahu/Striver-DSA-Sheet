#include <bits/stdc++.h>
using namespace std;

int main() {
    // n -> nodes, e -> edges
    int n, e; cin >> n >> e;

    // adjacency matrix representation
    vector<vector<int>> graph1(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < e; i++) {
        int src, des, weight; cin >> src >> des >> weight;
        graph1[src][des] = weight;
        graph1[des][src] = weight;
    }

    // adjacency list representation
    vector<pair<int, int>> graph2[n + 1];
    for(int i = 0; i < e; i++) {
        graph2[src].push_back({des, weight});
        graph2[des].push_back({src, weight});
    }

    return 0;
}