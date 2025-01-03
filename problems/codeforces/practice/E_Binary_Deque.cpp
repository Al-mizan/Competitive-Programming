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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n), pre(n);
    cin >> v;

    ll sum = accumulate(all(v), 0LL);
    if(sum < k) {
        cout << -1 << endl;
        return;
    }
    else if(sum == k) {
        cout << 0 << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!i) pre[i] = v[i];
        else pre[i] += pre[i-1] + v[i];
    }

    bool f = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll len = upper_bound(pre.begin()+i,pre.end(), k) - (pre.begin()+i);
        ans = max(ans,len);
        ll m = v[i] + k;
        k = m;
    }
    cout << n-ans << endl;
    // 0 1 1 2 3 4 4 4 5
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
