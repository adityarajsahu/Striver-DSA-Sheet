#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
    
    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto n : adj[node]) {
            indegree[n]--;
            if(indegree[n] == 0) {
                q.push(n);
            }
        }
    }
    
    if(ans.size() == numCourses) {
        return ans;
    }
    return {};
}