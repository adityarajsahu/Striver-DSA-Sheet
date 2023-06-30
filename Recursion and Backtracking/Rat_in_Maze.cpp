#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
        bool isValid(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m) {
            if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
                return true;
            }
            return false;
        }
    
        void solve(int x, int y, int n, string path, vector<vector<int>>& visited, vector<vector<int>>& m, vector<string>& ans) {
            if(x == n - 1 && y == n - 1) {
                ans.push_back(path);
                return;
            }
            
            visited[x][y] = 1;
            
            if(isValid(x + 1, y, n, visited, m)) {
                path.push_back('D');
                solve(x + 1, y, n, path, visited, m, ans);
                path.pop_back();
            }
            
            if(isValid(x, y - 1, n, visited, m)) {
                path.push_back('L');
                solve(x, y - 1, n, path, visited, m, ans);
                path.pop_back();
            }
            
            if(isValid(x, y + 1, n, visited, m)) {
                path.push_back('R');
                solve(x, y + 1, n, path, visited, m, ans);
                path.pop_back();
            }
            
            if(isValid(x - 1, y, n, visited, m)) {
                path.push_back('U');
                solve(x - 1, y, n, path, visited, m, ans);
                path.pop_back();
            }
            
            visited[x][y] = 0;
        }
        
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(m[0][0] == 0) {
            return ans;
        }
        
        int x = 0, y = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        string path = "";
        solve(x, y, n, path, visited, m, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};