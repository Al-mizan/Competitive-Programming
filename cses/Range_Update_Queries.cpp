#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll arr[200005], seg[4*200005], lazy[4*200005];

void build(ll node, ll l, ll r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid + 1, r);
    seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}

void propagate(ll node, ll l, ll r) {
    if (lazy[node] != 0) {
        seg[node] += (r - l + 1) * lazy[node];

        if (l != r) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll query(ll node, ll l, ll r, ll left, ll right) {
    propagate(node, l, r);

    if (r < left || l > right) return 0;  // No overlap
    if (l >= left && r <= right) return seg[node];  // Total overlap

    ll mid = (l + r) >> 1;
    ll leftQuery = query(2 * node + 1, l, mid, left, right);
    ll rightQuery = query(2 * node + 2, mid + 1, r, left, right);
    return leftQuery + rightQuery;
}

void update(ll node, ll l, ll r, ll left, ll right, ll val) {
    propagate(node, l, r);

    if (r < left || l > right) return;
    if (l >= left && r <= right) { // Apply the update lazily
        seg[node] += (r - l + 1) * val;
        if (l != r) {
            lazy[2 * node + 1] += val;
            lazy[2 * node + 2] += val;
        }
        return;
    }

    ll mid = (l + r) >> 1;
    update(2 * node + 1, l, mid, left, right, val);
    update(2 * node + 2, mid + 1, r, left, right, val);
    seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
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
            ll left, right, val;
            cin >> left >> right >> val;
            update(0, 0, n-1, left-1, right-1, val);
        } 
        else {
            ll left;
            cin >> left;
            cout << query(0, 0, n-1, left-1, left-1) << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}