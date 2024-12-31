#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and store vertices according to their finish times
void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& finishStack) {
    visited[node] = true;
    for (int v : adj[node]) {
        if (!visited[v]) {
            dfs1(v, adj, visited, finishStack);
        }
    }
    finishStack.push(node); // Store the node after all its adjacent nodes are visited
}

// Function to perform DFS on the reversed graph and mark visited SCCs
void dfs2(int node, vector<vector<int>>& transposeAdj, vector<bool>& visited) {
    cout << node << " "; // Print node part of the current SCC
    visited[node] = true;
    for (int v : transposeAdj[node]) {
        if (!visited[v]) {
            dfs2(v, transposeAdj, visited);
        }
    }
}

// Kosaraju's Algorithm to find all SCCs
void kosarajuSCC(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> finishStack;

    // Step 1: Perform DFS and store vertices in finishStack by finish time
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, finishStack);
        }
    }

    // Step 2: Transpose the graph (reverse all edges)
    vector<vector<int>> transposeAdj(V);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            transposeAdj[v].push_back(u); // Reverse the edge u -> v to v -> u
        }
    }

    // Step 3: Perform DFS on the transposed graph in the order of finishStack
    fill(visited.begin(), visited.end(), false); // Reset visited for second DFS pass
    cout << "Strongly Connected Components (SCCs):" << endl;
    while (!finishStack.empty()) {
        int node = finishStack.top();
        finishStack.pop();
        if (!visited[node]) {
            // DFS to print the current SCC
            dfs2(node, transposeAdj, visited);
            cout << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V); // Adjacency list for the graph

    cout << "Enter edges (u v for directed edge u -> v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    kosarajuSCC(V, adj);

    return 0;
}
