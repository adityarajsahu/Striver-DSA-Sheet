#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vector<vector<int>> ans(m, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> q;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!mat[i][j]) {
                vis[i][j] = true;
                q.push({{i, j}, 0});
            }
        }
    }
    
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int count = q.front().second;
        q.pop();
        
        if(x > 0 && !vis[x - 1][y] && mat[x - 1][y] == 1) {
            vis[x - 1][y] = true;
            q.push({{x - 1, y}, count + 1});
            ans[x - 1][y] = count + 1;
        }
        
        if(y > 0 && !vis[x][y - 1] && mat[x][y - 1] == 1) {
            vis[x][y - 1] = true;
            q.push({{x, y - 1}, count + 1});
            ans[x][y - 1] = count + 1;
        }
        
        if(x < m - 1 && !vis[x + 1][y] && mat[x + 1][y] == 1) {
            vis[x + 1][y] = true;
            q.push({{x + 1, y}, count + 1});
            ans[x + 1][y] = count + 1;
        }
        
        if(y < n - 1 && !vis[x][y + 1] && mat[x][y + 1] == 1) {
            vis[x][y + 1] = true;
            q.push({{x, y + 1}, count + 1});
            ans[x][y + 1] = count + 1;
        }
    }
    return ans;
}