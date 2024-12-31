#include <iostream>
#include <vector>
using namespace std;

#define INF 99999  // A large number representing infinity

// Function to print the solution matrix
void printSolution(const vector<vector<int>>& dist, int V) {
    cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to implement Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist = graph;  // Copying the input graph to a distance matrix

    // Applying Floyd Warshall Algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Update dist[i][j] if a shorter path is found
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Printing the shortest distance matrix
    printSolution(dist, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Running the Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}
