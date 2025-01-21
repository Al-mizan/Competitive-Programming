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
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n), p(m);
    cin >> v >> p;
 
    priority_queue<ll> pq;
    map<ll, ll> mp;
    for(auto a : v) mp[a]++;
    for(auto a : p) pq.push(a);

    while(!pq.empty()) {
        ll x = pq.top(); pq.pop();
        if(mp.count(x)) {
            mp[x]--;
            n--;
            if(mp[x] == 0) mp.erase(x);
        }
        else {
            pq.push(x/2 + x%2);
            pq.push(x/2);
        }
        if(pq.size() > n) {
            cout << "NO\n";
            return;
        }
    }
    
    if(mp.size() == 0) cout << "YES\n";
    else cout << "NO\n";
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
