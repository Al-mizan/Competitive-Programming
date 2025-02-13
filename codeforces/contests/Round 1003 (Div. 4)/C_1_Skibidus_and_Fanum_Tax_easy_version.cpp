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
    ll n, m, b;
    cin >> n >> m;
    vector<ll> v(n);
    cin >> v;
    cin >> b;

    ll mini = INT_MIN, last = INT_MIN, maxi = INT_MAX;
    for(int i = 0; i < v.size(); i++) {
        mini = min(v[i], b-v[i]);
        maxi = max(v[i], b-v[i]);
        
        if(mini >= last) last = mini;
        else if(maxi >= last) last = maxi;
        else {
            no; return;
        }
    }
    yes;
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