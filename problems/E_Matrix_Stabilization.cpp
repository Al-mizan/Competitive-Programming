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
#define setPre(n)       fixed << setprecision(n)
#define cases(tc)       cout << "Case #" << tc << ": "
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> v[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ll a = 0, b = 0, c = 0, d = 0;
            if(i-1 >= 0) a = v[i-1][j];
            if(i+1 < n) b = v[i+1][j];
            if(j-1 >= 0) c = v[i][j-1];
            if(j+1 < m) d = v[i][j+1];
            if(v[i][j] > max(max(a, b), max(c, d))) {
                v[i][j] = max(max(a, b), max(c, d));
                cout << v[i][j] << ' ';
            }
            else cout << v[i][j] << ' ';
        }
        newline;
    }
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
