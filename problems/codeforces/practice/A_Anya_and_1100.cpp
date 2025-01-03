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
    string s;
    cin >> s;
    ll n = s.size();
    ll cnt = 0;
    for(int i=0;i<n-3; i++) {
        if(s[i] == '1' && s[i+1] == '1' 
        && s[i+2] == '0' && s[i+3] == '0') {
            cnt++;
        }

    }
    ll q;
    cin >> q;
    while(q--) {
        ll ind, val;
        cin >> ind >> val;
        bool f = false, g = false;
        for(int i=0;i<4; i++) {
            if (ind - 1 - i < n && ind - 1 - i + 1 < n && ind - 1 - i + 2 < n && ind - 1 - i + 3 < n)
                if(s[ind - 1 - i] == '1' && s[ind - 1 - i + 1] == '1' && s[ind - 1 - i + 2] == '0' && s[ind - 1 - i + 3] == '0') {
                    f = 1;
                    break;
                }
        }
        s[ind - 1] = (val ? '1' : '0');
        for(int i=0;i<4; i++) {
            if (ind - 1 - i < n && ind - 1 - i + 1 < n && ind - 1 - i + 2 < n && ind - 1 - i + 3 < n)
                if(s[ind - 1 - i] == '1' && s[ind - 1 - i + 1] == '1' && s[ind - 1 - i + 2] == '0' && s[ind - 1 - i + 3] == '0') {
                    g = 1;
                    break;
                }
        }
        if(f && !g) cnt--;
        else if(!f && g) cnt++;
        if(cnt) yes;
        else no;
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
