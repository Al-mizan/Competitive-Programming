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
    vector<string> v(n);
    cin >> v;
    
    bool pos = true;
    for (ll i = 0; i < n && pos; i++) {
        for (ll j = 0; j < m && pos; j++) {
            if (v[i][j] == '1') {
                bool left = true;
                for (int k = 0; k < j; k++) {
                    if (v[i][k] != '1') {
                        left = false;
                        break;
                    }
                }
                bool top = true;
                for (int k = 0; k < i; k++) {
                    if (v[k][j] != '1') {
                        top = false;
                        break;
                    }
                }
                if (!left && !top) {
                    pos = false;
                }
            }
        }
    }

    pos ? yes : no;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}