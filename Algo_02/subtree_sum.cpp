#include <bits/stdc++.h>
using namespace std;

vector<int> subtreeSum, values;

void dfs(int node, int parent, vector<vector<int>>& adj) {
    subtreeSum[node] = values[node];
    for (int v : adj[node]) {
        if (v != parent) {
            dfs(v, node, adj);
            subtreeSum[node] += subtreeSum[v];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    values.resize(n);
    subtreeSum.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    dfs(0, -1, adj);
    int q;
    cin >> q;
    cout << endl;
    while (q--) {
        int u;
        cin >> u;
        u--;
        cout << subtreeSum[u] << endl;
    }
    return 0;
}
