#include<bits/stdc++.h>
using namespace std;

bool bfs1(vector<int> adj[], int s, int n, vector<int>& par) {
    vector<int> vis(n+1,0);
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto it: adj[x]) {
            if(!vis[it]) {
                vis[it]=1;
                q.push(it);
                par[it] = x;
            }
        }
    }
    return vis[n];

}

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1], par(n+1, -1);
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(!bfs1(adj, 1, n, par)) cout << "IMPOSSIBLE\n";
    else {
        vector<int> ans;
        while(n!=-1) {
            ans.push_back(n);
            n = par[n];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto it: ans) cout << it << " ";
    }

    return 0;
}