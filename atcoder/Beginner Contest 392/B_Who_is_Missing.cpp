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
    ll m, n;
    cin >> m >> n;
    vector<ll> v(n), ans;
    cin >> v;
    sort(all(v));

    ll cnt = 1;
    for(int i=0; i<n; ) {
        if(v[i] == cnt) cnt++, i++;
        else if(v[i] > cnt) {
            ans.pb(cnt++);
        }
    }

    if(cnt <= m) {
        for(int i=cnt; i<=m; i++) {
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}