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

bool onSegment(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x3 <= max(x1, x2) && x3 >= min(x1, x2)) &&
           (y3 <= max(y1, y2) && y3 >= min(y1, y2));
}

int cross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll val = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);
    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}

void solve() {
    vector<ll> v(8);
    cin >> v;
    
    ll cross_product1 = cross(v[0], v[1], v[2], v[3], v[4], v[5]);
    ll cross_product2 = cross(v[0], v[1], v[2], v[3], v[6], v[7]);
    
    ll cross_product3 = cross(v[4], v[5], v[6], v[7], v[0], v[1]);
    ll cross_product4 = cross(v[4], v[5], v[6], v[7], v[2], v[3]);

    if(cross_product1 != cross_product2 && cross_product3 != cross_product4) {
        yes;
    }
    else if (cross_product1 == 0 && onSegment(v[0], v[1], v[2], v[3], v[4], v[5])) {
        yes;
    }
    else if (cross_product2 == 0 && onSegment(v[0], v[1], v[2], v[3], v[6], v[7])) {
        yes;
    }
    else if (cross_product3 == 0 && onSegment(v[4], v[5], v[6], v[7], v[0], v[1])) {
        yes;
    }
    else if (cross_product4 == 0 && onSegment(v[4], v[5], v[6], v[7], v[2], v[3])) {
        yes;
    }
    else no;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}