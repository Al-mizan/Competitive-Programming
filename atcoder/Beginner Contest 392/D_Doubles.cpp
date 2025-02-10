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
    ll tt;
    cin >> tt;
    vector<map<ll,double>> ans(tt);
    for(int i=0; i<tt; i++) {
        ll n;
        cin >> n;
        map<ll,ll> mp;
        for(int j=0; j<n; j++) {
            ll x; cin >> x;
            mp[x]++;
        }
        for(auto [a,b]: mp) {
            ans[i][a] = (double)b/n;
        }
    }
    double maxi = 0;
    for(int i=0; i<tt; i++) {
        for(int k=i+1; k<tt; k++) {
            double pro = 0;
            for(auto [a,b]: ans[k]) {
                if(ans[i].count(a)) {
                    pro += ans[i][a]*ans[k][a];
                }
            }
            maxi = max(maxi, pro);
        }
    }

    cout << fixed << setprecision(15) << maxi << endl;
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