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
    int n;
    cin >> n;
    vector<string> v(n);
    for(auto &it: v) cin >> v;
    if(v[0][0] == '*' || v[n-1][n-1] == '*') {
        cout << 0 << endl;
        return;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(v[i][j] == '*') dp[i][j] = 0;
            else {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else dp[i][j] += ((i>0?dp[i-1][j]:0) + (j>0?dp[i][j-1]:0)) % mod;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}