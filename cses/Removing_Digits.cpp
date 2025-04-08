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
    
    vector<ll> dp(n+1, inf);
    dp[0] = 0;
    for(ll i = 1; i <= n; i++) {
        vector<ll> digits;
        ll temp = i;
        while (temp) {
            digits.pb(temp % 10);
            temp /= 10;
        }
        for (auto j : digits) {
            if (j == 0) continue;
            if (i >= j) {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }
    cout << dp[n] << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}