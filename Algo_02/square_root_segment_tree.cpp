#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    
    ll m = sqrt((ld)n);
    ll pre[(n+m-1)/m]{};
    ll maxi = INT_MIN;
    int j = 0;
    for(int i = 0; i <n; i++) {
        maxi = max(maxi, v[i]);
        if(i && ((i+1)%m == 0)) {
            pre[j++] = maxi;
            maxi = INT_MIN;
        }
    }
    if(maxi != INT_MIN) pre[j] = maxi;
    
    ll q;
    cin >> q;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        ll ans = INT_MIN;

        for(int i = a; i <= min(b, (a/m + 1)*m -1); i++)
            ans = max(ans,v[i]);

        for(int i = a/m; i < b/m; i++)
            ans = max(ans,pre[i]);

        for(int i = (b/m)*m; i <= b; i++)
            ans = max(ans,v[i]);

        cout << ans << endl;
    }
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}
