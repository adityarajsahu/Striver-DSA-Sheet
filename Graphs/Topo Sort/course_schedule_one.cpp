#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    
    for(int i = 0; i < prerequisites.size(); i++) {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    
    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < numCourses; i++) {
        for (auto v : adj[i]) {
            indegree[v]++;
        }
    }
    
    queue<int> q;
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    
    int count = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        
        for(auto n : adj[node]) {
            indegree[n]--;
            if(indegree[n] == 0) {
                q.push(n);
            }
        }
    }
    
    if(count == numCourses) {
        return true;
    }
    return false;
}