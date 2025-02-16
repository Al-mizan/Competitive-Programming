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
    vector<ll> v(n), pos(n), neg(n+1);
    cin >> v;
     
    for(int i=0; i<n; i++) {
        if(!i) pos[i] = 0;
        else pos[i] = pos[i-1];
        if(v[i] > 0) pos[i] += v[i];
    }
    for(int i=n-1; i>=0; i--) {
        if(i == n-1) neg[i] = 0;
        else neg[i] = neg[i+1];
        if(v[i] < 0) neg[i] -= v[i];
    }

    ll ans = 0;
    for(int i=0; i<n; i++) {
        ll sum = pos[i] + neg[i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}