#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200009;
vector<int> adj[MAXN];
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> v;
    
    visited.assign(n, false);
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            v.push_back(i+1);
        }
    }
    cout << v.size()-1 << '\n';
    for (int i = 0; i < v.size()-1; i++) {
        cout << v[i] << ' ' << v[i+1] << '\n';
    }
    
    return 0;
}
