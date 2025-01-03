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
    vector<string> v = {"0","1"};

    for(int i=2; i<=n; i++) {
        int j = pow(2,(i-1)) - 1;
        while(j>=0) {
            string s = "1";
            for(int k=0; k<i-v[j].size()-1; k++) {
                s += "0";
            }
            s += v[j];
            v.push_back(s);
            j--;
        }
        newline;
    }
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<n-(int)v[i].size(); j++)
            cout << '0';
        cout << v[i] << endl;
    }
}

int32_t main()
{
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
