#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<bool>& vis, vector<int> adj[]) {
    vis[node] = true;
    for(auto adjNode : adj[node]) {
        if(!vis[adjNode]) {
            if(dfs(adjNode, node, vis, adj)) {
                return true;
            }
        } else if(parent != adjNode) {
            return true;
        }
    }
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<bool> vis(V, false);
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, vis, adj)) {
                return true;
            }
        }
    }
    return false;
}