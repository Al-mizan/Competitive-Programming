#include<bits/stdc++.h>
using namespace std;

struct bf {
    int u,v,w;
};

void bell(vector<bf>& arr, int s, int n, int m) {
    vector<int> dist(n,INT_MAX);
    dist[s] = 0;
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m; j++) {
            int u = arr[j].u;
            int v = arr[j].v;
            int w = arr[j].w;
            if(dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int j=0; j<m; j++) {
        int u = arr[j].u;
        int v = arr[j].v;
        int w = arr[j].w;
        if(dist[u] != INT_MAX && dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }
    for(int j=0; j<n; j++) {
        cout << "Vertex " << j+1 << " \tDistance from source " << s << " is " << dist[j] << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<bf> arr(m);
    for(int i=0; i<m; i++) {
        cin >> arr[i].u >> arr[i].v >> arr[i].w;
    }
    int s;
    cin >> s;
    bell(arr, s, n, m);
    return 0;
}