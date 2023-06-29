#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(int row, int col, int n, vector<string>& board) {
        for(int i = row - 1; i >= 0; i-- ) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        
        for(int i = 1; i <= row; i++) {
            if(col - i >= 0) {
                if(board[row - i][col - i] == 'Q') {
                    return false;
                }
            }
            
            if(col + i < n) {
                if(board[row - i][col + i] == 'Q') {
                    return false;
                }
            }
        }
        return true;
    }
    
    void nQueenUtil(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(isPossible(row, i, n, board)) {
                board[row][i] = 'Q';
                nQueenUtil(row + 1, n, board, ans);
                board[row][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        string str;
        str.append(n, '.');
        vector<string> board(n, str);
        
        nQueenUtil(0, n, board, ans);
        return ans;
    }
};