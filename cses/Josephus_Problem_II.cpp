#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
template <class T, class cmp = less_equal<T>> using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    ll n, k;
    cin >> n >> k;
    ordered_set <ll> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);

    ll ind = 0;
    while(!st.empty()) {
        ind = (ind + k) % st.size();
        auto it = st.find_by_order(ind);
        cout << *it << ' ';
        st.erase(it);
    }
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}