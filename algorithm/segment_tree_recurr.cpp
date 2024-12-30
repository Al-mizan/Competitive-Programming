#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl            '\n'
#define ff              first
#define ss              second
#define pi              acos(-1)
#define mod             1000000007 
#define newline         cout << '\n'
#define no              cout << "NO\n"
#define yes             cout << "YES\n"
#define all(A)          A.begin(), A.end()
#define rall(x)         x.rbegin(), x.rend()
#define mem(a,n)        memset(a, n, sizeof(a))
#define setPre(n)       fixed << setprecision(n)
#define cases(tc)       cout << "Case #" << tc << ": "
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

ll arr[100005], seg[4*100005];

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

ll query(ll node, ll l, ll r, ll left, ll right) {
    if (r < left || l > right) return 0;  // No overlap
    if (l >= left && r <= right) return seg[node];  // Total overlap
    
    ll mid = (l + r) >> 1;
    ll leftQuery = query(2 * node + 1, l, mid, left, right);
    ll rightQuery = query(2 * node + 2, mid + 1, r, left, right);
    return leftQuery + rightQuery;
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

    seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}

void solve() {
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(0, 0, n - 1);
    int q;
    cin >> q;
    while (q--) {
        char type;
        cin >> type;
        if (type == 'U') {
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
