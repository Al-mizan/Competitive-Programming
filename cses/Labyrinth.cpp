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
char dir[] = {'D', 'R', 'U', 'L'};

void solve() {
    ll n, m, a1=0, b1=0, a2=0, b2=0;
    cin >> n >> m;
    vector<vector<char>> v(n,vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> v[i][j];
            if(v[i][j] == 'A') a1 = i, b1 = j;
            if(v[i][j] == 'B') a2 = i, b2 = j;
        }
    }

    queue<pair<ll,ll>> q;
    q.push({a1,b1});
    vis[a1][b1] = 1;
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int x = curr.ff + dx[k];
            int y = curr.ss + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && (v[x][y] == '.' || v[x][y] == 'B') && !vis[x][y]) {
                vis[x][y] = 1;
                q.push({x,y});
                par[x][y] = {curr.ff, curr.ss};
            }
        }
    }
    if(!vis[a2][b2]) {
        no;
        return;
    }
    yes;
    string ans = "";
    int cx = a2, cy = b2;
    while (cx != a1 || cy != b1) {
        auto [px, py] = par[cx][cy];
        for (int d = 0; d < 4; d++) {
            if (px + dx[d] == cx && py + dy[d] == cy) {
                ans += dir[d];
                break;
            }
        }
        cx = px;
        cy = py;
    }
    reverse(all(ans));
    cout << ans.size() << endl;
    cout << ans << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) solve();
    return 0;
}