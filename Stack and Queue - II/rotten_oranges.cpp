#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& grid, int x, int y, int row, int col) {
    if(x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 1) {
        return true;
    }
    return false;
}

int orangesRotting(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    int fresh = 0, time = 0;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(grid[i][j] == 2) {
                q.push({i, j});
            } else if(grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    
    if(fresh == 0) {
        return 0;
    }
    
    while(!q.empty()) {
        int qs = q.size(), count = 0;
        while(qs != 0) {
            auto p = q.front();
            q.pop();
            qs--;
            
            int x = p.first;
            int y = p.second;
            
            int x_dir[4] = {1, -1, 0, 0};
            int y_dir[4] = {0, 0, 1, -1};
            
            for(int i = 0; i < 4; i++) {
                int x_cord = x + x_dir[i];
                int y_cord = y + y_dir[i];
                
                if(isValid(grid, x_cord, y_cord, row, col)) {
                    count++;
                    grid[x_cord][y_cord] = 2;
                    q.push({x_cord, y_cord});
                }
            }
        }
        if(count != 0) {time++;}
    }
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(grid[i][j] == 1) {
                time = 0;
                break;
            }
        }
    }
    
    return (time == 0) ? -1 : time;
}