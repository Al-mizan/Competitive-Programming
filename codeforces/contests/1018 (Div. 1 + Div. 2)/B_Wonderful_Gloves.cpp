#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl            '\n'
#define inf             1e18
#define ff              first
#define ss              second
#define pb              push_back
#define mod             1000000007 
#define newline         cout << '\n'
#define no              cout << "NO\n"
#define yes             cout << "YES\n"
#define all(A)          A.begin(), A.end()
#define rall(A)         A.rbegin(), A.rend()
#define mem(A,n)        memset(A, n, sizeof(A))
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> vp(n), vs(n);

    for(int i=0; i<n; i++) {
        cin >> vp[i].ff;
    }
    for(int i=0; i<n; i++) {
        cin >> vp[i].ss;
        vs[i] = {vp[i].ff+vp[i].ss,i};
    }
    sort(rall(vs));
    vector<ll> maxi, mini;
    for(int i=0; i<n; i++) {
        maxi.pb(max(vp[vs[i].ss].ff, vp[vs[i].ss].ss));
        mini.pb(min(vp[vs[i].ss].ff, vp[vs[i].ss].ss));
    }
    sort(rall(mini));
    ll ans = accumulate(all(maxi), 0LL);
    for(int i=0; i<k-1; i++) 
        ans += mini[i];

    cout << ans+1 << endl;
}

// 97  59  50 87  36
// 95  77  33 13  74
// 192 136 83 100 110

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}