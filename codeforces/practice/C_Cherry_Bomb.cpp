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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n), p(n);
    cin >> v >> p;

    int sum = -1;
    for(int i=0; i<n; i++) {
        if(p[i] != -1) {
            sum = v[i] + p[i];
        }
    }
    if(sum != -1) {
        for(int i=0; i<n; i++) {
            if(p[i] == -1) p[i] = sum - v[i];
        }
        for(int i=0; i<n; i++) {
            if (!(0 <= p[i] && p[i] <= k)) {
                cout << 0 << endl;
                return;
            }
        }
        for(int i=0; i<n; i++) {
            if (v[i] + p[i] != sum) {
                cout << 0 << endl;
                return;
            }
        }
        cout << 1 << endl;
        return;
    }
    ll ans = k + 1 - (*max_element(all(v)) - *min_element(all(v)));
    
    cout << ans << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}