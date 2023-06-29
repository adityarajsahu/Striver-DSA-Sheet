#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(vector<vector<char>>& board, int i, int j, char val) {
        int sRow = (i / 3) * 3;
        int sCol = (j / 3) * 3;

        for(int k = 0; k < 9; k++){
            if(board[i][k] == val) {
                return false;
            }
            if(board[k][j] == val) {
                return false;
            }

            if(board[k/3 + sRow][k%3 + sCol] == val) {
                return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int row, int col) {
        if(row == 9) {
            return true;
        }

        if(board[row][col] == '.') {
            for(char ch ='1'; ch <= '9'; ch++) {
                if(isValid(board, row, col, ch)) {
                    board[row][col] = ch;
                    if(col < 8) {
                        if(solve(board, row, col + 1)) {
                            return true;
                        }
                    }
                    else if(solve(board, row + 1, 0)) {
                        return true;
                    }
                    board[row][col] = '.';
                }
            }
        } else {
            if(col < 8) {
                if(solve(board, row, col+1)) {
                    return true;
                }
            } else if(solve(board, row + 1, 0)) {
                return true;
            }
        }
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};