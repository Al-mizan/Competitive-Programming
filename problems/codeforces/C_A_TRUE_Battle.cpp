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
    string s;
    cin >> s;

    if(s[0] == '1' || s[n-1] == '1') {
        yes;
        return;
    }
    bool f = 1;
    int i;
    for(i=0; i<n-2; i+=2) {
        if(s[i] == '0' && s[i+1] == '1') continue;
        else if(s[i] == '0') i--;
        else {
            f = 0;
            break;
        }
    }
    if(i==n-1 && f) no;
    else if(f && s[n-2] == '0') no;
    else yes;
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
