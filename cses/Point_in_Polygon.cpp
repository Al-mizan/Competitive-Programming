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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    v.push_back(v[0]);
    
    while(m--) {
        ll x, y;
        cin >> x >> y;
        bool f = 0;
        ll cnt = 0;

        for(int i=0; i < n; i++) {
            ll maxi = max(v[i].ss, v[i+1].ss);
            ll mini = min(v[i].ss, v[i+1].ss);
            if((x - v[i].ff) * (v[i+1].ss - v[i].ss) == (v[i+1].ff - v[i].ff) * (y - v[i].ss)) {
                if(min(v[i].ff, v[i+1].ff) <= x && max(v[i].ff, v[i+1].ff) >= x && min(v[i].ss, v[i+1].ss) <= y && max(v[i].ss, v[i+1].ss) >= y) {
                    cout << "BOUNDARY\n"; f = 1 ;
                    break;
                }
            }
            if(max(v[i].ff, v[i+1].ff) >= x && mini < y && maxi >= y) {
                double d = (double)(y-v[i].ss) * (v[i+1].ff-v[i].ff) / (v[i+1].ss - v[i].ss) + v[i].ff;
                if(v[i].ff == v[i+1].ff || x <= d) {
                    cnt++;
                }
            }
        }
        if(f) continue;
        if(cnt % 2) cout << "INSIDE\n";
        else cout << "OUTSIDE\n";
    }
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) solve();
    return 0;
}