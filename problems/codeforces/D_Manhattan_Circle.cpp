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
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    ll ans = INT_MIN, ind = -1, st = -1, end = -1;
    ll l = -1, r = -1;
    for(int i = 0; i < n; i++) {
        ll cnt = 0;
        bool f = 1;
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '#') {
                cnt++;
                if(f) {
                    st = j;
                    f = 0;
                }
                end = j;
            }
        }
        if(cnt > ans) {
            ans = cnt;
            ind = i;
            l = st;
            r = end;
        }
    }
    cout << ind+1 << ' ' << l + (r-l)/2 + 1 << endl;
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
