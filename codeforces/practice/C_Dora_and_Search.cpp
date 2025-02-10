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
    
    ll l = 1, r = n; bool f = 1;
    int i;
    for(i=0; i<n; ) {
        if(v[i] == l || v[n-1] == l || v[i] == r || v[n-1] == r) {
            if(v[i] == l) l++, i++;
            else if(v[n-1] == l) l++, n--;
            if(v[i] == r) r--, i++;
            else if(v[n-1] == r) r--, n--;
        }
        else {
            f = 0;
            break;
        }
    }

    if(f || n-i < 4) {
        cout << -1 << endl;
    }
    else {
        cout << i+1 << ' ' << n << endl;
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