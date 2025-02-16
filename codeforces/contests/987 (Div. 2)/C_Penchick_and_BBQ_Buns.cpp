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
    
    if(n < 26 && n%2) {
        cout << -1 << '\n';
        return;
    } 

    if(n%2 == 0) {
        for(int i=1; i<=n; i++) {
            cout << (i+1)/2 << ' ';
        }
        newline;
    }
    else {
        cout << 1 << ' ';
        for(int i=2; i<=9; i++)
            cout << (i+2)/2 << ' ';
        cout << 1 << ' ';
        for(int i=11; i<23; i++)
            cout << (i+1)/2 << ' ';
        cout << 13 << ' ' << 12 << ' ' << 12 << ' ';
        cout << 1 << ' ' << 13 << ' ';
        for(int i=28; i<=n; i++)
            cout << i/2 << ' ';
        newline;
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