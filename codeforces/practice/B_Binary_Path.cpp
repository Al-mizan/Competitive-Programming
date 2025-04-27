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
    vector<string> v(2);
    cin >> v;
    
    ll cnt = 1; bool f = 0;
    string ans = ""; ans += v[0][0];
    for(int i=0; i<n-1; i++) {
        if(f) {
            ans += v[1][i];
            continue;
        }
        if(v[0][i+1] == v[1][i]) {
            ans += v[1][i];
            cnt++;
        }
        else if(v[0][i+1] > v[1][i]) {
            ans += v[1][i];
            f = 1;
        }
        else if(v[0][i+1] < v[1][i]){
            ans += v[0][i+1];
            cnt = 1;
        }
    }
    ans += v[1][n-1];

    cout << ans << endl;
    cout << cnt << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}