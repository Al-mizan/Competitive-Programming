#include <bits/stdc++.h>
using namespace std;

const int N = 200005; // Maximum number of nodes
vector<int> adj[N];   // Adjacency list
bool visited[N];      
int tin[N], low[N];   // Discovery & Lowest reachable time
bool isArticulation[N]; // Stores articulation points
vector<pair<int, int>> bridges; // Stores bridges
int timer = 0;

void dfs(int v, int p, int &rootChildren) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;

    for (int to : adj[v]) {
        if (to == p) continue; // Ignore parent edge
        
        if (visited[to]) { // Back edge
            low[v] = min(low[v], tin[to]);
        }
        else { // Forward edge
            dfs(to, v, rootChildren);
            low[v] = min(low[v], low[to]);

            // Articulation Point Condition (Non-root)
            if (p != -1 && low[to] >= tin[v]) {
                isArticulation[v] = true;
            }

            // Articulation Bridge Condition
            if (low[to] > tin[v]) {
                bridges.push_back({v, to});
            }

            children++;
        }
    }

    // Special case for root node
    if (p == -1 && children > 1) {
        isArticulation[v] = true;
        rootChildren = children;
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
            int rootChildren = 0;
            dfs(i, -1, rootChildren);
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
