#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& isConnected, int V, int vertex, vector<bool>& vis) {
    vis[vertex] = true;
    for(int i = 0; i < V; i++) {
        if(i == vertex) {
            continue;
        }

        if(isConnected[vertex][i] == 1) {
            if(vis[i]) {
                continue;
            }
            dfs(isConnected, V, i, vis);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int count = 0;
    int V = isConnected.size();

    vector<bool> vis(V, false);

    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            count++;
            dfs(isConnected, V, i, vis);
        }
    }
    return count;
}