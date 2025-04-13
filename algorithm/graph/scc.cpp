#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20000 + 10;
vector<int> adj[MAXN], adjT[MAXN];
vector<bool> visited;
stack<int> st;

void dfs1(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs1(u);
    }
    st.push(v);
}

void dfs2(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int u : adjT[v]) {
        if (!visited[u])
            dfs2(u);
    }
}

void findSCCs(int n) {
    if (n <= 0) return;
    visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs1(i);
    }

    fill(visited.begin(), visited.end(), false);

    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (!visited[v]) {
            dfs2(v);
            cout << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adjT[y].push_back(x);
    }
    
    cout << endl;
    findSCCs(n);
    
    return 0;
}
