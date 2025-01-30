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
    ll n, p;
    cin >> n >> p;
    vector<ll> v(n), pre(n), suf(n);
    cin >> v;
    
    ll maxi = inf;
    for(int i=0; i<n; i++) {
        maxi = max(maxi, v[i]);
        if(v[i]) pre[i] = maxi; 
        else {
            pre[i] = 0;
            maxi = 0;
        }
    }
    maxi = inf;
    for(int i=n-1; i>=0; i--) {
        maxi = max(maxi, v[i]);
        if(v[i]) suf[i] = maxi; 
        else {
            suf[i] = 0;
            maxi = 0;
        }
    }

    for (int i=0; i<n; i++) {
        cout << (min(pre[i], suf[i])+p-1)/p << ' ';
    }
    newline;
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