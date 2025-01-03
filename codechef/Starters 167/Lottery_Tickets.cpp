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
    vector<ll> v(n);
    cin >> v;
    ll x = v[0];
    ll l = 0, r = 0;
    sort(all(v));
    bool f = 0, g =0;

    for(int i=0; i<n; i++) {
        if(v[i] == x) {
            if(i > 0) l = v[i-1];
            else l = 1, f = 1;
            if(i < n-1) r = v[i+1];
            else r = 1e6, g = 1;
            break;
        }
    }
    ll l1 = ((x-l+1)+1)/2;
    if(f) l1 = x;
    ll r1 = (r-x)/2;
    if(g) r1 = 1e6 - x;
    ll sum = l1 + r1;
    
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
