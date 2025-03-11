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
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void DFS(vector<vector<char>> &v, vector<vector<int>> &vis, int i, int j){
    vis[i][j] = 1;
    for (int k=0; k<4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < v.size() && y >= 0 && y < v[0].size() && v[x][y] == '.' && !vis[x][y]) {
            DFS(v, vis, x, y);
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0; i<n; i++) cin >> v[i];
    vector<vector<int>> vis(n,vector<int>(m,0));

    ll sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v[i][j] == '#') continue;
            if(!vis[i][j]) {
                sum++;
                DFS(v,vis,i,j);
            }
        }
    }

    cout << sum << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}