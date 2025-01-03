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
    ll n;
    cin >> n;
    ll v[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> v[i][j];
        }
    }
    ll sum = 0;
    for(int k=0; k<n; k++) {
        int x = k, y = 0;
        ll mini = 0;
        for(int i=0; i<n; i++) {
            if(y+i > n-1 || x+i> n-1) break;
            if(v[x+i][y+i] < 0) {
                mini = min(mini, v[x+i][y+i]);
            }
        } 
        sum -= mini;
    }
    for(int k=0; k<n-1; k++) {
        int x = 0, y = k+1;
        ll mini = 0;
        for(int i=0; i<n; i++) {
            if(y+i > n-1 || x+i > n-1) break;
            if(v[x+i][y+i] < 0) {
                mini = min(mini, v[x+i][y+i]);
            }
        }
        sum -= mini;
    }
    cout << sum << endl;
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
