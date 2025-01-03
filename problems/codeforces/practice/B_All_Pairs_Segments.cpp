#include <bits/stdc++.h>
using namespace std;
int start[10], finish[10];
// To add an edge in an undirected graph
void addEdge(vector<vector<int>> &adj, int s, int t){
    adj[s].push_back(t); 
    adj[t].push_back(s); 
}

// Recursive function for DFS traversal
void DFS(vector<vector<int>> &adj, vector<bool> &visited, int s){
  	static int time = 0;
    visited[s] = true;
    time = time +1;
	start[s] = time;
    cout << s << " - " << "sart time: " << time << endl;
    for (int i : adj[s]) {
        if (visited[i] == false)
            DFS(adj, visited, i);
    }
  time = time +1;
  finish[s] = time;
  cout << s << " - " << "finish time: " << time << endl;
}

int main(){
    int V = 5; 
    vector<vector<int>> adj(V);
  
    // Add edges
    vector<vector<int>> edges={{1, 2},{1, 0},{2, 0},{2, 3},{2, 4}};
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    vector<bool> visited(adj.size(), false);
    int s = 1; // Starting vertex for DFS
    cout << "DFS from source: " << s << endl;
    DFS(adj,visited, s); // Perform DFS starting from the source vertex
    return 0;
}
