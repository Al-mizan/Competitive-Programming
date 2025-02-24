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
    vector<pair<pair<ll,ll>,ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff.ff >> v[i].ff.ss;
        v[i].ss = i;
    }
    sort(all(v));
    vector<pair<ll,ll>> ans;
    multiset<pair<ll,ll>> st;

    for(int i = 0; i < n; i++) {
        auto it = st.lower_bound({v[i].ff.ff, INT_MIN});
        if(st.size() == 0) {
            st.insert({v[i].ff.ss, 1});
            ans.pb({v[i].ss, 1}); continue;
        }
        if(it == st.begin()) {
            st.insert({v[i].ff.ss, st.size() + 1});
            ans.pb({v[i].ss, st.size()}); continue;
        }
        it--;
        st.insert({v[i].ff.ss, it->ss});
        ans.pb({v[i].ss, it->ss});
        st.erase(it);
    }
    
    sort(all(ans));
    cout << st.size() << endl;
    for(int i = 0; i < n; i++) {
        cout << ans[i].ss << ' ';
    }
    newline;
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