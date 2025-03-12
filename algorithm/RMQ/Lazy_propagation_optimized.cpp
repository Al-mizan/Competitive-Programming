#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

struct SegmentTree {
    vector<ll> tree, lazyAdd, lazyIncrement;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazyAdd.assign(4 * n, 0);
        lazyIncrement.assign(4 * n, 0);
    }

    void push(int node, int start, int end) {
        if (lazyAdd[node] != 0 || lazyIncrement[node] != 0) {
            // Apply lazyAdd
            ll addVal = lazyAdd[node];
            ll incVal = lazyIncrement[node];
            ll len = (end - start + 1);

            // Update current node
            tree[node] += addVal * len + incVal * len * (len - 1) / 2;

            // Propagate to children if not a leaf node
            if (start != end) {
                int mid = (start + end) / 2;
                lazyAdd[2 * node + 1] += addVal;
                lazyIncrement[2 * node + 1] += incVal;
                lazyAdd[2 * node + 2] += addVal + incVal * (mid - start + 1);
                lazyIncrement[2 * node + 2] += incVal;
            }

            // Clear lazy values for the current node
            lazyAdd[node] = 0;
            lazyIncrement[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, ll addVal, ll incVal) {
        push(node, start, end);

        if (start > r || end < l) return; // No overlap

        if (start >= l && end <= r) { // Total overlap
            lazyAdd[node] += addVal + incVal * (start - l);
            lazyIncrement[node] += incVal;
            push(node, start, end);
            return;
        }

        // Partial overlap
        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, l, r, addVal, incVal);
        updateRange(2 * node + 2, mid + 1, end, l, r, addVal, incVal);

        // Update current node
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    ll queryRange(int node, int start, int end, int l, int r) {
        push(node, start, end);

        if (start > r || end < l) return 0;
        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        ll leftSum = queryRange(2 * node + 1, start, mid, l, r);
        ll rightSum = queryRange(2 * node + 2, mid + 1, end, l, r);
        return leftSum + rightSum;
    }

    void update(int l, int r, ll addVal, ll incVal) {
        updateRange(0, 0, n - 1, l, r, addVal, incVal);
    }

    ll query(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    SegmentTree segTree(n);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            // Update type 1: Array[i] += i for L <= i <= R
            int l, r;
            cin >> l >> r;
            segTree.update(l, r, l, 1);
        } else if (type == 2) {
            // Update type 2: Array[i] += (i - L + 1) for L <= i <= R
            int l, r;
            cin >> l >> r;
            segTree.update(l, r, 1, 1);
        } else if (type == 3) {
            // Query: Get sum of Array[L..R]
            int l, r;
            cin >> l >> r;
            cout << segTree.query(l, r) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
