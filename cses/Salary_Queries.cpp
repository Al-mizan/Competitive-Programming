#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using namespace __gnu_pbds;
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
template <class T, class cmp = less_equal<T>> using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// s.erase(s.upper_bound(value));
// st.order_of_key(x); // number of elements < x
void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    cin >> v;

    ordered_set<pair<ll, ll>> st;
    for(int i=0; i<n; i++) {
        st.insert({v[i], i});
    }

    while(q--) {
        char ch; ll x, y;
        cin >> ch >> x >> y;

        if(ch == '!') {
            st.erase(st.upper_bound({v[x-1], x-1}));
            st.insert({y, x-1});
            v[x-1] = y;
        }
        else {
            ll l = st.order_of_key({x, INT_MIN});
            ll r = st.order_of_key({y+1, INT_MIN});
            cout << r-l << endl;
        }
    }
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