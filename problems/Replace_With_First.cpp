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
    string a, b;
    cin >> a >> b;
    if(a[0] != b[0]) {
        cout  << -1 << endl; return;
    }
    if(a == b) {
        cout << 0 << endl; return;
    }
    if(n < m) {
        swap(n,m);
        swap(a,b);
    }
    ll sum = 0, cnt = m;
    for(int i=0; i<m; i++) {
        if(a[i] == b[i]) cnt--;
        else break;
    }
    for(int i=0; i<m; i++) {
        if(a[n-i-1] == b[m-i-1]) cnt--;
        else break;
    }
    if(cnt <= 0) cout << 1 << endl;
    else cout << 2 << endl;
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
