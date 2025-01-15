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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    cin >> v;

    map<ll,ll> mp, mp2;
    for(int i=0; i<n; i++) mp[v[i]]++;
    mp2 = mp;

    // ll fre = n-mp[k], lol = mp[k];
    ll maxi = 0;
    for(auto& [a,b]: mp) {
        if(a != k) maxi = max(maxi, b);
    }
    if(mp[k] >= maxi) {
        cout << 0 << endl;
        return;
    }
    for(int i=0; i<n; i++) {
        mp[v[i]]--;
        ll maxi = 0;
        for(auto& [a,b]: mp) {
            if(a != k) maxi = max(maxi, b);
        }
        if(mp[k] >= maxi && mp[k]>0) {
            cout << 1 << endl;
            return;
        }
        if(mp[k] < 1) break;
    }
    // fre = n-lol;
    for(int i=n-1; i>=0; i--) {
        mp2[v[i]]--;
        ll maxi = 0;
        for(auto& [a,b]: mp2) {
            if(a != k) maxi = max(maxi, b);
        }
        if(mp2[k] >= maxi && mp2[k]>0) {
            cout << 1 << endl;
            return;
        }
        if(mp2[k] < 1) break;
    }
    cout << 2 << endl;
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
