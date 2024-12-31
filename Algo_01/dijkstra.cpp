#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int,int>> adj[], int s, int n) {
    vector<int> dist(n,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> >> pq;
    pq.push({0,s});
    dist[s]=0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for(auto& it: dist) cout << it << ' ';
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    int s;
    cin >> s;
    dijkstra(adj, s, n);
    return 0;
}