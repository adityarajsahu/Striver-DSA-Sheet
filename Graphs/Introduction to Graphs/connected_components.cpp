#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int V, int vertex, vector<bool>& vis) {
    vis[vertex] = true;
    for(int i = 0; i < V; i++) {
        if(i == vertex) {
            continue;
        }
        
        if(adj[vertex][i] == 1) {
            if(vis[i]) {
                continue;
            }
            dfs(adj, V, i, vis);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    // code here
    int count = 0;
    
    vector<bool> vis(V, false);
    
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            count++;
            dfs(adj, V, i, vis);
        }
    }
    return count;
}