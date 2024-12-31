#include<bits/stdc++.h>
using namespace std;

int n, m;
void floyed_warshel(vector<vector<int>>& arr) {
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][k] != INT_MAX && arr[k][j]!= INT_MAX && arr[i][j] > arr[i][k] + arr[k][j]) 
                    arr[i][j] = arr[i][k] + arr[k][j];
            }

        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == INT_MAX) cout << "INF ";
            else
                cout << arr[i][j] << " ";   
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(n,INT_MAX));
    for (int i = 0; i < n; i++) {
        arr[i][i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        arr[u][v] = w;
    }
    floyed_warshel(arr);
    return 0;
}