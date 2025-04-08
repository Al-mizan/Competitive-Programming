#include <bits/stdc++.h>
using namespace std;

vector<int> subtree_sum, values;

void dfs(int node, int parent, vector<vector<int>>& adj) {
    subtree_sum[node] = values[node];
    for (int v : adj[node]) {
        if (v != parent) {
            dfs(v, node, adj);
            subtree_sum[node] += subtree_sum[v];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    values.resize(n);
    subtree_sum.resize(n);
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
        cout << subtree_sum[u] << endl;
    }
    return 0;
}
