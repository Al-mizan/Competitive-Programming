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
    vector<string> s;
    int ind = -1;
    for(int i = 0; i < 3; i++) {
        string str;
        cin >> str;
        s.push_back(str);
        if(str[0] == '?' || str[1] == '?' || str[2] == '?') {
            ind = i;
        }
    }
    bool a = 0, b = 0, c = 0;
    for(int i=0; i<3; i++) {
        if(s[ind][i] == 'A') {
            a = 1;
        } 
        else if(s[ind][i] == 'B') {
            b = 1;
        } 
        else if(s[ind][i] == 'C') {
            c = 1;
        }
    }
    if(a == 0) cout << "A";
    else if(b == 0) cout << "B";
    else cout << "C";
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
