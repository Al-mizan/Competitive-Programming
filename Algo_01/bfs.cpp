#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int s, int n) {
    vector<int> vis(n,0);
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(auto &it: adj[x]) {
            if(!vis[it]) {
                vis[it]=1;
                q.push(it);
            }
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s;
    cin >> s;
    bfs(adj, s, n);
    return 0;
}