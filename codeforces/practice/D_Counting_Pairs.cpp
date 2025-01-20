#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl            '\n'
#define ff              first
#define ss              second
#define pi              acos(-1)
#define mod             1000000007 
#define newline         cout << '\n'
#define no              cout << "NO\n"
#define yes             cout << "YES\n"
#define all(A)          A.begin(), A.end()
#define rall(x)         x.rbegin(), x.rend()
#define mem(a,n)        memset(a, n, sizeof(a))
#define setPre(n)       fixed << setprecision(n)
#define cases(tc)       cout << "Case #" << tc << ": "
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}
template <class T, class cmp = less_equal<T>> using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> v(n);
    cin >> v;
    
    ll sum = accumulate(all(v),0LL);
    sort(all(v));
    ll xx = sum - x;
    ll yy = sum - y;
    ll ans = 0;

    for(int i=0; i<n; i++) {
        ll ind_l = lower_bound(v.begin()+i+1, v.end(), yy-v[i]) - v.begin();
        ll ind_r = upper_bound(v.begin()+i+1, v.end(), xx-v[i]) - v.begin();
        ans += ind_r - ind_l;
    }

    cout << ans << endl;
}
//  22(9) 27(4)
// 3 4 4 5 6 9  - 31

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
