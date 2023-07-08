#include <bits/stdc++.h>
using namespace std;

void dfs(int m, int n, int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int x[], int y[]) {
    vis[row][col] = 1;
    for(int i = 0; i < 4; i++) {
        int r = row + x[i];
        int c = col + y[i];
        
        if(r >= 0 && c >= 0 && r < m && c < n && grid[r][c] == 1 && vis[r][c] == 0) {
            dfs(m, n, r, c, grid, vis, x, y);
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    
    int x[] = {-1, 1, 0, 0};
    int y[] = {0, 0, -1, 1};
    
    for(int i = 0; i < m; i++) {
        if(grid[i][0] == 1 && vis[i][0] == 0) {
            dfs(m, n, i, 0, grid, vis, x, y);
        }
        
        if(grid[i][n - 1] == 1 && vis[i][n - 1] == 0) {
            dfs(m, n, i, n - 1, grid, vis, x, y);
        }
    }
    
    for(int j = 0; j < n; j++) {
        if(grid[0][j] == 1 && vis[0][j] == 0) {
            dfs(m, n, 0, j, grid, vis, x, y);
        }
        
        if(grid[m - 1][j] == 1 && vis[m - 1][j] == 0) {
            dfs(m, n, m - 1, j, grid, vis, x, y);
        }
    }
    
    int count = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1 && vis[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}