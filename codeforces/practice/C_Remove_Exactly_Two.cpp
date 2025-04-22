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
    ll n;
    cin >> n;
    vector<ll> v[n+1], ad(n+2, 0);
    for (ll i = 1; i < n; i++) {
        ll x, y; cin >> x >> y;
        v[x].pb(y); v[y].pb(x);
        ad[x]++; ad[y]++;
    }

    // for(int i=1; i<=n; i++) {
    //     cout << endl << i << " : ";
    //     for(auto j : v[i]) {
    //         cout << j << " ";
    //     }
    // }


    if(n <= 5) {
        cout << n-2 << endl;
        return;
    }

    ll ans = 0, maxi = INT_MIN, ind = -1;
    for(int i=1; i<=n; i++) {
        if(maxi <= ad[i]) {
            maxi = ad[i];
            ind = i;
        }
    }
    ans += maxi;
    debug(ans);
    debug(ind);
    for(auto i : v[ind]) {
        ad[i]--;
    }
    
    maxi = INT_MIN;
    for(int i=1; i<=n; i++) {
        if(i!=ind && maxi < ad[i]) {
            maxi = ad[i];
        }
        // maxi = max(maxi, ad[i]);
    }
    debug(maxi-1);
    ans += maxi - 1;

    cout << ans << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}