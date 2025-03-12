#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int s, int n, vector<int>& vis) {
    vis[s] = 1;
    for(auto& it: adj[s]) {
        if(!vis[it]) {
            dfs(adj, it, n, vis);
        }
    }
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
    int s;
    cin >> s;
    vector<int> vis(n,0);
    dfs(adj, s, n, vis);
    return 0;
}