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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

ll dfs(vector<vector<ll>>& v, vector<vector<ll>>& vis, int i, int  j, int n, int m) {
    vis[i][j] = 1;

    ll sum = v[i][j];
    for(int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && v[x][y]) {
            sum += dfs(v, vis, x, y, n, m);
        }
    }
    return sum;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m)), vis(n, vector<ll>(m,0));
    for(int i=0; i<n; i++) {
        for(int j =0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    ll ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j] && v[i][j]) {
                ans = max(ans, dfs(v, vis, i, j, n, m));
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
