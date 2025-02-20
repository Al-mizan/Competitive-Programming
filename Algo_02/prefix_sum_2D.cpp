#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prefixSum2D(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> psum(n, vector<int>(m));

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        psum[i][j] = mat[i][j];
        if (i > 0) psum[i][j] += psum[i - 1][j];
        if (j > 0) psum[i][j] += psum[i][j - 1];
        if (i > 0 && j > 0) psum[i][j] -= psum[i - 1][j - 1];
    }
    return psum;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            cin >> mat[i][j];

    vector<vector<int>> psum2D = prefixSum2D(mat);
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
            cout << psum2D[i][j] << ' ';
        cout << endl;
    }
    
    return 0;
}