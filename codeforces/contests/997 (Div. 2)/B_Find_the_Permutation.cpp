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
    ll n;
    cin >> n;
    vector<string> vs(n);
    cin >> vs;
    vector<vector<int>> adj(n + 1);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vs[i][j] == '1') {
                adj[i + 1].push_back(j + 1);
            }
        }
    }
    vector<int> ans(n + 1, 0);

    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(auto node: adj[i + 1]) {
            if(node > i + 1) {
                cnt++;
            }
        }
        int idx = n+1;
        while(--idx) {
            if(cnt <= 0 && ans[idx]==0) {
                ans[idx] = i+1;
                break;
            }
            if(ans[idx]==0) cnt--;
        }
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
