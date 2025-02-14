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

void tower_of_hanoi(ll n, int a, int b, int c) {
    if(n == 1) {
        cout << a << ' ' << c << endl;
        return;
    }
    tower_of_hanoi(n-1, a, c, b);
    cout << a << ' ' << c << endl;
    tower_of_hanoi(n-1, b, a, c);
}

void solve() {
    ll n;
    cin >> n;

    cout << (1 << n) - 1 << '\n';

    tower_of_hanoi(n, 1, 2, 3);
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}