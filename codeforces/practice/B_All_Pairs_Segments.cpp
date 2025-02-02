#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl            '\n'
#define inf             1e18
#define ff              first
#define ss              second
#define pb              push_back
#define mod             1000000007 
#define newline         cout << '\n'
#define no              cout << "NO\n"
#define yes             cout << "YES\n"
#define all(A)          A.begin(), A.end()
#define rall(A)         A.rbegin(), A.rend()
#define mem(A,n)        memset(A, n, sizeof(A))
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n), p(m), pre(n), suff(n), s(n);
    cin >> v >> p;

    for(int i=0;i<n;i++) s[i] = n-i-1;
    auto ss = s;
    reverse(all(ss));
    
    for(int i=0;i<n;i++) {
        if(!i) {
            pre[i] = s[i];
            suff[i] = ss[i];
        }
        else {
            pre[i] += pre[i-1] + s[i];
            suff[i] += suff[i-1] + ss[i];
        }
    }

    map<ll, ll> mp;
    for(int i=0;i<n;i++) {
        if(!i) mp[pre[i]]++;
        else {
            if(v[i]-v[i-1] != 1) mp[pre[i-1]-suff[i-1]] += v[i]-v[i-1]-1;
            mp[pre[i]-suff[i-1]]++;
        }
    }

    for(int i=0;i<m;i++) {
        cout << mp[p[i]] << ' ';
    }
    newline;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}