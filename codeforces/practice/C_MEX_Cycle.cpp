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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> v(n+1, n);
    
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i==1?v[n]:v[i-1]);
        st.insert(i==n?v[1]:v[i+1]);
        if(x==i) st.insert(v[y]);
        else if(y==i) st.insert(v[x]);

        int k = 0;
        for(auto it: st) {
            if(it == k) k++;
            else break;
        }
        v[i] = k;
        st.clear();
    }

    for(int i=1; i<=n; i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}