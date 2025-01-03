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
    string s;
    ll n;
    cin >> s >> n;

    map<char, int> mp;
    for(auto &it: s) mp[it]++;
    ll sum = 0, cnt = -1; char ch = '$';
    for(auto& [a,b]: mp) {
        if(b * (a-'a'+1) + sum <= n) sum += b * (a-'a'+1);
        else {
            cnt = (n-sum) / (a-'a'+1);
            sum += cnt * (a-'a'+1);
            ch = a;
            break;
        }
    }
    if(ch == '$') { 
        cout << s << endl;
        return;
    }
    for(auto& it: s) {
        if(it == ch && cnt) {cout << it; cnt--;}
        else if(it < ch) cout << it;
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
