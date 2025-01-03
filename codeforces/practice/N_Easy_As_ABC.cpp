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

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
int vis[3][3];
string ans = "DDD";
void dfs(int i, int j, string temp, vector<string>& v) {
    if(temp.size()==3) {
        ans = min(ans,temp);
        return;
    }
    vis[i][j] = 1;
    for(int k=0; k<8; k++) {
        int p = i+dx[k];
        int q = j+dy[k];
        if(p<0 || q<0 || p>2 || q>2) continue;
        if(!vis[p][q]) {
            dfs(p,q, temp+v[p][q], v);
        }
    }
    vis[i][j] = 0;
}

void solve() {
    vector<string> v(3);
    cin >> v;
    int cnt = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            dfs(i,j,"", v);
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        // cases(tc);
        solve();
    }
    return 0;
}
