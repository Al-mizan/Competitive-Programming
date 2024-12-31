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
    vector<ll> v(n), p, pre1(n+1, 0), pre2(n+1, 0);
    cin >> v;
    p = v;
    sort(all(p));
    for(int i=0; i<n; i++) {
        pre1[i+1] = pre1[i] + v[i];
        pre2[i+1] = pre2[i] + p[i];
    }
    int m;
    cin >> m;
    while(m--) {
        int c, l, r;
        cin >> c >> l >> r;
        if(c == 1) {
            cout << pre1[r]-pre1[l-1] << endl;
        }
        else {
            cout << pre2[r]-pre2[l-1] << endl;
        }
    }
}

int32_t main()
{
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
