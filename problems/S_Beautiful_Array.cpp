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
#define cases(tc)       cout << "Case #" << tc << ": "
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    ll div = b/n;
    ll maxi = n*div*k + n*(k-1) + (b%n)*k;
    ll mini = n*div*k + (b%n)*k;

    if(s <= maxi && s >= mini) {
        ll ans = b*k + k-1;
        if(ans > s) ans = s;
        cout << ans << ' ';
        for(int i=0; i<n-1; i++) {
            if(ans + k-1 <= s) {
                cout << k-1 << ' ';
                ans += k-1;    
            }
            else {
                cout << s-ans << ' ';
                ans += s-ans;
            }
        }
        newline;
    }
    else cout << -1 << endl;
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        // cases(tc);
        solve();
    }
    return 0;
}
