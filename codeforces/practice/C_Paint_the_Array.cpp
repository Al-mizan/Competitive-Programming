#include <bits/stdc++.h>
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


void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n), va, vb;
    cin >> v;
    
    ll a = 0, b = 0;
    for(int i=0; i<n; i++) {
        if(i%2) b = gcd(b,v[i]);
        else a = gcd(a,v[i]);
    }

    bool f = true;
    for(int i=1; i<n; i+=2) {
        if(v[i]%a == 0) {
            f = false;
            break;
        }
    }
    if(f) {
        cout << a << endl;
        return;
    }
    f = true;
    for(int i=0; i<n; i+=2) {
        if(v[i]%b == 0) {
            f = false;
            break;
        }
    }
    if(f) {
        cout << b << endl;
        return;
    }
    cout << 0 << endl;
}

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
