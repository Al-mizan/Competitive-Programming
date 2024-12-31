#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// A structure to represent a node in the priority queue
typedef pair<int, int> iPair;

// Function to add an edge to the adjacency list
void addEdge(vector<vector<iPair>>& adj, int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w)); // Undirected graph
}

// Function to perform Prim's algorithm to find the Minimum Spanning Tree (MST)
void primMST(int V, vector<vector<iPair>>& adj) {
    // Priority queue to store vertices that are being processed (min-heap)
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // Vector to store the minimum cost of adding a vertex to the MST
    vector<int> key(V, INT_MAX);

    // Array to store the parent node in the MST
    vector<int> parent(V, -1);

    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);

    // Start with the first vertex, initialize its key value to 0
    int startVertex = 0;
    pq.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the smallest key value
        pq.pop();

        inMST[u] = true; // Include u in MST

        // Traverse all adjacent vertices of u
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If v is not in the MST and the weight of u-v is smaller than the current key value of v
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    // Print the edges of the MST
    cout << "Edge   Weight\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "    " << key[i] << "\n";
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<iPair>> adj(V); // Adjacency list to store the graph

    cout << "Enter the edges in the format (u, v, weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(adj, u, v, w);
    }

    // Perform Prim's algorithm to find the MST
    primMST(V, adj);

    return 0;
}
