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
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i=0;i<n;i++) 
        cin >> s[i];
    
    ll sum = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(s[i][j] == 'W') {
                if(i+1<n && s[i+1][j] == 'P') sum++;
                else if(i-1>=0 && s[i-1][j] == 'P') sum++;
                else if(j+1<m && s[i][j+1] == 'P') sum++;
                else if(j-1>=0 && s[i][j-1] == 'P') sum++;
            }
        }
    }
    cout << sum << endl;
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        // cases(tc);
        solve();
    }
    return 0;
}
