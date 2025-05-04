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
    ll n, b, c;
    cin >> n >> b >> c;

    ll res = 0;
    if(b == 0 && c == 0) {
        res = -1;
        if(n <= 2) res = n-1;
    }
    else if(b == 0) {
        if(c+1 < n-1) res = -1;
        else res = (c>=n)? n: n-1;
    }
    else if(n <= c) res = n;
    else {
        res = (n-1-c)/b + 1;
        res = n-res;
    }

    cout << res << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}