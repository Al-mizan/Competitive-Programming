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

pair<ll,ll> mini(vector<pair<ll,ll>>& v) {
    pair<ll,ll> mini = {inf, inf};
    for(auto it : v) {
        mini = min(mini, {it.ss, it.ff});
    }
    return {mini.ss, mini.ff};
}

int orientation(pair<ll,ll>& p, pair<ll,ll>& q, pair<ll,ll>& r) {
    ll val = (q.ss - p.ss) * (r.ff - q.ff) - (q.ff - p.ff) * (r.ss - q.ss);
    if(val == 0) return 0;
    return (val > 0) ? 1 : -1;
}

bool are_collinear(pair<ll,ll>& a, pair<ll,ll>& b, pair<ll,ll>& c) {
    return orientation(a, b, c) == 0;
}

bool polar_compare(pair<ll,ll>& pivot, pair<ll,ll>& a, pair<ll,ll>& b) {
    int o = orientation(pivot, a, b);
    if (o == 0) {
        auto dist_a = (a.ff - pivot.ff) * (a.ff - pivot.ff) + (a.ss - pivot.ss) * (a.ss - pivot.ss);
        auto dist_b = (b.ff - pivot.ff) * (b.ff - pivot.ff) + (b.ss - pivot.ss) * (b.ss - pivot.ss);
        return dist_a < dist_b;
    }
    return o < 0;
}

bool is_clockwise(pair<ll,ll>& a, pair<ll,ll>& b, pair<ll,ll>& c) {
    int o = orientation(a, b, c);
    return o <= 0;
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    auto pivot = mini(v);
    sort(v.begin(), v.end(), [&pivot](auto a, auto b) {
        return polar_compare(pivot, a, b);
    });

    int i = v.size() - 1;
    while (i >= 0 && are_collinear(pivot, v[i], v.back())) {
        i--;
    }
    reverse(v.begin() + i + 1, v.end());
    
    vector<pair<ll,ll>> hull;
    for (auto& p : v) {
        while (hull.size() > 1 && !is_clockwise(hull[hull.size()-2], hull.back(), p)) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    cout << hull.size() << endl;
    for (auto p : hull) {
        cout << p.ff << ' ' << p.ss << endl;
    }
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) solve();
    return 0;
}