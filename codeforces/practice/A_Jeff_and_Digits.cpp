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
#define setPre(n)       fixed << setprecision(n)
#define Fill(v,x)       fill(v.begin(),v.end(),x)
#define cases(tc)       cout << "Case #" << tc << ": "
#define debug(args...)  cout << #args << " = " << args << endl;
#define getunique(v){sort(v.begin(), v.end());v.erase(unique(v.begin(), v.end()), v.end());}
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    cin >> v;
    ll five = 0, zero = 0;
    for(int i=0; i<n; i++) {
        if(v[i] == 0) zero++;
        else five++;
    }
    if(zero == 0) cout << -1 << endl;
    else if(five < 9) cout << 0 << endl;
    else {
        ll x = five - (five%9);
        for(int i=0; i<x; i++) cout << 5;
        for(int i=0; i<zero; i++) cout << 0;
        newline;
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        // cases(tc);
        solve();
    }
    return 0;
}
