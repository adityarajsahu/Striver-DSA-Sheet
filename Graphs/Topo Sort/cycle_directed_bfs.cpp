#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> indegree(V);
    for(int i = 0; i < V; i++) {
        for(auto v : adj[i]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while(!q.empty) {
        int node = q.front();
        q.pop();
        
        for(auto n : adj[node]) {
            indegree[n]--;
            if(indegree[n] == 0) {
                count++;
            }
        }
    }

    if(count == V) {
        return true;
    }
    return false;
}