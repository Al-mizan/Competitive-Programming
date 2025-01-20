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
    vector<pair<ll,ll>> a(n), b(n), c(n);
    for(int i=0;i<n;i++) {
        cin >> a[i].ff;
        a[i].ss = i;
    }
    for(int i=0;i<n;i++) {
        cin >> b[i].ff;
        b[i].ss = i;
    }
    for(int i=0;i<n;i++) {
        cin >> c[i].ff;
        c[i].ss = i;
    }
    sort(rall(a));
    sort(rall(b));
    sort(rall(c));
    ll ans = 0;
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                if(a[i].ss != b[j].ss && a[i].ss != c[k].ss && b[j].ss != c[k].ss) {
                    ans = max(ans, a[i].ff + b[j].ff + c[k].ff);
                }
            }
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
