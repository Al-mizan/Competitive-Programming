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
    vector<pair<ll,ll>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    sort(all(v));

    ll distance = LLONG_MAX, k = 0;
    set<pair<ll,ll>> st;
    st.insert({v[0].ss, v[0].ff});

    for (int i=1; i<n; i++) {
        ll dist = ceil(sqrt(distance));
        while(k < i && v[k].ff + dist < v[i].ff) {
            st.erase({v[k].ss,v[k].ff});
            k++;
        }
        auto lo = st.lower_bound({v[i].ss - dist, 0});
        auto hi = st.upper_bound({v[i].ss + dist, 0});
        
        for (auto it = lo; it != hi; it++) {
            distance = min(distance, (it->ss - v[i].ff)*(it->ss - v[i].ff) + (it->ff - v[i].ss)*(it->ff - v[i].ss));
        }
        st.insert({v[i].ss, v[i].ff});
    }

    cout << distance << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) solve();
    return 0;
}