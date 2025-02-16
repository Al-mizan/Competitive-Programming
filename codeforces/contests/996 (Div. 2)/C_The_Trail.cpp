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
    string s;
    cin >> s;
    vector<vector<ll>> v(n, vector<ll>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> v[i][j];

    
    vector<ll> row(n+1), col(m+1);
    for(int i=0; i<n; i++) {
        ll sum = 0;
        for(int j=0; j<m;j++) {
            sum += v[i][j];
        }
        row[i] = sum;
    }
    for(int i=0; i<m; i++) {
        ll sum = 0;
        for(int j=0; j<n;j++) {
            sum += v[j][i];
        }
        col[i] = sum;
    }

    ll r = 0, c = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'D') {
            v[r][c] = -row[r];
            col[c] -= row[r];
            r++;
        }
        else if(s[i] == 'R') {
            v[r][c] = -col[c];
            row[r] -= col[c];
            c++;
        }
    }
    if(s[s.size()-1] == 'R') v[r][c] = -col[c];
    else v[r][c] = -row[r];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cout << v[i][j] << ' ';
        newline;
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
        solve();
    }
    return 0;
}
