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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    cin >> v;

    while(k--) {
        ll diff = 0, diff_ind = -1;
        for(int i=0;i<n-1; i++) {
            if(abs(v[i+1]-v[i]) > diff) {
                diff = abs(v[i+1] - v[i]);
                diff_ind = v[i+1]<v[i]?i:i+1;
            }
        }
        if(diff_ind != -1) {
            ll next = diff_ind!=n-1?abs(v[diff_ind]-v[diff_ind+1]):-1;
            ll prev = diff_ind!=0?abs(v[diff_ind]-v[diff_ind-1]):-1;
            if(next!=-1 && prev!=-1) {
                if(next>prev) v[diff_ind] = v[diff_ind+1];
                else v[diff_ind] = v[diff_ind-1];
            } 
            else if(next!=-1) v[diff_ind] = v[diff_ind+1];
            else if(prev!=-1) v[diff_ind] = v[diff_ind-1];
        }
    }
    
    cout << accumulate(all(v), 0LL) << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}