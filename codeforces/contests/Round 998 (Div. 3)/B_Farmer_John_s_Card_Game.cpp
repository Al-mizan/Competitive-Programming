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
    vector<vector<ll>> v(n, vector<ll>(m));
    vector<pair<ll,ll> > ans(n);
    for(int i = 0; i <n; i++){
        for(int j = 0; j <m; j++){
            cin >> v[i][j];
        }
        sort(all(v[i]));
        ans[i] = {v[i][0], i+1};
    }
    sort(all(v));
    if(m==1) {
        sort(all(ans));
        for(int i = 0; i <n; i++){
            cout << ans[i].ss << ' ';
        }
        newline;
        return;
    }
    for(int i=0; i<n; i++){
        for(int j = 0; j <m-1; j++){
            if(v[i][j+1]-v[i][j] != n) {
                cout << -1 << endl;
                return;
            } 
        }
    }
    sort(all(ans));
    for(int i = 0; i <n; i++){
        cout << ans[i].ss << ' ';
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
