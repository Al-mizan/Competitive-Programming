#include <bits/stdc++.h>
using namespace std;

void findAP(int u, int parent, int& timer, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, vector<bool>& ap) {
    static int time = 0;
    int children = 0;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (v == parent) continue;
        if (disc[v] == -1) {
            children++;
            findAP(v, u, timer, adj, disc, low, ap);
            low[u] = min(low[u], low[v]);

            if (parent == -1 && children > 1) ap[u] = true;
            if (parent != -1 && low[v] >= disc[u]) ap[u] = true;
        }
        else low[u] = min(low[u], disc[v]);
    }
}
vector<int> articulationPoints(int n, vector<vector<int>>& adj) {
    vector<int> disc(n, -1), low(n, -1);
    vector<bool> ap(n, false);

    for (int i = 0; i < n; i++) 
        if (disc[i] == -1) findAP(i, -1, i, adj, disc, low, ap);
    vector<int> result;

    for (int i = 0; i < n; i++) 
        if (ap[i]) result.push_back(i);
    
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ap = articulationPoints(n, adj);
    cout << endl;
    for (auto point : ap) 
        cout << point << ' ';
    cout << endl;
    
    return 0;
}
