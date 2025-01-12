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

ll mod_pow(ll b, ll n) {
    b %= mod;
    if (n < 0) n = mod - 2; // For modular inverse
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * b % mod;
        n >>= 1;
        b = b * b % mod;
    }
    return ans;
}
ll mod_mul(ll a, ll b) {
    return (a % mod * b % mod) % mod;
}
ll mod_inv(ll n) {
    return mod_pow(n, mod - 2);
}
ll mod_div(ll a, ll b) {
    return mod_mul(a, mod_inv(b));
}


void solve() {
    ll n;
    cin >> n;

    ll sum = mod_mul(n, n+1);
    sum = mod_mul(sum, 2*n+1 %  mod);
    sum = mod_div(sum, 6);
    
    ll k = n-1;
    ll sum2 = mod_mul(k, k+1);
    sum2 = mod_mul(sum2, 2*k+1 % mod);
    sum2 = mod_div(sum2, 6);
    sum = sum + sum2 % mod;
    sum = sum + mod_div(mod_mul(k, k+1),2) % mod;

    cout << mod_mul(sum,2022) << endl;
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
