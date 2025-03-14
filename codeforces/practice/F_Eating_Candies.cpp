#include <bits/stdc++.h>
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
    vector<ll> v(n), pre(n+1,0);
    cin >> v;
    
    map<ll,ll> mp;
    for(int i=1;i<=n;i++) {
        if(i>1) pre[i] += v[i-1] + pre[i-1];
        else pre[i] = v[i-1];
        mp[pre[i]] = i;
    }

    ll ans = 0;
    for(int i=n;i>=1;i--) {
        ll x = pre[n] - pre[i-1];
        ll ind = 0;

        if(mp.count(x)) {
            ind = mp[x];
            if(ind >= i) break;
            ans = max(ans, n-i+1+ind);
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
