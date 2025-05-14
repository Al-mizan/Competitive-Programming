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
    vector<pair<ll,ll>> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    v.push_back(v[0]);
    
    ll on_boundary = 0;
    for(int i=0; i<n; i++) {
        on_boundary += gcd(abs(v[i].ff - v[i+1].ff), abs(v[i].ss - v[i+1].ss));
    }

    ll area = 0;
    for(int i=0; i<n; i++) {
        area += (v[i].ff * v[i+1].ss) - (v[i+1].ff * v[i].ss);
    }
    area = abs(area) / 2;

    ll inside = area - on_boundary / 2 + 1;
    cout << inside << ' ' << on_boundary << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) solve();
    return 0;
}