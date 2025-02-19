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
    vector<ll> v(n);
    cin >> v;
    
    ll ans = 0;
    for(int i=0; i<n; i++) {
        auto p = v;
        for(int j=0; j<i; j++) {
            if(p[j]<p[j+1] && j+1 == i) {
                p[j+1] = p[j+1]-p[j];
                continue;
            }
            // else if(p[j]>=p[j+1] && j+1 == i) {
            //     sum += 0;
            // }
            p[j+1] = 0;
        }
        for(int j=n-1; j>=i+1; j--) {
            if(p[j]<p[j-1] && j-1 == i) {
                p[j-1] = p[j-1]-p[j];
                continue;
            }
            p[j-1] = 0;
        }
        ans = max(ans, p[i]);
    }

    cout << ans << endl;
}

// 1 100 10 5 2 2
// 1 100 10 5 99 2

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