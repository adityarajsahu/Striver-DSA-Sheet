#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(it, adj, vis, pathVis)) {
                return true;
            }
        } else if (pathVis[it]) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V);
    vector<int> pathVis(V);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, pathVis)) {
                return true;
            }
        }
    }
    return false;
}