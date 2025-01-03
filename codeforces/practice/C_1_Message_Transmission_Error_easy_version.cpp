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
#define Fill(v,x)       fill(v.begin(),v.end(),x)
#define cases(tc)       cout << "Case #" << tc << ": "
#define debug(args...)  cout << #args << " = " << args << endl;
#define getunique(v){sort(v.begin(), v.end());v.erase(unique(v.begin(), v.end()), v.end());}
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void solve() {
    string s;
    cin >> s;
    string ans = "";
    int n = s.size();
    bool f = false;
    int j = 1, k = 0;
    for(int i = 0; i < (n+1)/2; ) {
        int x = 0;
        ans = "";
        if(i-k > 1) { 
            int ind = i-1, cnt = 1;
            while(ind-- && s[ind] != s[0] && s[ind+1] != s[1]) {
                ans += s[ind];
                cnt++;
            }
            reverse(all(ans));
            x = cnt;
        }
        k = i;
        for(j = i+1; j < n; j++) {
            if(s[x] == s[j]) {
                ans += s[j]; 
                if(x >= i+1 && j == n-1) f = 1;
                x++;
            }
            else break;
            if(f) {
                yes;
                cout << ans << endl;
                return;
            }
        }
        i = j;
    }
    no;
}

int32_t main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
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
