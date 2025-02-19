#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll arr[200005], seg[4*200005];

void build(ll node, ll l, ll r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid + 1, r);
    seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
}

ll query(ll node, ll l, ll r, ll left, ll right) {
    if (r < left || l > right) return 1e9+5;  // No overlap
    if (l >= left && r <= right) return seg[node];  // Total overlap
    
    ll mid = (l + r) >> 1;
    ll leftQuery = query(2 * node + 1, l, mid, left, right);
    ll rightQuery = query(2 * node + 2, mid + 1, r, left, right);
    return min(leftQuery, rightQuery);
}

void update(ll node, ll l, ll r, ll idx, ll val) {
    if (l == r) {
        arr[idx] = val;
        seg[node] = val;
        return;
    }
    ll mid = (l + r) >> 1;
    if (idx <= mid) update(2 * node + 1, l, mid, idx, val);
    else update(2 * node + 2, mid + 1, r, idx, val);

    seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
}

void solve() {
    ll n;
    cin >> n;
    int q;
    cin >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(0, 0, n - 1);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll idx, val;
            cin >> idx >> val;
            update(0, 0, n - 1, idx-1, val);
        } 
        else {
            ll left, right;
            cin >> left >> right;
            cout << query(0, 0, n - 1, left-1, right-1) << endl;
        }
    }
}
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
