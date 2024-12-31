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
#define Fill(v,x)       fill(v.begin(),v.end(),x)
#define cases(tc)       cout << "Case #" << tc << ": "
#define debug(args...)  cout << #args << " = " << args << endl;
#define getunique(v){sort(v.begin(), v.end());v.erase(unique(v.begin(), v.end()), v.end());}
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vis(n+5, 0);
    while(m--) {
        int a,b;
        cin >> a >> b;
        vis[a]=1, vis[b]=1;
    }
    int i;
    for(i=1; i<=n; i++) {
        if(vis[i]==0)
            break;
    }
    cout << n-1 << endl;
    for(int j=1; j<=n; j++) {
        if(i == j) continue;
        cout << j << " " << i << endl;
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        // cases(tc);
        solve();
    }
    return 0;
}
