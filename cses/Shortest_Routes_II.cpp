#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m, q;
void floyed_warshel(vector<vector<int>>& arr) {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(arr[i][k] != LLONG_MAX && arr[k][j]!= LLONG_MAX && arr[i][j] > arr[i][k] + arr[k][j]) 
                    arr[i][j] = arr[i][k] + arr[k][j];
            }

        }
    }
}

int32_t main() {
    cin >> n >> m >> q;
    vector<vector<int>> arr(n+1,vector<int>(n+1,LLONG_MAX));
    for (int i = 1; i <= n; i++) {
        arr[i][i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        arr[u][v] = min(w,arr[u][v]);
        arr[v][u] = min(w,arr[v][u]);
    }
    floyed_warshel(arr);

    while(q--) {
        int a,b;
        cin >> a >> b;
        if(arr[a][b] == LLONG_MAX) cout << -1 << endl;
        else cout << arr[a][b] << endl;
    }
    return 0;
}