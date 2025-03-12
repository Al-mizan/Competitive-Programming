#include <bits/stdc++.h>
using namespace std;

vector<long long> BIT;
int n;

void update(int idx, long long val) {
    if (idx < 0 || idx >= n) return;
    for (++idx; idx <= n; idx += idx & -idx) {
        BIT[idx] += val;
    }
}

long long query(int idx) {
    long long sum = 0;
    for (++idx; idx > 0; idx -= idx & -idx) {
        sum += BIT[idx];
    }
    return sum;
}

long long rangeQuery(int l, int r) {
    if (l > r || l < 0 || r >= n) return 0;
    return query(r) - (l > 0 ? query(l - 1) : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    BIT.assign(n + 1, 0);
    vector<int> values(n);
    
    for (int i = 0; i < n; i++) {
        cin >> values[i];
        update(i, values[i]);
    }
    
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx, val;
            cin >> idx >> val;
            idx--;
            int diff = val - values[idx];
            values[idx] = val;
            update(idx, diff);
        } 
        else if (type == 2) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << rangeQuery(l, r) << '\n';
        }
    }
    return 0;
}