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
    map<ll,ll> mp;
    ll x;
    for(int i=0;i<n;i++) {
        cin >> x;
        mp[x]++;
    }
    if(mp.find(5)!=mp.end() || mp.find(7)!=mp.end()) {
        cout << -1 << endl; return;
    }
    ll sum = mp[6]+mp[4], sum2 = 0;
    bool f = 0;
    if(mp[6]) {
        if(mp[3] > mp[6]) f = 1;
        else mp[6]-=mp[3];
        if(!f && mp[6]>mp[2]) f = 1;
        else mp[2]-=mp[6];
        sum2 = mp[6];
    }
    if(mp[4]) {
        if(!f && mp[4] != mp[2]) f = 1, sum += mp[2];
    }
    if(mp[1] != sum) f = 1;
    if(f) {
        cout << -1 << endl; return;
    }
    for(int i=0; i<n/3; i++) {
        if(mp[4]) {
            cout << 1 << ' ' << 2 << ' ' << 4 << endl;
            mp[4]--;
        }
        else if(sum2) {
            cout << 1 << ' ' << 2 << ' ' << 6 << endl;
            sum2--;
        }
        else 
            cout << 1 << ' ' << 3 << ' ' << 6 << endl;
    }
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        // cases(tc);
        solve();
    }
    return 0;
}