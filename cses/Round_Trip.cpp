#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int s, int p, vector<int>& vis, vector<int>& par) {
    vis[s] = 1;
    par[s] = p;
    for(auto& it: adj[s]) {
        if(!vis[it]) {
            if(dfs(adj, it, s, vis, par)) 
                return true;
        }
        else if(it != p) {
            int x = s;
            vector<int> ans = {it};
            while(x != it) {
                ans.push_back(x);
                x = par[x];
            }
            ans.push_back(it);
            cout << ans.size() << '\n';
            for(auto i: ans)
                cout << i << ' ';
            return true;
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n+1,0), par(n+1,-1);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            if(dfs(adj, i, -1, vis, par))
                return 0;
        }
    }
    cout << "IMPOSSIBLE\n" << endl;
    
    return 0;
}