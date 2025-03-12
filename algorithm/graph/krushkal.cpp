#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
};

// A structure to represent a graph
struct Graph {
    int V, E; // V is the number of vertices, E is the number of edges
    vector<Edge> edges; // Collection of all edges
};

// Function to add an edge to the graph
void addEdge(Graph& graph, int u, int v, int weight) {
    graph.edges.push_back({u, v, weight});
}

// Find function for Disjoint Set (with path compression)
int findParent(vector<int>& parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

// Union function for Disjoint Set (with union by rank)
void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Function to perform Kruskal's algorithm to find the MST
void kruskalMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> result; // To store the edges in the MST
    int mst_weight = 0; // Total weight of the MST

    // Sort all edges by their weight
    sort(graph.edges.begin(), graph.edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    // Initialize Disjoint Set
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Pick edges one by one and include them in the MST if they don't form a cycle
    for (Edge& edge : graph.edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        // Find the parents (or representatives) of the two vertices
        int set_u = findParent(parent, u);
        int set_v = findParent(parent, v);

        // If including this edge does not form a cycle, include it in the result
        if (set_u != set_v) {
            result.push_back(edge);
            mst_weight += weight;
            unionSets(parent, rank, set_u, set_v);
        }
    }

    // Print the edges of the MST
    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    for (Edge& edge : result)
        cout << edge.u << " - " << edge.v << "    " << edge.weight << "\n";
    cout << "Total weight of the MST: " << mst_weight << "\n";
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph;
    graph.V = V;
    graph.E = E;

    cout << "Enter the edges in the format (u, v, weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        addEdge(graph, u, v, weight);
    }

    // Perform Kruskal's algorithm
    kruskalMST(graph);

    return 0;
}
