#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int row = matrix.size(), col = matrix[0].size();
    vector<int> v;
    
    for(int j = 0; j < col; j++)
    {
        for(int i = row-1; i >= 0; i--)
        {
            v.push_back(matrix[i][j]);
        }
    }
    
    int k = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            matrix[i][j] = v[k++];
        }
    }
    v.clear();
}