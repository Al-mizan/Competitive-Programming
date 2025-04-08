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

vector<ll> dp(1e6+1,0);

void func(ll n) {
    dp[0] = 1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= 6; j++) {
            if(i-j >= 0) {
                dp[i] = (dp[i] + dp[i-j]) % mod;
            }
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    cout << dp[n] << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    func(1e6);
    while (t--) solve();
    return 0;
}