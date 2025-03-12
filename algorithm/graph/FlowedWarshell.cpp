#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
void floyed_warshel(vector<vector<int>>& arr) {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(arr[i][k] != LLONG_MAX && arr[k][j]!= LLONG_MAX && arr[i][j] > arr[i][k] + arr[k][j]) 
                    arr[i][j] = arr[i][k] + arr[k][j];
            }

        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == LLONG_MAX) cout << "INF ";
            else
                cout << arr[i][j] << " ";   
        }
        cout << endl;
    }
}

int32_t main() {
    cin >> n >> m;
    vector<vector<int>> arr(n+1,vector<int>(n+1,LLONG_MAX));
    for (int i = 1; i <= n; i++) {
        arr[i][i] = 0;  // 1 based indexing
    }
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        arr[u][v] = min(w,arr[u][v]); // directed
        // arr[v][u] = min(w,arr[v][u]); // undirected
    }
    floyed_warshel(arr);
    return 0;
}