#include <bits/stdc++.h>
using namespace std;

// Function to perform topological sort using Kahn's Algorithm
void topologicalSortKahns(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);
    
    // Calculate in-degrees of all vertices
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Queue to store vertices with in-degree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoSort;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);

        // Reduce in-degree for adjacent vertices and push to queue if in-degree becomes 0
        for (int v : adj[node]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Check if a valid topological sort exists
    if (topoSort.size() != V) {
        cout << "Cycle detected, topological sort not possible" << endl;
    } else {
        cout << "Topological Sort (Kahn's Algorithm): ";
        for (int node : topoSort) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v for directed edge u -> v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    topologicalSortKahns(V, adj);

    return 0;
}
