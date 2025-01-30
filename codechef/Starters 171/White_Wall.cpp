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

ll func(string& s, string& comp) {
    ll cnt = 0, n = s.size();
    for(int i=0;i<n; i+=3) {
        for(int j=0;j<3;j++) {
            if(i+j < n && s[i+j] != comp[j]) cnt++;
        }
    }
    return cnt;
}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = INT_MAX;
    string comp = "RGB";
    ans = min(ans, func(s, comp));
    comp = "RBG";
    ans = min(ans, func(s, comp));
    comp = "BGR";
    ans = min(ans, func(s, comp));
    comp = "BRG";
    ans = min(ans, func(s, comp));
    comp = "GBR";
    ans = min(ans, func(s, comp));
    comp = "GRB";
    ans = min(ans, func(s, comp));

    cout << ans << endl;
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
