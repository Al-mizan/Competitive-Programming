#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dijkstra(vector<pair<ll,ll>> adj[], ll s, ll n) {
    vector<ll> dist(n+1,LLONG_MAX);
    vector<bool> visited(n+1, false);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll> >> pq;
    pq.push({0,s});
    dist[s]=0;

    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true; 
        for (auto x : adj[u]) {
            ll v = x.first;
            ll weight = x.second;
            if (dist[u] != LLONG_MAX && dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> adj[n+1];
    for(ll i=0;i<m;i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
    }
    dijkstra(adj, 1, n);
    return 0;
}