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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++) 
        cin >> v[i].ss;
    for(int i=0;i<n;i++) 
        cin >> v[i].ff;

    sort(all(v));
    ll sum = 0, cnt = 0, j = -1;
    bool f = 0;
    for(int i=0; i<n; i++) {
        if(v[i].ff < m) {
            j = i;
            if(cnt + v[i].ss >= n-1) {
                v[i].ss = n-1 - cnt; f = 1;
            }
            cnt += v[i].ss;
            sum += v[i].ff * v[i].ss;
            if(f) break;
        }
        else break;
    }
    if(f) sum += m;
    else sum += m * (n-cnt);

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
