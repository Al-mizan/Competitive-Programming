#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Structure to represent a weighted edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to implement Bellman-Ford algorithm
void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    // Step 1: Initialize distances from src to all other vertices as INFINITE
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles.
    // The above step guarantees the shortest distances if the graph doesn't
    // contain negative weight cycle. If we get a shorter path, then there
    // is a cycle.
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }

    // Print the calculated shortest distances
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << " \t\t" << "INF" << endl;
        else
            cout << i << " \t\t" << dist[i] << endl;
    }
}

int main() {
    int V, E, src;
    
    cout << "Enter the number of vertices: ";
    cin >> V;
    
    cout << "Enter the number of edges: ";
    cin >> E;
    
    vector<Edge> edges(E);
    
    cout << "Enter the edges in the format (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    // Call the Bellman-Ford algorithm
    bellmanFord(V, E, edges, src);

    return 0;
}
