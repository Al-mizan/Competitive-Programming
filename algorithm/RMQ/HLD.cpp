#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN], segtree(4 * MAXN), subtree_size(MAXN);
vector<int> parent(MAXN), depth(MAXN), heavy(MAXN, -1);
vector<int> head(MAXN), pos(MAXN), values(MAXN);
int cur_pos = 0, n;

void build_segtree(int node, int start, int end) {
    if (start == end) {
        segtree[node] = values[start];
        return;
    }
    int mid = (start + end) / 2;
    build_segtree(2 * node, start, mid);
    build_segtree(2 * node + 1, mid + 1, end);
    segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
}

void update_segtree(int node, int start, int end, int idx, int val) {
    if (start == end) {
        segtree[node] = val;
        values[idx] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
        update_segtree(2 * node, start, mid, idx, val);
    else
        update_segtree(2 * node + 1, mid + 1, end, idx, val);
    segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
}

int query_segtree(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return INT_MIN;
    if (l <= start && end <= r)
        return segtree[node];
    int mid = (start + end) / 2;
    return max(query_segtree(2 * node, start, mid, l, r),
              query_segtree(2 * node + 1, mid + 1, end, l, r));
}

// Heavy-Light Decomposition
void dfs(int v, int p = -1) {
    subtree_size[v] = 1;
    int max_child_size = 0;
    
    for (int u : adj[v]) {
        if (u == p) continue;
        parent[u] = v;
        depth[u] = depth[v] + 1;
        dfs(u, v);
        subtree_size[v] += subtree_size[u];
        if (subtree_size[u] > max_child_size) {
            max_child_size = subtree_size[u];
            heavy[v] = u;
        }
    }
}

void decompose(int v, int h, int p = -1) {
    head[v] = h;
    pos[v] = cur_pos++;
    
    if (heavy[v] != -1)
        decompose(heavy[v], h, v);
    
    for (int u : adj[v]) {
        if (u != p && u != heavy[v])
            decompose(u, u, v);
    }
}

void initHLD() {
    cur_pos = 0;
    parent[0] = -1;
    depth[0] = 0;
    dfs(0);
    decompose(0, 0);
    build_segtree(1, 0, n - 1);
}

// Query the maximum value on the path from a to b
int query(int a, int b) {
    int res = INT_MIN;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]])
            swap(a, b);
        int chain_head = head[a];
        res = max(res, query_segtree(1, 0, n - 1, pos[chain_head], pos[a]));
        a = parent[chain_head];
    }
    
    if (depth[a] > depth[b])
        swap(a, b);
    res = max(res, query_segtree(1, 0, n - 1, pos[a], pos[b]));
    return res;
}

// Update value at vertex idx
void update(int idx, int val) {
    update_segtree(1, 0, n - 1, pos[idx], val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    initHLD();

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx, val;
            cin >> idx >> val;
            update(idx - 1, val);
        } 
        else {
            int u, v;
            cin >> u >> v;
            cout << query(u - 1, v - 1) << '\n';
        }
    }
    
    return 0;
}
