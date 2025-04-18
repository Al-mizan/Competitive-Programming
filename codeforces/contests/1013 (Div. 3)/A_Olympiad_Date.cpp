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
    
    int a0 = 3, b1 = 1, c2 = 2, d3 = 1, e5 = 1;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        cnt++;
        if(v[i] == 0) a0--;
        else if(v[i] == 1) b1--;
        else if(v[i] == 2) c2--;
        else if(v[i] == 3) d3--;
        else if(v[i] == 5) e5--;
        if(a0 <= 0 && b1 <= 0 && c2 <= 0 && d3 <= 0 && e5 <= 0) {
            break;
        }
        else if(i==n-1) cnt = 0;
    }
    cout << cnt << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}