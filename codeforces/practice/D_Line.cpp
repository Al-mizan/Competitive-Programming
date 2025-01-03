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
    string s;
    cin >> s;
    vector<pair<ll,ll>> vp;
    ll sum = 0;

    for(int i=0;i<n;i++) {
        if(i < n/2) {
            if(s[i] == 'L') vp.push_back({i, n-i-1});
            if(s[n-i-1] == 'R') vp.push_back({i, n-i-1});
            if(s[i] == 'L') sum += i;
            else sum += n-i-1;
        }
        else {
            if(s[i] == 'R') sum += n-i-1;
            else sum += i;
        }
    }

    ll m = n, i = 0;
    while(m--) {
        ll cnt = 0;
        if(i < vp.size()) {
            cnt = vp[i].ss - vp[i].ff;
            i++;
        }
        sum += cnt;

        cout << sum << ' ';
    }
    newline;
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
