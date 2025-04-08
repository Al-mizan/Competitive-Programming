#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<vector<ll>> prefixSum2D(vector<vector<ll>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<ll>> psum(n, vector<ll>(m));
 
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        psum[i][j] = mat[i][j];
        if (i > 0) psum[i][j] += psum[i - 1][j];
        if (j > 0) psum[i][j] += psum[i][j - 1];
        if (i > 0 && j > 0) psum[i][j] -= psum[i - 1][j - 1];
    }
    return psum;
}
 
int main() {
    int rows, cols, q;
    cin >> rows;
    cin >> q;
    cols = rows;
    vector<vector<ll>> mat(rows, vector<ll>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
 
    vector<vector<ll>> psum2D = prefixSum2D(mat);
    
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        if(x1+y1 > x2+y2) swap(x1, x2), swap(y1, y2);
 
        ll ans = psum2D[x2][y2];
        if (x1 > 0) ans -= psum2D[x1 - 1][y2];
        if (y1 > 0) ans -= psum2D[x2][y1 - 1];
        if (x1 > 0 && y1 > 0) ans += psum2D[x1 - 1][y1 - 1];
        
        cout << ans << endl;
    }
    return 0;
}
