#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int s, int n, vector<int>& vis, vector<int>& col) {
    vis[s] = 1;
    for(auto& it: adj[s]) {
        if(!vis[it]) {
            col[it] = col[s]^1;
            if(!dfs(adj, it, n, vis, col)) {
                return false;
            }
        }
        else if(col[it] == col[s]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n+1,0), col(n+1,-1);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            col[i] = 0;
            if(!dfs(adj, i, n, vis, col)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        cout << col[i]+1 << ' ';
    }
    cout << '\n';

    return 0;
}