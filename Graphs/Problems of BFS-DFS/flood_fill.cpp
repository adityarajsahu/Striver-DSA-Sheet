#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc] == color) {
        return image;
    }
    
    int row = image.size(), col = image[0].size();
    queue<pair<pair<int, int>, int>> q;
    q.push({{sr, sc}, image[sr][sc]});
    
    while(!q.empty()) {
        auto pixel = q.front();
        q.pop();
        int x = pixel.first.first;
        int y = pixel.first.second;
        int c = pixel.second;
        
        image[x][y] = color;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] >= 0 && x + dx[i] < row && y + dy[i] >= 0 && y + dy[i] < col && image[x + dx[i]][y + dy[i]] == c) {
                image[x + dx[i]][y + dy[i]] = color;
                q.push({{x + dx[i], y + dy[i]}, c});
            }
        }
    }
    return image;
}