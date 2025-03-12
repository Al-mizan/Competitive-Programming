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

int tt = 0;
void dfs(vector<int> v[], int s, vector<int>& vis, vector<int>& st, vector<int>& end) {
    vis[s] = 1;
    st[s] = ++tt;
    for(auto i: v[s]) {
        if(!vis[i]) {
            dfs(v, i, vis, st, end);
        }
    }
    end[s] = ++tt;
}

void solve() {
    ll n;
    cin >> n;
    vector<int> v[n+1], vis(n+1, 0), st(n+1,0), end(n+1,0);
    for(int i=2; i<=n; i++) {
        ll x;
        cin >> x;
        v[x].pb(i);
    }
    dfs(v, 1, vis, st, end);

    for(int i=1; i<=n; i++) cout << (end[i]-st[i])/2 << ' ';
    cout << '\n';
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}