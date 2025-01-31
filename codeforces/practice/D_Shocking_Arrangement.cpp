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
    vector<ll> v(n), pos, neg;
    cin >> v;
    
    ll x = *max_element(all(v)) - *min_element(all(v));
    if(x <= *max_element(all(v))) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for(int i=0;i<n;i++) {
        if(v[i] < 0) neg.pb(v[i]);
        else pos.pb(v[i]);
    }
    sort(rall(pos));
    sort(all(neg));

    ll sum = 0, ind = 0;
    for(int i=0;i<pos.size();i++) {
        if(sum + pos[i] < x) cout << pos[i] << ' ';
        else {
            while(sum + pos[i] >= x) {
                cout << neg[ind] << ' ';
                sum += neg[ind++];
            }
            if(sum < 0) sum = 0;
            cout << pos[i] << ' ';
        }
        sum += pos[i];
    }
    for(int i=ind;i<neg.size();i++) {
        cout << neg[i] << ' ';
    }
    newline;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}