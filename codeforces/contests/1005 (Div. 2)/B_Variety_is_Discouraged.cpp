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
    ll n;
    cin >> n;
    vector<ll> v(n);
    cin >> v;
    map<ll,ll> mp;
    for(auto i: v) mp[i]++;

    if(n==1) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }

    ll cnt = 0, ans = 0, l = -1, r = -1;
    for(int i=0;i<n;i++) {
        if(mp[v[i]]==1) {
            cnt++;
        }
        else {
            if(ans < cnt) {
                ans = cnt;
                l = i-cnt+1;
                r = i;
            }
            cnt=0;
        }
    }
    if(cnt > ans) {
        l = n-cnt+1;
        r = n;
    }
    if(l == -1 or r == -1) {
        cout << 0 << endl;
    }
    else {
        cout << l << ' ' << r << endl;
    }
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