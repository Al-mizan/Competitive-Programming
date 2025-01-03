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
    vector<ll> v1(n), v2(m), p(n), pre(n);
    cin >> v1 >> v2;

    ll maxi = INT_MIN;
    for(int i=0; i<n; i++) {
        if(!i) pre[i] = v1[i];
        else pre[i] += pre[i-1] + v1[i];
        maxi = max(maxi,v1[i]);
        p[i] = maxi;
    }

    for(int i=0; i<m; i++) {
        ll ind = upper_bound(all(p), v2[i]) - p.begin() - 1;
        
        if(ind == -1) cout << 0 << ' ';
        else cout << pre[ind] <<  ' ';
    }
    newline;
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
