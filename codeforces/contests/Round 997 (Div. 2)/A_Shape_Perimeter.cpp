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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> vp(n);
    for(int i=0; i<n; i++) {
        cin >> vp[i].ff >> vp[i].ss;
    }
    for(int i=1; i<n; i++) {
        vp[i].ff += vp[i-1].ff;
        vp[i].ss += vp[i-1].ss;
    }
    
    ll sum = 4*m, x = vp[0].ff+m, y = vp[0].ss+m;
    for(int i=1;i<n; i++) {
        sum += 4*m;
        ll s1 = x - vp[i].ff;
        ll s2 = y - vp[i].ss;
        sum -= 2*(s1+s2);
        x = vp[i].ff + m;
        y = vp[i].ss + m;
    }

    cout << sum << endl;
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
