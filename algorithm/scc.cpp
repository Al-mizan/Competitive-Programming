#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<vector<int>> adjT; // Transposed graph

    void dfs1(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u])
                dfs1(u, visited, Stack);
        }
        Stack.push(v);
    }

    void dfs2(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adjT[v]) {
            if (!visited[u])
                dfs2(u, visited);
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        adjT.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);   // Original graph
        adjT[w].push_back(v);  // Transposed graph (reverse edge)
    }

    void findSCCs() {
        stack<int> Stack;
        vector<bool> visited(V, false);

        // Step 1: Perform DFS and store vertices in stack according to their finish time
        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs1(i, visited, Stack);

        // Step 2: Reset visited array for the second DFS on transposed graph
        fill(visited.begin(), visited.end(), false);

        // Step 3: Process all vertices in order defined by stack
        while (!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();
            if (!visited[v]) {
                cout << "SCC: ";
                dfs2(v, visited);  // Perform DFS on the transposed graph
                cout << endl;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    while(n--) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }

    cout << "Strongly Connected Components are:\n";
    g.findSCCs();

    return 0;
}
