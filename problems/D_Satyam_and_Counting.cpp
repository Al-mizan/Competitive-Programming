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
    map<ll,ll> mp, mp1, mp0;
    ll cnt1 = 0, cnt0 = 0;
    while(n--) {
        ll x, y;
        cin >> x >> y;
        mp[x]++;
        if(y) cnt1++, mp1[x]++;
        else cnt0++, mp0[x]++;
    }
    ll sum = 0;
    bool f = 0; ll cnt = 0;
    for(auto& it : mp) {
        if(it.ss > 1) {
            f = 1; cnt++;
            sum += cnt0 + cnt1 - 2;
        }
    }
    for(auto& [a,b] : mp1) {
        if(mp1.count(a+2) && mp0.count(a+1)) {
            sum++;
        }
    }
    for(auto& [a,b] : mp0) {
        if(mp0.count(a+2) && mp1.count(a+1)) {
            sum++;
        }
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
        // cases(tc);
        solve();
    }
    return 0;
}
