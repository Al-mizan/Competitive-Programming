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

ll fact(ll n) {
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res *= i;
    return res;
}

void solve() {
    string s;
    cin >> s;
    
    ll n = s.size();
    map<char, ll> mp;
    for(int i=0;i<n;i++) {
        mp[s[i]]++;
    }
    ll ans = fact(n);
    for(auto [a,b]: mp) {
        ans /= fact(b);
    }

    cout << ans << endl;
    
    set<string> st;
    sort(all(s));
    
    do {
        st.insert(s);
    }
    while(next_permutation(all(s)));

    for(auto ss: st) 
        cout << ss << endl;
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