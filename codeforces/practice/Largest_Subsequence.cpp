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
    string s;
    cin >> s;
    ll ans = 0, ab = 0, ba = 0, a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    for(int i=0; i<n-1; i++) {
        if(s[i] == 'a' && s[i+1] == 'b') {
            ab++;
            a2 = i+1;
            if(a1 == 0) a1 = i+1;
        }
        else if(s[i] == 'b' && s[i+1] == 'a') {
            ba++;
            b2 = i+1;
            if(b1 == 0) b1 = i+1;
        }
    }
    ll l = 0;
    if(ab > ba) l = min(a1, n-a2);
    else if(ab < ba) l = min(b1, n-b2);
    ans = n - l;
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
        // cases(tc);
        solve();
    }
    return 0;
}
