#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    // Helper function for DFS
    void dfs(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;

        // Visit all adjacent vertices
        for (int u : adj[v]) {
            if (!visited[u])
                dfs(u, visited, Stack);
        }

        // Push the vertex into the stack after visiting its neighbors
        Stack.push(v);
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // Function to perform topological sort
    void topologicalSort() {
        stack<int> Stack;
        vector<bool> visited(V, false);

        // Perform DFS for all unvisited vertices
        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs(i, visited, Stack);

        // Print topological order (stored in the stack)
        cout << "Topological Sort: ";
        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout << endl;
    }
};

int main() {
    // Example usage:
    int n, m;
    cin >> n >> m;
    Graph g(n);
    while(n--) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }

    cout << "Topological sort of the given graph:\n";
    g.topologicalSort();

    return 0;
}
