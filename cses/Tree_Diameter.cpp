#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl            '\n'
#define inf             1e18
#define ff              first
#define ss              second
#define pb              push_back
#define mod             1000000007 
#define newline         cout << '\n'
#define no              cout << "NO\n"
#define yes             cout << "YES\n"
#define all(A)          A.begin(), A.end()
#define rall(A)         A.rbegin(), A.rend()
#define mem(A,n)        memset(A, n, sizeof(A))
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void dfs(ll node, vector<ll> v[], vector<ll> &dist, vector<bool> &vis) {
    vis[node] = true;
    for(auto it : v[node]) {
        if(!vis[it]) {
            dist[it] = dist[node] + 1;
            dfs(it, v, dist, vis);
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v[n+1];
    ll a, b;
    for(ll i = 0; i < n-1; i++) {
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    vector<ll> dist(n+1, 0);
    vector<bool> vis(n+1, false);
    
    dfs(1, v, dist, vis);
    
    ll cnt = 0, node = 0;
    for(ll i = 1; i <= n; i++) {
        if(cnt < dist[i]) {
            cnt = dist[i];
            node = i;
        }
    }
    dist = vector<ll>(n+1,0);
    vis = vector<bool> (n+1, false);
    dfs(node, v, dist, vis);
    
    cnt = 0;
    for(ll i = 1; i <= n; i++) {
        cnt = max(cnt, dist[i]);
    }
    cout << cnt << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}