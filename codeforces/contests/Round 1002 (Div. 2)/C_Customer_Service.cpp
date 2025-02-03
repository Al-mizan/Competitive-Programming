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
    vector<vector<ll>> v(n,vector<ll>(n));
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    
    vector<ll> ans;
    for(int i=0;i<n;i++) {
        ll cnt = 0;
        for(int j=n-1; j>=0, v[i][j]==1; j--) {
            cnt++;
        }
        if(cnt == n) cnt--;
        if(cnt) ans.pb(cnt);
    }

    sort(all(ans));
    ll sol = 1;
    for(int i=0; i<ans.size(); i++) {
        if(ans[i] >= sol) sol++;
    }

    cout << sol << endl;
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