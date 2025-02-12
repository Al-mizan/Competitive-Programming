#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    ll h = log2(n) + 1;
    ll arr[h][n];
    for (int i = 0; i < n; i++)
        arr[0][i] = v[i];

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < n; j++) {
            if((j+(1 << i)-1) < n) {
                arr[i][j] = max(arr[i-1][j], arr[i-1][j + (1 << (i-1))]);
            }
        }
    }

    ll q;
    cin >> q;
    while(q--) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        ll pos = log2(r-l+1);

        cout << max(arr[pos][l], arr[pos][r-(1<<pos)+1]) << endl;
    }
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
