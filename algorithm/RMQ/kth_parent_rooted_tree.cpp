#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>> up;
vector<int> depth;

void dfs(int node, int parent, vector<vector<int>>& adj) {
    up[node][0] = parent;
    
    for (int i = 1; i < LOG; i++) {
        if (up[node][i - 1] != -1)
            up[node][i] = up[up[node][i - 1]][i - 1];
        else
            up[node][i] = -1;
    }
    
    for (int v : adj[node]) {
        if (v != parent) {
            depth[v] = depth[node] + 1;
            dfs(v, node, adj);
        }
    }
}

int getKthParent(int node, int k) {
    if (k > depth[node]) return -1;

    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            node = up[node][i];
            if (node == -1) break;
        }
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    up.assign(n, vector<int>(LOG, -1));
    depth.assign(n, 0);
    dfs(0, -1, adj);
    
    int q;
    cin >> q;
    cout << endl;
    while (q--) {
        int u, k;
        cin >> u >> k;
        u--;
        int result = getKthParent(u, k);
        cout << (result == -1 ? -1 : result + 1) << '\n';
    }
    return 0;
}