#include <bits/stdc++.h>
using namespace std;

void DFSUtil (int i, vector <int> adj[], int V, vector<bool>& vis, vector <int>& res)
{
    if (vis[i]) {
        return;
    }

    vis[i] = true;
    res.push_back (i);
    
    for (int j : adj[i])
    {
        if (!vis[j]) {
            DFSUtil(j, adj, V, vis, res);
        }
    }
}

vector <int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector <int> res;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            DFSUtil(i, adj, V, vis, res);
        }
    }
    
    return res;
}