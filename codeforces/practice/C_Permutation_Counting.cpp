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

bool ck(vector<ll>& v, ll mid, ll k) {
    for (auto x : v) {
        if (x < mid) {
            k -= (mid - x);
            if(k < 0) break;
        }
    }
    return k >= 0;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    cin >> v;
    
    ll l = 0, r = *min_element(all(v)) + k, ans = 0;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        if(ck(v, mid, k)) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
        }
    }
    
    ll cnt = 0;
    for (auto x : v) {
        if (x < ans) {
            k -= (ans - x);
        }
        if(x > ans) cnt++;
    }
    if(k > 0) cnt += k;

    cout << (n*ans) - n + 1 + cnt << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}