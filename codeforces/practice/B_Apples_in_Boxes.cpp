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
    
    ll maxi = *max_element(all(v));
    ll mini = *min_element(all(v));
    ll sum = accumulate(all(v), 0LL);

    if(maxi - mini - 1 > k) {
        cout << "Jerry\n";
    }
    else if(maxi - mini - 1 == k && count(all(v), maxi)>1) {
        cout << "Jerry\n";
    }
    else {
        if(sum % 2 == 0) {
            cout << "Jerry\n";
        }
        else {
            cout << "Tom\n";
        }
    }
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}