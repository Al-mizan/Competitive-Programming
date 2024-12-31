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
    adj[v].push_back(make_pair(u, w)); // For undirected graph
}

// Function to perform Dijkstra's shortest path algorithm
void dijkstra(int V, vector<vector<iPair>>& adj, int src) {
    // Priority queue to store vertices that are being processed
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // Vector to store the shortest distance from the source to each vertex
    vector<int> dist(V, INT_MAX);

    // Insert source vertex into the priority queue and initialize its distance to 0
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the smallest distance
        pq.pop();

        // Traverse all adjacent vertices of u
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first; // Adjacent vertex
            int weight = neighbor.second; // Weight of edge u-v

            // If there is a shorter path to v through u
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print the calculated shortest distances from source
    cout << "Vertex Distance from Source " << src << "\n";
    for (int i = 0; i < V; ++i)
        cout << i << " \t\t " << dist[i] << "\n";
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m; // n is the number of vertices, m is the number of edges
    vector<vector<iPair>> adj(n); // Adjacency list to store the graph

    cout << "Enter the edges in the format (u, v, weight):\n";
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z; // Read edge from vertex x to vertex y with weight z
        addEdge(adj, x, y, z); // Add the edge to the adjacency list
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src; // Read the source vertex for Dijkstra's algorithm

    // Perform Dijkstra's algorithm from the source vertex
    dijkstra(n, adj, src);

    return 0;
}
