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
    ll n;
    cin >> n;
    vector<int> v(n), ans(n);
    map<int,int> mp;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        mp[v[i]]++;
    }

    bool f = true, g = 1;
    int a = 1, b = 2;
    for(int i=0; i<n; i++) {
        if(mp[v[i]] == 1) {
            ans[i] = 1;
            continue;
        }
        if(mp[v[i]] == 0) continue;
        if(a == 1) {
            ans[i] = a;
            a++;
        }
        else ans[i] = b;
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            if(v[i] == v[j] && f) {
                ans[j] = a;
            }
            else if(v[i] == v[j]) {
                ans[j] = 3; g = 0;
            }
        }
        if(a == 2) f = 0;
        mp[v[i]] = 0;
    }
    if(!g) cout << ans << endl;
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
        solve();
    }
    return 0;
}
