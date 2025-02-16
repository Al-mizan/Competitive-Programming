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
    vector<ll> a(n), b(m);
    cin >> a >> b;
    
    sort(all(b));
    ll last = INT_MIN;
    for(int i = 0; i < n; i++) {
        auto ind = lower_bound(all(b), a[i]+last);
        
        if(ind == b.end() && a[i] < last) {
            no; return;
        }
        else if(ind == b.end()) {
            last = a[i];
        }
        else {
            if(last <= min(a[i], (*ind)-a[i])) {
                last = min(a[i], (*ind)-a[i]);
            } 
            else {
                last = max(a[i], (*ind)-a[i]);
            }
        }
        // debug(last);
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