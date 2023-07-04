#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<bool> vis(V, false);
    queue<int> q;
    vector<int> bfs;
    
    q.push(0); 
    vis[0] = true;
    
    while(!q.empty()) {
        int node = q.front(); 
        q.pop(); 
        bfs.push_back(node); 
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = true; 
                q.push(it); 
            }
        }
    }
    return bfs; 
}