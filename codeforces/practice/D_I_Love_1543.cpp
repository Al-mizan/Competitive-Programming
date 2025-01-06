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
    ll n, m;
    cin >> n >> m;
    ll v[n][m];
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<m; j++) 
            v[i][j] = s[j]-'0';
    }
    
    vector<ll> c = {1,5,4,3};
    ll ans = 0;
    for(int i=0; i<min(n,m)/2; i++) {
        // debug(i);
        vector<ll> t;
        for(int j=i; j<m-i-1; j++) t.push_back(v[i][j]);
        for(int j=i; j<n-i-1; j++) t.push_back(v[j][m-1-i]);
        for(int j=m-i-1; j>i; j--) t.push_back(v[n-1-i][j]);
        for(int j=n-i-1; j>i; j--) t.push_back(v[j][i]);
        
        ll k = 0;
        for(int p=0; p<t.size(); p++) {
            if(t[p] == c[k]) {
                k++;
                if(k == 4) ans++, k = 0;
            }
            else {
                k = 0;
                if(t[p] == c[k]) k++; 
            }
        }
        if(k) {
            for(int j=0; j<3; j++) {
                if(t[j] == c[k]) {
                    k++;
                    if(k == 4) ans++, k = 0;
                }
                else k = 0;
            }
        }
    }
    cout << ans << endl;
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
