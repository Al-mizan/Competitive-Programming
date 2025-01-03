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
    vector<ll> v(n);
    cin >> v;
    ll m;
    cin >> m;
    map<ll, char> mp2;
    map<char, ll> mp1;
    while(m--) {
        string s;
        cin >> s;
        if(s.size() != n) {
            no; 
            continue;
        }
        bool f = 1;
        mp1.clear();
        mp2.clear();
        for(int i=0; i<n; i++) {
            if(mp1.find(s[i]) == mp1.end() && mp2.find(v[i]) == mp2.end()) {
                mp1[s[i]] = v[i];
                mp2[v[i]] = s[i];
            }
            else if(mp2[v[i]] != s[i]) {
                no;
                f = 0;
                break;
            }
        }
        if(f) yes;
    }
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
