#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    for(int i = 0; i < row; i++) {
        if(target == matrix[i][col - 1]) {
            return true;
        } else if(target < matrix[i][col - 1]) {
            for(int j = 0; j < col; j++) {
                if(target == matrix[i][j]) {
                    return true;
                }
            }
        }
    }
    return false;
}