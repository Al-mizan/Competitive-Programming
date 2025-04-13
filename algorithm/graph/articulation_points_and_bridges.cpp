#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> adj[N];
bool visited[N];      
int tin[N], low[N];
bool isArticulation[N];
vector<pair<int, int>> bridges;
int timer = 0;

void dfs(int v, int p) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;

    for (int u : adj[v]) {
        if (u == p) continue;
        if (visited[u]) { // Back edge
            low[v] = min(low[v], tin[u]);
        }
        else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (p != -1 && low[u] >= tin[v]) isArticulation[v] = true;  // Articulation point
            if (low[u] > tin[v]) bridges.push_back({v, u});  // Bridge
            children++;
        }
    }
    if (p == -1 && children > 1) {  // for root node
        isArticulation[v] = true;
    }
}

void findArticulationPointsAndBridges(int n) {
    memset(visited, false, sizeof(visited));
    memset(isArticulation, false, sizeof(isArticulation));
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    timer = 0;
    bridges.clear();

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findArticulationPointsAndBridges(n);

    cout << "Articulation Points:\n";
    for (int i = 0; i < n; i++) {
        if (isArticulation[i]) {
            cout << i << "\n";
        }
    }

    cout << "Articulation Bridges:\n";
    for (auto bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << "\n";
    }

    return 0;
}
