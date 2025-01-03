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
    ll n, c, d, mini = INT_MAX;
    cin >> n >> c >> d;
    vector<ll> v(n*n);
    map<ll, ll> mp;
    for(ll i=0; i<n*n; i++){
        cin >> v[i];
        mini = min(mini, v[i]);
        mp[v[i]]++;
    }
    for(int i=0; i<n; i++) {
        ll m = 0;
        if(i == 0) m = mini;
        else {
            m = mini + c;
            mini = m;
        }
        mp[m]--;
        for(int j=1; j<n; j++) {
            m += d;
            mp[m]--;
        }
    }
    for(auto &[a,b]: mp) {
        if(b == 0) continue;
        no;
        return;
    }
    yes;
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
