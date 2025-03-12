#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st) {
    vis[node] = true;
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adj, vis, st);
        }
    }
    st.push(node);
}

void topologicalSort(vector<int> adj[], int n) {
    vector<bool> vis(n + 1, false); 
    stack<int> st; // Stack to store the topological order

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    topologicalSort(adj, n);

    return 0;
}