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
    ll b, c, d;
    cin >> b >> c >> d;
    vector<bool> v[8];
    for(int i=0; i<8; i++) {
        for (int j=0; j<3; j++) {
            if (i & (1 << j)) v[i].pb(1);
            else v[i].pb(0);
        }
        bool x = (v[i][0] | v[i][1]) - (v[i][2] & v[i][0]);
        v[i].pb(x);
    }

    ull ans = 0;
    for(int i=0; i<62; i++) {
        bool bb = b & (1LL << i);
        bool cc = c & (1LL << i);
        bool dd = d & (1LL << i);
        bool f = 1;
        for(int j=0; j<8; j++) {
            if(bb == v[j][1] && cc == v[j][2] && dd == v[j][3]) {
                ans += (v[j][0]) ? (1LL << i): 0;
                f = 0;
                break;
            }
        }
        if(f) {
            cout << -1 << endl;
            return;
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