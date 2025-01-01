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

vector<ll> p;
void solve() {
    string s;
    ll x;
    cin >> s >> x;

    ll t = (10*(s[0]-'0') + (s[1]-'0'))*60 + (s[3]-'0')*10 + (s[4]-'0');
    set<ll> v;

    for(int i=0; i<1440; i++) {;
        v.insert(t);
        t += x;
        t %= 1440;
    }
    ll ans = 0;
    for(auto &i : v) {
        for(int j=0; j<p.size(); j++) {
            if(i == p[j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for(int i=0; i<1440; i++) {
        ll x = i%60;
        if(i/60 == 10*(x%10) + x/10) p.push_back(i);
    }
    while (t--)
    {
        solve();
    }
    return 0;
}