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
    ll n, k, d;
    cin >> n >> k >> d;
    vector<ll> v(n), cmp(n,0);
    cin >> v;
    
    ll ans = 0;
    sort(all(v));
    for(int i=0; i<d; i++) {
        ll cnt = 0;
        for(int j=0; j<n; j++) {
            if(cmp[j] <= 0) cnt++;
        }
        if(cnt > k) {
            cnt -= k;
            for(int j=0; j<n; j++) {
                if(cnt==0) break;
                if(cmp[j] <= 0) {
                    cmp[j] = v[j];
                    ans++;
                    cnt--;
                }
            }
        }
        for(int j=0; j<n; j++) {
            cmp[j]--;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}