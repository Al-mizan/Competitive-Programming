#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl            '\n'
#define ff              first
#define ss              second
#define pi              acos(-1)
#define mod             1000000007 
#define newline         cout << '\n'
#define no              cout << "NO\n"
#define yes             cout << "YES\n"
#define all(A)          A.begin(), A.end()
#define rall(x)         x.rbegin(), x.rend()
#define mem(a,n)        memset(a, n, sizeof(a))
#define setPre(n)       fixed << setprecision(n)
#define cases(tc)       cout << "Case #" << tc << ": "
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}


void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    cin >> v;
    map<ll,ll> mp;
    sort(all(v));

    for(auto &it : v) mp[it]++;

    ll sum = 0; bool f = 0;
    for(auto& it: mp) {
        if(it.ss >= 4) {
            cout << it.ff << ' ' << it.ff << ' ' << it.ff << ' ' << it.ff << endl;
            return;
        }
        if(it.second >= 2) {
            if(f) {
                cout << sum << ' ' << sum << ' ' << it.ff << ' ' << it.ff << endl;
                return;
            }
            sum = it.ff;
            ll cnt = 2;
            for(int i=0; i<n; i++) {
                if(it.ff == v[i] && cnt) {
                    cnt--;
                    v[i] = -1;
                }
            }
            sort(all(v));
            for(int i=2; i<n; i++) {
                // ll a = upper_bound(all(v), v[i]) - v.begin() - 1;
                ll b = upper_bound(all(v), v[i]+2*it.ff-1) - v.begin() - 1;
                if(b>i) {  // v[b] - v[i] < it.ff
                    cout << it.ff << ' ' << it.ff << ' ' << v[i] << ' ' << v[b] << endl;
                    return;
                }
            }
            f = 1;
        }
    }
    
    cout << -1 << endl;
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        // cases(tc);
        solve();
    }
    return 0;
}
