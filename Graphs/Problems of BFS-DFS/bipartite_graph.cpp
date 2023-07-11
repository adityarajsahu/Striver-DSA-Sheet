#include <bit/stdc++.h>
using namespace std;

bool dfs(int node, int c, vector<int>& color, vector<vector<int>>& graph) {
    color[node] = c;
    
    for(auto n : graph[node]) {
        if(color[n] == -1) {
            if(dfs(n, !c, color, graph) == false) {
                return false;
            }
        } else if(color[n] == c) {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V, -1);
    
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            if(!dfs(i, 0, color, graph)) {
                return false;
            }
        }
    }
    return true;
}