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

    vector<ll> v;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a' || s[i] == 'e') v.push_back(i);
    }
    int k = 0;
    for(int i = 0; i < v.size()-1; i++) {
        if(v[i+1]-v[i] == 2) {
            cout << s[k++] << s[k++] << '.';
        }
        else {
            cout << s[k++] << s[k++] << s[k++] << '.';
        }
    }
    for(int i = k; i < n; i++) {
        cout << s[i];
    }
    newline;
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
