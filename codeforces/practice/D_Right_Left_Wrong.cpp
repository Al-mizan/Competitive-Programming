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
    vector<ll> v(n), pre(n+1), L, R;
    cin >> v;
    string s;
    cin >> s;
    for(int i=1; i<=n; i++) {
        if(!i) pre[i] = v[i-1];
        else pre[i] += pre[i-1] + v[i-1];
    }
    for(int i=0; i<n; i++) {
        if(s[i] == 'L') L.push_back(i+1);
        else R.push_back(i+1);
    }

    ll sum = 0, i = 0, j = R.size()-1;
    while(i < L.size() && j >= 0) {
        ll l = L[i++], r = R[j--];
        if(l >= r) break;
        sum += pre[r] - pre[l-1];
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
        solve();
    }
    return 0;
}
