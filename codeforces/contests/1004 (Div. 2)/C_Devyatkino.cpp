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

bool fun(ll n) {
    while(n) {
        if(n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

void solve() {
    ll n;
    cin >> n;
    
    if(fun(n)) {
        cout << 0 << endl;
        return;
    }
    ll ans = INT_MAX;
    ll len = log10(n), sum = 9;

    for(int i=0; i<len+1; i++) {
        ll cnt = 1;
        while(!fun(n + cnt*sum)) cnt++;
        ans = min(ans, cnt);
        sum *= 10;
        sum += 9;
    }

    cout << ans << endl;
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